/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:57:44 by knikanor          #+#    #+#             */
/*   Updated: 2018/03/21 21:02:00 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*elem;
	t_list		*head;
	t_list		*res;

	if (!lst || !f)
		return (NULL);
	elem = f(lst);
	if (!(res = ft_lstnew(elem->content, elem->content_size)))
		return (NULL);
	lst = lst->next;
	head = res;
	while (lst)
	{
		elem = f(lst);
		if (!(res->next = ft_lstnew(elem->content, elem->content_size)))
			return (NULL);
		res = res->next;
		lst = lst->next;
	}
	return (head);
}
