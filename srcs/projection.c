/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:47:23 by knikanor          #+#    #+#             */
/*   Updated: 2018/03/25 22:59:35 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			scale(t_fdf *fdf)
{
	int		square;
	double	scale;

	square = fdf->plane.lines * fdf->plane.nodes;
	scale = -0.00117 * square + 24.896;
	return (scale);
}

int			x_😡(int x, int y, int z, t_fdf *fdf)
{
	int x0;
	int y0;
	int z0;
	int res;

	x0 = x + (fdf->cntr_x / 2) - (fdf->win_w / 2);
	y0 = y + (fdf->cntr_y / 2) - (fdf->win_h / 2);
	z0 = -z;
	res = (x0 * cos(fdf->beta) + (-y0 * sin(fdf->alpha) + z0 * cos(fdf->alpha))
		* sin(fdf->beta)) * cos(fdf->gamma) + (y0 * cos(fdf->alpha)
		+ z0 * sin(fdf->alpha)) * sin(fdf->gamma) + ((fdf->cntr_x / 2) +
		(fdf->win_w / 2) + fdf->shift_x);
	return (res);
}

int			y_😡(int x, int y, int z, t_fdf *fdf)
{
	int x0;
	int y0;
	int z0;
	int res;

	x0 = x + (fdf->cntr_x / 2) - (fdf->win_w / 2);
	y0 = y + (fdf->cntr_y / 2) - (fdf->win_h / 2);
	z0 = -z;
	res = -(x0 * cos(fdf->beta) + (-y0 * sin(fdf->alpha) + z0 * cos(fdf->alpha))
		* sin(fdf->beta)) * sin(fdf->gamma) + (y0 * cos(fdf->alpha)
		+ z0 * sin(fdf->alpha)) * cos(fdf->gamma) + ((fdf->win_h / 2) +
		(fdf->cntr_y / 2) + fdf->shift_y);
	return (res);
}
