/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_splits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:09:20 by knikanor          #+#    #+#             */
/*   Updated: 2017/11/08 20:04:15 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*find_next(char const *str, char c, int skip)
{
	if (skip)
		while (*str != '\0' && *str == c)
			str++;
	else
		while (*str != '\0' && *str != c)
			str++;
	return (str);
}

int					ft_count_splits(const char *str, char s)
{
	int		i;

	i = 0;
	while (*str != '\0')
	{
		str = find_next(str, s, 1);
		if (*str != '\0')
		{
			i++;
			str = find_next(str, s, 0);
		}
	}
	return (i);
}
