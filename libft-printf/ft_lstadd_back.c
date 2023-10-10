/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:54:06 by janhan            #+#    #+#             */
/*   Updated: 2023/10/08 17:32:35 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cursor;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		cursor = *lst;
		while (cursor->next != NULL)
			cursor = cursor->next;
		cursor->next = new;
	}
}
