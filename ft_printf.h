/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:48:07 by janhan            #+#    #+#             */
/*   Updated: 2023/10/10 14:43:00 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_info
{
	int	length;
	int	sign;
}	t_info;

void	ft_printf_p(void *ptr, int *out_index);
void	ft_putnbr_fd_alt(int n, int fd, int *out_index);
int		ft_printf(const char *str, ...);
void	ft_printf_u(int n, int fd, int *out_index);
void	ft_printf_hexlow(int n, int fd, int *out_index);
void	ft_printf_hexup(unsigned int n, int fd, int *out_index);

#endif
