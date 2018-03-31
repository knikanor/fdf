/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:14:14 by knikanor          #+#    #+#             */
/*   Updated: 2018/03/30 23:07:46 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			count_line(char **map)
{
	int		count;

	count = 0;
	while (map[count] != NULL)
		count++;
	return (count);
}

int			create_map_2(t_fdf *fdf, int count, char *line)
{
	char	**tab;
	int		i;
	char	*p;

	i = -1;
	tab = ft_strsplit(line, ' ');
	if (count_line(tab) < fdf->plane.nodes)
		usage(-5);
	fdf->plane.map[count] = (t_point *)malloc(sizeof(t_point) *
							fdf->plane.nodes + 1);
	while (tab[++i])
	{
		fdf->plane.map[count][i].x = i + 1;
		fdf->plane.map[count][i].y = count + 1;
		fdf->plane.map[count][i].z = (ft_atoi(tab[i])) * fdf->scalez;
		if (((p = ft_strchr(tab[i], ','))) != 0)
			fdf->plane.map[count][i].c = ft_atoi_base(p + 3, 16);
		else
			fdf->plane.map[count][i].c = 0x00FFFF;
	}
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (0);
}

int			create_additional(t_fdf *fdf, char *line, int count)
{
	close(fdf->fd);
	if ((fdf->fd = open(fdf->filename, O_RDONLY)) == -1)
		usage(-2);
	fdf->plane.map = (t_point **)malloc(sizeof(t_point *) *
						fdf->plane.lines + 1);
	fdf->plane.map[fdf->plane.lines] = NULL;
	while (get_next_line(fdf->fd, &line))
	{
		create_map_2(fdf, count++, line);
		free(line);
	}
	fdf->plane.map[count] = NULL;
	return (-1);
}

int			create_map(t_fdf *fdf)
{
	char	*line;
	char	**map;
	int		count;
	int		gres;

	count = 0;
	while ((get_next_line(fdf->fd, &line)))
	{
		if (line[0] == '\0')
			usage(-4);
		gres = 1;
		if ((fdf->plane.lines == 0) && (map = ft_strsplit(line, ' ')))
			fdf->plane.nodes = count_line(map);
		fdf->plane.lines++;
		free(line);
	}
	if (gres != 1)
		usage(-4);
	count = create_additional(fdf, line, count);
	while (map[++count])
		free(map[count]);
	free(map);
	return (0);
}
