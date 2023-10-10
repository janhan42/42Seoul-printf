/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:57:57 by janhan            #+#    #+#             */
/*   Updated: 2023/10/10 16:42:23 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_check(const char *str)
{


}

int	ft_printf(const char *str, ...)
{
	va_list ap;
	int		out_count;

	out_count = 0;
	va_start(ap, str);
	while (str[i])
	{
		if(str[i] != '%')
			ft_putchar_fd(str[i], STDOUT_FILENO);
		else
		{
			i++;
			if (str[i] == 'c')
				ft_putchar_fd(va_arg(ap, int), STDOUT_FILENO);
			if (str[i] == 'd' || str[i] == 'i')
				ft_putnbr_fd(va_arg(ap, int), STDOUT_FILENO);
			if (str[i] == 's')
				ft_putstr_fd(va_arg(ap, char *), STDOUT_FILENO);
			if (str[i] == 'p')
				ft_print_p(va_arg(ap, void *), STDOUT_FILENO);
			if (str[i] == 'u')
				ft_print_u(va_arg(ap, unsigned int), STDOUT_FILENO);
			if (str[i] == 'x')
				ft_print_hex(va_arg(ap, int), STDOUT_FILENO, flag = 1);
			if (str[i] == 'X')
				ft_printf_hex(va_arg(ap, unsigned int), STDOUT_FILENO, flag = 2);
		}
		i++;
	}
	return (out_count);
}

int main(void)
{
	printf("%d", 123123);
}
