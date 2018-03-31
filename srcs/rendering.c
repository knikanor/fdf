/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:57:00 by knikanor          #+#    #+#             */
/*   Updated: 2018/03/30 23:12:26 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			put_pixel_to_img(t_fdf *fdf, int x, int y, int color)
{
	int				bpp;
	int				sl;
	int				en;
	char			*img;
	unsigned int	tmp;

	img = mlx_get_data_addr(fdf->img, &bpp, &sl, &en);
	tmp = (mlx_get_color_value(fdf->mlx, color));
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
		ft_memcpy((void *)((img + y * WIDTH * (bpp / 8) + x * (bpp / 8))),
							(void *)&tmp, 4);
}

void			plotline_miami(t_fdf *fdf, t_2d_point p1, t_2d_point p2)
{
	fdf->l.sign_x = p1.x < p2.x ? 1 : -1;
	fdf->l.sign_y = p1.y < p2.y ? 1 : -1;
	fdf->l.dx = abs(p2.x - p1.x);
	fdf->l.dy = -abs(p2.y - p1.y);
	fdf->l.err = fdf->l.dx + fdf->l.dy;
	put_pixel_to_img(fdf, p2.x, p2.y, p2.c);
	while (p2.y != p1.y || p2.x != p1.x)
	{
		put_pixel_to_img(fdf, p1.x, p1.y, p1.c);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		if (p1.x >= WIDTH || p1.y >= HEIGHT)
			break ;
		fdf->l.err2 = 2 * fdf->l.err;
		if (fdf->l.err2 >= fdf->l.dy)
		{
			fdf->l.err = fdf->l.err + fdf->l.dy;
			p1.x = p1.x + fdf->l.sign_x;
		}
		if (fdf->l.err2 <= fdf->l.dx)
		{
			fdf->l.err = fdf->l.err + fdf->l.dx;
			p1.y = p1.y + fdf->l.sign_y;
		}
	}
}

t_2d_point		new_coord(t_point p, t_fdf *fdf)
{
	t_2d_point	res;

	p.x *= fdf->scalex;
	p.y *= fdf->scaley;
	res.x = x_😡(p.x, p.y, p.z, fdf);
	res.y = y_😡(p.x, p.y, p.z, fdf);
	res.c = p.c;
	return (res);
}

void			pre_rendering(t_2d_point *i, t_fdf *fdf)
{
	i->x = -1;
	if (fdf->scalex == 0 || fdf->scaley == 0)
	{
		fdf->scalex = fdf->win_w / (fdf->plane.nodes + 1);
		fdf->scaley = fdf->win_h / (fdf->plane.lines + 1);
	}
	if (fdf->plane.lines == 1 && fdf->plane.nodes == 1)
	{
		put_pixel_to_img(fdf, 500, 500, 0xffffff);
		fdf->one_point_chaeker = 1;
	}
	mlx_clear_window(fdf->mlx, fdf->win);
	mlx_destroy_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
}

void			rendering(t_fdf *fdf)
{
	t_2d_point	i;
	t_2d_point	p1;
	t_2d_point	p2;

	pre_rendering(&i, fdf);
	while (fdf->plane.map[++i.x] != NULL && fdf->one_point_chaeker != 1)
	{
		i.y = -1;
		while (++i.y <= fdf->plane.nodes - 1)
		{
			p1 = new_coord(fdf->plane.map[i.x][i.y], fdf);
			if (i.y != (fdf->plane.nodes - 1))
			{
				p2 = new_coord(fdf->plane.map[i.x][i.y + 1], fdf);
				plotline_miami(fdf, p1, p2);
			}
			if (i.x != (fdf->plane.lines - 1))
			{
				p2 = new_coord(fdf->plane.map[i.x + 1][i.y], fdf);
				plotline_miami(fdf, p1, p2);
			}
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	put_info(fdf);
}
