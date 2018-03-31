/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:45:48 by knikanor          #+#    #+#             */
/*   Updated: 2018/03/25 15:45:16 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		string_put(char *str, int a, int b, t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, a * 10, b * 15, fdf->color, str);
}

void			put_info(t_fdf *fdf)
{
	string_put(" WASD             - move", 1, 0, fdf);
	string_put(" + -              - scale", 1, 1, fdf);
	string_put(" strings          - rotate", 1, 2, fdf);
	string_put(" esc              - quit", 1, 3, fdf);
	fdf->color += 10000;
	if (fdf->color >= 16777215)
		fdf->color = 10;
}
