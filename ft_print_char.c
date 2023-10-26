/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:25:01 by janhan            #+#    #+#             */
/*   Updated: 2023/10/26 11:15:20 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(va_list *out_ap, int *out_count, int *flag)
{
	char	c;
	int		out;

	out = 0;
	c = (unsigned char)va_arg(*out_ap, int);
	out = write(1, &c, 1);
	if (out == -1)
		*flag = 1;
	else
		*out_count += out;
}
