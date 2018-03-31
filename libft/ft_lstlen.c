/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:53:17 by knikanor          #+#    #+#             */
/*   Updated: 2017/11/16 21:16:18 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list **lst)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	if (lst != NULL)
	{
		tmp = *lst;
		while (tmp)
		{
			tmp = tmp->next;
			i++;
		}
		return (i);
	}
	else
		return (0);
}
