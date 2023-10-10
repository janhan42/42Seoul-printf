/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:25:48 by janhan            #+#    #+#             */
/*   Updated: 2023/10/10 15:52:50 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		out_index;

	out_index = 0;
	va_start(ap, str);
	for (int i = 0;  str[i]; i++)
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			out_index++;
		}
		else
		{
			i++;
			if (str[i] == 'c')
			{
				ft_putchar_fd(va_arg(ap, int), STDOUT_FILENO);
				out_index++;
			}
			else if (str[i] == 'd' || str[i] == 'i')
			{
				ft_putnbr_fd_alt(va_arg(ap, int), STDOUT_FILENO, &out_index);
			}
			else if (str[i] == 's')
			{
				char	*s = va_arg(ap, char *);
				ft_putstr_fd(s, STDOUT_FILENO);
				out_index = out_index + ft_strlen(s);
			}
			else if (str[i] == 'p')
				ft_printf_p(va_arg(ap, void *), &out_index);
			else if (str[i] == 'u')
				ft_printf_u(va_arg(ap, unsigned int), STDOUT_FILENO, &out_index);
			else if (str[i] == 'x')
				ft_printf_hexlow(va_arg(ap, int), STDOUT_FILENO, &out_index);
			else if (str[i] == 'X')
				ft_printf_hexup(va_arg(ap, unsigned int), STDOUT_FILENO, &out_index);
		}
	}
	va_end(ap);
	return (out_index);
}
