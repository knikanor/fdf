/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:29:21 by knikanor          #+#    #+#             */
/*   Updated: 2017/11/17 15:12:19 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, char *src, size_t dstsize)
{
	size_t		i;
	size_t		dlen;
	size_t		slen;

	i = 0;
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	i = dlen;
	while (*src && (i + 1 < dstsize))
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	if (dstsize < dlen)
		return (slen + dstsize);
	return (dlen + slen);
}
