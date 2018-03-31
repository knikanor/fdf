/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:32:09 by knikanor          #+#    #+#             */
/*   Updated: 2017/11/16 17:38:53 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*len;

	len = (char *)str + ft_strlen(str);
	while (*len != c)
	{
		if (len == str)
			return (NULL);
		len--;
	}
	return (len);
}
