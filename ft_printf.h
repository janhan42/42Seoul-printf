/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:36:20 by janhan            #+#    #+#             */
/*   Updated: 2023/10/16 16:48:11 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

/* --------------------------main func-------------------------- */

int		ft_printf(const char *format, ...);

/*	-------------------------char func-------------------------- */

void	ft_print_char(va_list *out_ap, int *out_count);
void	ft_print_str(va_list *out_ap, int *out_count);

/*	-------------------------digit func-------------------------- */

void	ft_print_di(va_list *out_ap, int *out_count);
void	ft_print_hex(va_list *out_ap, int *out_count, const char type);
void	ft_print_address(va_list *out_ap, int *out_count);
void	ft_print_u(va_list *out_ap, int *out_count);

#endif
