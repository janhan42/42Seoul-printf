/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:36:20 by janhan            #+#    #+#             */
/*   Updated: 2023/10/16 15:35:35 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

/* --------------------------메인 함수-------------------------- */

void	ft_print_format(const char format, va_list *out_ap, int *out_count);
void	ft_parse_type(const char *format, va_list *out_ap, int *out_count);
int		ft_printf(const char *format, ...);

/*	-------------------------문자 함수-------------------------- */

void	ft_print_char(va_list *out_ap, int *out_count);
void	ft_print_str(va_list *out_ap, int *out_count);
void	ft_print_per(int *out_count);

/*	-------------------------숫자 함수-------------------------- */

void	ft_print_di(va_list *out_ap, int *out_count);
void	ft_print_hex(va_list *out_ap, int *out_count, const char type);
void	ft_print_address(va_list *out_ap, int	*out_count);
void	ft_print_u(va_list *out_ap, int *out_count);

#endif
