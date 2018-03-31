/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 23:21:39 by knikanor          #+#    #+#             */
/*   Updated: 2017/11/03 21:57:12 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*s2;

	i = 0;
	if (s != NULL && f != NULL)
	{
		s2 = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (s2 == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			s2[i] = f(s[i]);
			i++;
		}
		s2[i] = '\0';
		return (s2);
	}
	return (0);
}
