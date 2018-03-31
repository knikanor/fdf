/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:37:13 by knikanor          #+#    #+#             */
/*   Updated: 2017/11/03 20:48:23 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (str == NULL)
		return (NULL);
	if (start > (unsigned int)ft_strlen(str))
		return (NULL);
	if ((res = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < len && str[start] != '\0')
	{
		res[i] = str[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
