/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:25:01 by janhan            #+#    #+#             */
/*   Updated: 2023/10/16 15:33:56 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(va_list *out_ap, int *out_count)
{
	char	c;

	c = (unsigned char)va_arg(*out_ap, int);
	*out_count += write(1, &c, 1);
}

void	ft_print_str(va_list *out_ap, int *out_count)
{
	char	*str;
	size_t	len;

	str = va_arg(*out_ap, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	*out_count += write(1, str, len);
}

void	ft_print_per(int *out_count)
{
	*out_count += write(1, "%", 1);
}
