/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:19:29 by knikanor          #+#    #+#             */
/*   Updated: 2017/11/16 21:09:30 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		spaces(char c)
{
	if (c == '\n' || c == '\t' || c == ' ' || c == '\r' \
		|| c == '\v' || c == '\f')
		return (1);
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	int				res;
	unsigned long	i;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	while (spaces(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		i = i * 10 + (*str - '0');
		str++;
		if ((sign == 1) && (i > 9223372036854775806))
			return (-1);
		if ((sign == -1) && (i > 9223372036854775807))
			return (0);
	}
	return (res * sign);
}
