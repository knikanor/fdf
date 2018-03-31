/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 21:15:47 by knikanor          #+#    #+#             */
/*   Updated: 2017/10/29 20:27:47 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	s;

	i = 0;
	s = (unsigned char)c;
	str = (unsigned char *)arr;
	while (i < n)
	{
		if (str[i] == s)
			return (str + i);
		i++;
	}
	return (NULL);
}
