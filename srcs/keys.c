/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:57:44 by knikanor          #+#    #+#             */
/*   Updated: 2018/03/30 23:04:59 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook_additional(t_fdf *fdf)
{
	if (fdf->key.a == 1)
		fdf->alpha += (1.0 * (M_PI / 180.0));
	if (fdf->key.a == -1)
		fdf->alpha -= (1.0 * (M_PI / 180.0));
	if (fdf->key.b == 1)
		fdf->beta += (1.0 * (M_PI / 180.0));
	if (fdf->key.b == -1)
		fdf->beta -= (1.0 * (M_PI / 180.0));
	if (fdf->key.g == 1)
		fdf->gamma += (1.0 * (M_PI / 180.0));
	if (fdf->key.g == -1)
		fdf->gamma -= (1.0 * (M_PI / 180.0));
	return (0);
}

int		key_hook(t_fdf *fdf)
{
	key_hook_additional(fdf);
	if (fdf->key.zoom_p == 1)
	{
		fdf->scalex += fdf->scalex / 10;
		fdf->scaley += fdf->scaley / 10;
	}
	if (fdf->key.zoom_m == 1)
	{
		fdf->scalex -= fdf->scalex / 10;
		fdf->scaley -= fdf->scaley / 10;
	}
	if (fdf->key.sh_x == 1)
		fdf->shift_x += 10;
	if (fdf->key.sh_x == -1)
		fdf->shift_x -= 10;
	if (fdf->key.sh_y == 1)
		fdf->shift_y += 10;
	if (fdf->key.sh_y == -1)
		fdf->shift_y -= 10;
	return (0);
}

int		key_press_additional(int keycode, t_fdf *fdf)
{
	if (keycode == 126)
		fdf->key.a = 1;
	if (keycode == 125)
		fdf->key.a = -1;
	if (keycode == 124)
		fdf->key.b = 1;
	if (keycode == 123)
		fdf->key.b = -1;
	if (keycode == 116)
		fdf->key.g = 1;
	if (keycode == 121)
		fdf->key.g = -1;
	if (keycode == 69)
		fdf->key.zoom_p = 1;
	if (keycode == 78)
		fdf->key.zoom_m = 1;
	return (0);
}

int		key_press(int keycode, t_fdf *fdf)
{
	key_press_additional(keycode, fdf);
	if (keycode == 0)
		fdf->key.sh_x = -1;
	if (keycode == 13)
		fdf->key.sh_y = -1;
	if (keycode == 2)
		fdf->key.sh_x = 1;
	if (keycode == 1)
		fdf->key.sh_y = 1;
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(1);
	}
	return (1);
}

int		key_release(int keycode, t_fdf *fdf)
{
	if (keycode == 126 || keycode == 125)
		fdf->key.a = 0;
	if (keycode == 124 || keycode == 123)
		fdf->key.b = 0;
	if (keycode == 116 || keycode == 121)
		fdf->key.g = 0;
	if (keycode == 69)
		fdf->key.zoom_p = 0;
	if (keycode == 78)
		fdf->key.zoom_m = 0;
	if (keycode == 0)
		fdf->key.sh_x = 0;
	if (keycode == 13)
		fdf->key.sh_y = 0;
	if (keycode == 2)
		fdf->key.sh_x = 0;
	if (keycode == 1)
		fdf->key.sh_y = 0;
	return (1);
}
