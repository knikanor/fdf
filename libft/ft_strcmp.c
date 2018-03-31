/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:39:52 by knikanor          #+#    #+#             */
/*   Updated: 2017/11/01 17:42:44 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const	char *str1, const char *str2)
{
	unsigned char	*s1;
	unsigned char	*s2;
	int				i;

	i = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while ((str1[i] != '\0') || (str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
