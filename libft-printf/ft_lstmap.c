/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:05:10 by janhan            #+#    #+#             */
/*   Updated: 2023/10/10 09:27:33 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void*(*f)(void *), void(*del)(void *))
{
	t_list	*new;
	t_list	*temp_cpy;

	new = NULL;
	if (!lst)
		return (lst);
	while (lst)
	{
		temp_cpy = ft_lstnew(f(lst->content));
		if (!temp_cpy)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, temp_cpy);
		lst = lst->next;
	}
	return (new);
}
