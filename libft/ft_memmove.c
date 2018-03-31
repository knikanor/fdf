/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:09:16 by knikanor          #+#    #+#             */
/*   Updated: 2017/10/30 00:25:19 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;

	i = 0;
	if (dst < src)
	{
		i = 0;
		while (len-- > 0)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
		while (len-- > 0)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	return (dst);
}
