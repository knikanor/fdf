/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 19:41:05 by knikanor          #+#    #+#             */
/*   Updated: 2017/11/08 15:41:50 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str)
{
	char	*s;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	i = -1;
	j = 0;
	while (str[len - 1] == ' ' || str[len - 1] == '\t' || str[len - 1] == '\n')
		len--;
	while ((str[++i] == ' ' || str[i] == '\t' || str[i] == '\n') && len > 0)
		len--;
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	while (j < len)
	{
		s[j++] = str[i++];
	}
	s[j] = '\0';
	return (s);
}
