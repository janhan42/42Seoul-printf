/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 23:47:13 by janhan            #+#    #+#             */
/*   Updated: 2023/10/13 23:50:11 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(t_info *info, va_list ap)
{
	int			len;
	int			count_printed;
	const char	*s;

	count_printed = 0;
	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (info->precision < len && info->precision > 0)
		len = info->precision;
	else if (info->precision == 0 || info->dot_only == ENABLE)
		len = 0;
	if (info->minus == DISABLE)
		while (len < (info->width)--)
			count_printed += write(1, " ", 1);
	count_printed += write(1, s, len);
	while (len < (info->width)--)
		count_printed += write(1, " ", 1);
	return (count_printed);
}
