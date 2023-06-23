/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:06:45 by mbruzzi           #+#    #+#             */
/*   Updated: 2022/09/30 11:17:03 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_begin;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst -> content));
	if (!new)
		return (NULL);
	new_begin = new;
	lst = lst -> next;
	while (lst)
	{	
		new -> next = ft_lstnew(f(lst -> content));
		if (!new -> next)
		{
			ft_lstclear(&new_begin, del);
			return (NULL);
		}
		new = new -> next;
		lst = lst -> next;
	}
	new -> next = NULL;
	return (new_begin);
}
