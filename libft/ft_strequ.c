/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:59:10 by knikanor          #+#    #+#             */
/*   Updated: 2017/11/03 21:56:05 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *str1, char const *str2)
{
	int i;

	i = 0;
	if (str1 && str2)
	{
		while (str1[i] != 0)
		{
			i++;
			if (str1[i] != str2[i])
				return (0);
		}
		return (1);
	}
	return (0);
}
