/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:58:30 by knikanor          #+#    #+#             */
/*   Updated: 2017/10/29 20:30:10 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned	char	s;
	unsigned	char	*str1;
	unsigned	char	*str2;

	s = (unsigned char)c;
	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	while (n)
	{
		*str1 = *str2;
		str1++;
		if (*str2 == s)
			return (str1);
		str2++;
		n--;
	}
	return (NULL);
}
