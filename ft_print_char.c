/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 23:13:43 by janhan            #+#    #+#             */
/*   Updated: 2023/10/13 23:19:06 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(t_info *info, va_list ap)
{
	int		count_printed;
	char	c;

	count_printed = 0;
	if (info->minus == DISABLE)
	{
		while (--(info->width) > 0)
			count_printed += write(1, " ", 1);
	}
	c = (unsigned char)va_arg(ap, int);
	count_printed += write(1, &c, 1);
	while (--(info->width) > 0)
		count_printed += write(1, " ", 1);
	return (count_printed);
}

int	ft_print_percent(t_info *info)
{
	int	count_printed;

	count_printed = 0;
	if (info->minus == DISABLE && info->zero == DISABLE)
	{
		while (--(info->width) > 0)
			count_printed += write(1, " ", 1);
	}
	if (info->minus == DISABLE && info->zero == ENABLE)
	{
		while (--(info->width) > 0)
			count_printed += write(1, "0", 1);
	}
	count_printed += write(1, "%", 1);
	while (--(info->width) > 0)
		count_printed += write(1, " ", 1);
	return (count_printed);
}
