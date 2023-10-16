/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:09:11 by janhan            #+#    #+#             */
/*   Updated: 2023/10/16 15:34:08 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putup_alt(va_list *out_ap, int *out_count, unsigned int num)
{
	char	*uphex;
	char	c;

	if (num <= 0)
		return ;
	uphex = "0123456789ABCDEF";
	ft_putup_alt(out_ap, out_count, num / 16);
	c = uphex[num % 16];
	*out_count += write(1, &c, 1);
}

static void	ft_putlow_alt(va_list *out_ap, int *out_count, unsigned int num)
{
	char	*lowhex;
	char	c;

	if (num <= 0)
		return ;
	lowhex = "0123456789abcdef";
	ft_putlow_alt(out_ap, out_count, num / 16);
	c = lowhex[num % 16];
	*out_count += write(1, &c, 1);
}

void	ft_print_hex(va_list *out_ap, int *out_count, const char type)
{
	unsigned int	num;

	num = va_arg(*out_ap, unsigned int);
	if (num == 0)
	{
		*out_count += write(1, "0", 1);
		return ;
	}
	if (type == 'x')
		ft_putlow_alt(out_ap, out_count, num);
	else if (type == 'X')
		ft_putup_alt(out_ap, out_count, num);
}
