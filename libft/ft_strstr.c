/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:48:12 by knikanor          #+#    #+#             */
/*   Updated: 2017/11/07 16:54:07 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *small)
{
	char	*src;
	char	*sub;
	size_t	size;

	src = (char *)big;
	sub = (char *)small;
	size = ft_strlen(sub);
	if (size == 0)
		return (src);
	while (*src)
	{
		if (ft_strncmp(src, sub, size) == 0)
			return (src);
		src++;
	}
	return (NULL);
}
