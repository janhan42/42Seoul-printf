/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:53:27 by janhan            #+#    #+#             */
/*   Updated: 2023/10/16 13:02:01 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnum_recursive(unsigned int num, int *out_count)
{
	char	c;

	if (num <= 0)
		return ;
	ft_putnum_recursive(num / 10, out_count);
	c = num % 10 + '0';
	*out_count += write(1, &c, 1);
}

static void	ft_putnbr_alt(int n, int *out_count)
{
	unsigned int	num;

	if (n < 0)
		*out_count += write(1, "-", 1);
	else if (n == 0)
	{
		*out_count += write(1, "0", 1);
		return ;
	}
	if (n == -2147483648)
		num = 2147483648;
	else
	{
		if (n < 0)
			n *= -1;
		num = (unsigned int)n;
	}
	ft_putnum_recursive(num, out_count);
}

void	ft_print_di(va_list *out_ap, int *out_count)
{
	int	num;

	num = va_arg(*out_ap, int);
	ft_putnbr_alt(num, out_count);
}
