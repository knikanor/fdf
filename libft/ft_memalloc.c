/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 21:10:40 by knikanor          #+#    #+#             */
/*   Updated: 2017/11/08 14:45:24 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	if (!(str = (void*)malloc(sizeof(void*) * size)))
		return (NULL);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
