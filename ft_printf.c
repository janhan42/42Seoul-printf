/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:25:48 by janhan            #+#    #+#             */
/*   Updated: 2023/10/13 23:55:40 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_info *info)
{
	info->minus = DISABLE;
	info->zero = DISABLE;
	info->dot_only = DISABLE;
	info->locass = DISABLE;
	info->address = DISABLE;
	info->precision = -1;
	info->num_base = 10;
	info->num_sign = 0;
}

int	ft_format_check(const char *format, va_list ap)
{
	t_info	info;
	int		count_printed;

	count_printed = 0;
	while (*format != '\0')
	{
		init_struct(&info);
		if (*format == '%')
		{
			format++;
			ft_parse_flag(&format, &info);
			ft_parse_width(&format, &info, ap);
			ft_parse_precision(&format, &info, ap);
			count_printed += ft_parse_type(&info, ap, *format);
		}
		else
			count_printed += write(1, format, 1);
		format++;
	}
	return (count_printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count_printed;

	va_start(ap, format);
	count_printed = ft_format_check(format, ap);
	va_end(ap);
	return (count_printed);

}
/*	format = cdspuxX%
	c = ft_putchar_fd
	d && i = ft_putnbr_fd
	s = ft_putstr_fd
	p = TODO: ft_print_p
	u = TODO: ft_print_u
	x && X = TODO: ft_print_hex
	% = TODO: ft_print_per*/

/*	숫자 관련	*/
/*	print_di
	print_u
	print_xx
	print_p
	*/
