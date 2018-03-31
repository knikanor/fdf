/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:57:44 by knikanor          #+#    #+#             */
/*   Updated: 2018/03/30 20:50:38 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		init(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF Katrin");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->plane.lines = 0;
	fdf->plane.nodes = 0;
	fdf->win_w = WIDTH;
	fdf->win_h = HEIGHT;
	fdf->alpha = 1.204277;
	fdf->beta = -0.226893;
	fdf->gamma = 0;
	fdf->key.a = 0;
	fdf->key.b = 0;
	fdf->key.g = 0;
	fdf->key.zoom_p = 0;
	fdf->key.zoom_m = 0;
	fdf->key.sh_x = 0;
	fdf->key.sh_y = 0;
	fdf->scalex = 0;
	fdf->scaley = 0;
	fdf->color = 65280;
	fdf->shift_x = 0;
	fdf->shift_y = 0;
	fdf->one_point_chaeker = 0;
}
