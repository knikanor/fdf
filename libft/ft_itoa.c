/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 20:57:09 by knikanor          #+#    #+#             */
/*   Updated: 2017/11/08 18:20:39 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		m[2];
	char	*str;
	char	buff[11];

	m[0] = 0;
	m[1] = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		m[1] = -n;
	while (m[1] > 0)
	{
		buff[m[0]++] = (m[1] % 10) + '0';
		m[1] = m[1] / 10;
	}
	if (n < 0)
		buff[m[0]++] = '-';
	if (!(str = ft_strnew((size_t)m[0])))
		return (0);
	while (--m[0] >= 0)
		str[m[1]++] = buff[m[0]];
	str[m[1]] = '\0';
	return (str);
}
