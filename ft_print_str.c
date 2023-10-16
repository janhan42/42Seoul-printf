/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:36:49 by janhan            #+#    #+#             */
/*   Updated: 2023/10/16 16:37:58 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(va_list *out_ap, int *out_count)
{
	char	*str;
	size_t	len;

	str = va_arg(*out_ap, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	*out_count += write(1, str, len);
}
