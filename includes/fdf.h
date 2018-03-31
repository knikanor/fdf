/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:29:54 by knikanor          #+#    #+#             */
/*   Updated: 2018/03/30 23:08:24 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include <math.h>
# include "../libft/libft.h"
# define WIDTH 1000
# define HEIGHT 1000
# define RAD 57

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				c;
}					t_point;

typedef struct		s_2d_point
{
	int				x;
	int				y;
	int				c;
}					t_2d_point;

typedef struct		s_proj
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				z0;
	int				z1;
}					t_proj;

typedef struct		s_plane
{
	t_point			**map;
	int				lines;
	int				nodes;
}					t_plane;

typedef struct		s_alg
{
	int				dx;
	int				dy;
	int				sign_x;
	int				sign_y;
	int				err;
	int				err2;
}					t_alg;

typedef	struct		s_key
{
	int				esc;
	int				iso;
	int				a;
	int				b;
	int				g;
	double			zoom_p;
	double			zoom_m;
	int				sh_x;
	int				sh_y;
	double			info_z;
}					t_key;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	char			*filename;
	void			*img;
	char			*line;
	int				fd;
	int				cntr_x;
	int				cntr_y;
	int				win_w;
	int				win_h;
	double			alpha;
	double			beta;
	double			gamma;
	int				color;
	int				shift_x;
	int				shift_y;
	double			scalex;
	double			scaley;
	int				scalez;
	int				one_point_chaeker;
	t_key			key;
	t_plane			plane;
	t_point			*point;
	t_alg			l;
}					t_fdf;

# define INIT_POINT(x, y) ((t_2d_point){(x),(y)})

void				init(t_fdf *fdf);
void				usage(int error_code);
int					create_map(t_fdf *fdf);
int					create_map_2(t_fdf *fdf, int count, char *line);
void				rendering(t_fdf *fdf);
int					x_😡(int x, int y, int z, t_fdf *fdf);
int					y_😡(int x, int y, int z, t_fdf *fdf);
int					scale(t_fdf *fdf);
t_fdf				*transform(t_fdf *fdf);
int					key_hook(t_fdf *fdf);
int					key_press(int keycode, t_fdf *fdf);
int					key_release(int keycode, t_fdf *fdf);
void				put_info(t_fdf *fdf);
int					zaloop_hook(t_fdf *fdf);

#endif
