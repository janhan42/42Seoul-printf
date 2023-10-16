/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 23:25:03 by janhan            #+#    #+#             */
/*   Updated: 2023/10/13 23:57:46 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	_print_di(t_info *info, va_list ap)
{
	int			count_printed;
	long long	num;

	info->num_base = 10;
	num = va_arg(ap, int);
	if (num < 0)
	{
		info->num_sign = -1;
		num = -num;
		(info->width)--;
	}
	count_printed = print_num(info, num);
	return (count_printed);
}

int	_print_u(t_info *info, va_list ap)
{
	int			count_printed;
	long long	num;

	info->num_base = 10;
	num = va_arg(ap, unsigned int);
	count_printed = print_num(info, num);
	return (count_printed);
}

int	_print_xx(t_info *info, va_list ap, char format)
{
	int			count_printed;
	long long	num;

	if (format == 'x')
		info->locass = SMALL;
	info->num_base = 16;
	num = va_arg(ap, unsigned int);
	count_printed = print_num(info, num);
	return (count_printed);
}

int	_print_p(t_info *info, va_list ap)
{
	int			count_printed;
	long long	num;

	info->address = ENABLE;
	info->locass = SMALL;
	info->width -= 2;
	info->num_base = 16;
	num = (unsigned long)va_arg(ap, void *);
	count_printed = print_num(info, num);
	return (count_printed);
}
