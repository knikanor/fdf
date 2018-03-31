/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:06:26 by knikanor          #+#    #+#             */
/*   Updated: 2017/11/08 14:44:05 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *big, char const *lit, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (lit[0] == '\0')
		return ((char *)&big[i]);
	while (big[i] != '\0' && i < len)
	{
		while (lit[j] == big[i + j] && (i + j) < len)
		{
			j++;
			if (lit[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
