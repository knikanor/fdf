/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 17:34:01 by knikanor          #+#    #+#             */
/*   Updated: 2017/11/08 17:09:03 by knikanor         ###   ########.fr       */
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

static int			count_splits(const char *str, char c)
{
	int		i;

	i = 0;
	while (*str != '\0')
	{
		str = find_next(str, c, 1);
		if (*str != '\0')
		{
			i++;
			str = find_next(str, c, 0);
		}
	}
	return (i);
}

static char			**table(char **str2, int len)
{
	int		i;

	i = 0;
	while (i < len)
		free(str2[i]);
	free(str2);
	return (NULL);
}

char				**ft_strsplit(char const *str, char c)
{
	int			i;
	char		**str2;
	const char	*next;

	if (str == NULL)
		return (NULL);
	str2 = (char **)malloc(sizeof(char *) * (count_splits(str, c) + 1));
	if (str2 == NULL)
		return (NULL);
	i = 0;
	while (*str != '\0')
	{
		str = find_next(str, c, 1);
		if (*str != '\0')
		{
			next = find_next(str, c, 0);
			str2[i] = ft_strsub(str, 0, next - str);
			if (str2[i] == NULL)
				return (table(str2, i));
			i++;
			str = next;
		}
	}
	str2[i] = 0;
	return (str2);
}
