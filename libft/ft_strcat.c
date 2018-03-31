/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:04:14 by knikanor          #+#    #+#             */
/*   Updated: 2017/10/29 20:12:18 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *app)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (app[j] != '\0')
	{
		dest[i + j] = app[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
