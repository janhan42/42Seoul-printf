/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:25:01 by janhan            #+#    #+#             */
/*   Updated: 2023/10/16 16:39:35 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(va_list *out_ap, int *out_count)
{
	char	c;

	c = (unsigned char)va_arg(*out_ap, int);
	*out_count += write(1, &c, 1);
}
