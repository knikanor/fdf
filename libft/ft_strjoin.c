/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 19:35:30 by knikanor          #+#    #+#             */
/*   Updated: 2017/11/07 16:09:05 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*s;
	int		len;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	len = ft_strlen(str1) + ft_strlen(str2);
	s = (char *)malloc(sizeof(*s) * (len + 1));
	if (s == NULL)
		return (NULL);
	ft_strcpy(s, str1);
	ft_strcat(s, str2);
	return (s);
}
