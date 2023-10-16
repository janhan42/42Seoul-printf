/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:31:13 by janhan            #+#    #+#             */
/*   Updated: 2023/10/16 15:34:32 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_u(unsigned int num, int *out_count)
{
	char	c;

	if (num <= 0)
		return ;
	ft_putnbr_u(num / 10, out_count);
	c = num % 10 + '0';
	*out_count += write(1, &c, 1);
}

void	ft_print_u(va_list *out_ap, int *out_count)
{
	unsigned int	num;

	num = va_arg(*out_ap, unsigned int);
	if (num == 0)
	{
		*out_count += write(1, "0", 1);
		return ;
	}
	ft_putnbr_u(num, out_count);
}
