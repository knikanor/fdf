/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:58:31 by knikanor          #+#    #+#             */
/*   Updated: 2018/03/30 23:03:59 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		zaloop_hook(t_fdf *fdf)
{
	rendering(fdf);
	key_hook(fdf);
	return (0);
}

void	usage(int error_code)
{
	if (error_code == -1)
	{
		ft_putendl_fd("Error: breaking while creating map T_T", 2);
		exit(0);
	}
	if (error_code == -2)
	{
		ft_putendl_fd("Error: cannot open file >_<", 2);
		exit(0);
	}
	if (error_code == -3)
	{
		ft_putendl_fd("Usage: ./fdf test_maps/<map_name> <z_scale>", 2);
		exit(0);
	}
	if (error_code == -4)
	{
		ft_putendl_fd("No data found", 2);
		exit(0);
	}
	if (error_code == -5)
	{
		ft_putendl_fd("Found wrong line length", 2);
		exit(0);
	}
}

void	main_additional(t_fdf *fdf, int ac, char *height)
{
	if (ac == 3)
	{
		fdf->scalez = ft_atoi(height);
		if (fdf->scalez <= 0 || fdf->scalez > 100)
			fdf->scalez = 1;
	}
	init(fdf);
	if ((fdf->fd = open(fdf->filename, O_RDONLY)) == -1)
		usage(-2);
	if (create_map(fdf) == -1)
		usage(-1);
}

int		main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac == 2 || ac == 3)
	{
		fdf.filename = av[1];
		fdf.scalez = 1;
		main_additional(&fdf, ac, av[2]);
		rendering(&fdf);
		fdf.cntr_x = fdf.plane.nodes / 2;
		fdf.cntr_y = fdf.plane.lines / 2;
	}
	else
		usage(-3);
	mlx_hook(fdf.win, 2, 1, key_press, &fdf);
	mlx_hook(fdf.win, 3, 2, key_release, &fdf);
	mlx_loop_hook(fdf.mlx, zaloop_hook, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
