/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 23:31:07 by knikanor          #+#    #+#             */
/*   Updated: 2017/11/08 14:33:28 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*map;
	size_t	len;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	if (!s || !f)
		return (NULL);
	if ((map = (char *)malloc(sizeof(char) \
							* (len + 1))) == NULL)
		return (NULL);
	while (*s)
	{
		map[i] = f(i, *s);
		i++;
		s++;
	}
	map[i] = '\0';
	return (map);
}
