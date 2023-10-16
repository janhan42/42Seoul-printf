/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:06:45 by janhan            #+#    #+#             */
/*   Updated: 2023/10/16 15:15:50 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putaddress(int *out_count, size_t num)
{
	char	*lowhex;
	char	c;

	if (num <= 0)
		return ;
	lowhex = "0123456789abcdef";
	ft_putaddress(out_count, num / 16);
	c = lowhex[num % 16];
	*out_count += write(1, &c, 1);
}

void	ft_print_address(va_list *out_ap, int *out_count)
{
	size_t	address;

	address = (size_t)va_arg(*out_ap, void *);
	if (address == 0)
	{
		*out_count += write(1, "0x0", 3);
		return ;
	}
	else
	{
		*out_count += write(1, "0x", 2);
		ft_putaddress(out_count, address);
	}
}
