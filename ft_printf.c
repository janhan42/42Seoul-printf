/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:37:19 by janhan            #+#    #+#             */
/*   Updated: 2023/10/16 16:44:53 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_format(const char format, va_list *out_ap, int *out_count)
{
	if (format == 'c')
		ft_print_char(out_ap, out_count);
	else if (format == 's')
		ft_print_str(out_ap, out_count);
	else if (format == '%')
		*out_count += write(1, "%", 1);
	else if (format == 'd' || format == 'i')
		ft_print_di(out_ap, out_count);
	else if (format == 'x' || format == 'X')
		ft_print_hex(out_ap, out_count, format);
	else if (format == 'p')
		ft_print_address(out_ap, out_count);
	else if (format == 'u')
		ft_print_u(out_ap, out_count);
}

static void	ft_parse_type(const char *format, va_list *out_ap, int *out_count)
{
	size_t	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			++i;
			ft_print_format(format[i], out_ap, out_count);
		}
		else
			*out_count += write(1, &format[i], 1);
		++i;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	ft_parse_type(format, &ap, &count);
	va_end(ap);
	return (count);
}
