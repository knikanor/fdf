/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:10:46 by knikanor          #+#    #+#             */
/*   Updated: 2018/03/21 20:37:03 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_base(const char c)
{
	int		n;

	if (c >= '0' && c <= '9')
		n = c - '0';
	else if (c >= 'a' && c <= 'z')
		n = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		n = c - 'A' + 10;
	else
		n = -1;
	return (n);
}

int				ft_atoi_base(const char *str, int base)
{
	int		sign;
	int		n;
	int		tmp;

	n = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\f' || *str == '\r' || *str == '\v')
		str++;
	sign = (*str == '-' ? 1 : 0);
	if (*str == '-' || *str == '+')
		str++;
	tmp = check_base(*str);
	while (tmp >= 0 && tmp < base)
	{
		n = n * base + tmp;
		str++;
		tmp = check_base(*str);
	}
	return (sign ? -n : n);
}
