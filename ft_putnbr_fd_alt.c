/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_alt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:11:45 by janhan            #+#    #+#             */
/*   Updated: 2023/10/10 14:39:31 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnum_alt(unsigned int num, int fd, int *out_index)
{
	char	c;

	if (num <= 0)
		return ;
	ft_putnum_alt(num / 10, fd, out_index);
	c = num % 10 + '0';
	write(fd, &c, 1);
	*out_index += 1;
}
void	ft_putnbr_fd_alt(int n, int fd, int *out_index)
{
	unsigned int	num;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		*out_index += 1;
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
		*out_index += 1;
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
	ft_putnum_alt(num, fd, out_index);
}
