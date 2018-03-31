/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:56:44 by knikanor          #+#    #+#             */
/*   Updated: 2018/03/30 20:39:04 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*strjoin_free(char *str1, char *str2, int costil)
{
	char	*s;
	int		len;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	len = ft_strlen(str1) + ft_strlen(str2);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	ft_strcpy(s, str1);
	ft_strcat(s, str2);
	free(str1);
	if (costil == 1)
		free(str2);
	return (s);
}

int						cut(char **line, t_gnl *lst)
{
	char				*n;
	char				*cut;
	char				*costil;

	if (!lst->s)
		return (0);
	if ((n = ft_strchr(lst->s, ENDL)))
	{
		cut = ft_strsub(lst->s, 0, n - lst->s);
		*line = strjoin_free(*line, cut, 1);
		costil = lst->s;
		lst->s = ft_strdup(lst->s + (n - lst->s) + 1);
		free(costil);
		return (1);
	}
	else
	{
		*line = strjoin_free(*line, lst->s, 1);
		lst->s = NULL;
	}
	return (0);
}

static t_gnl			*find_fd(t_gnl **lst, int fd)
{
	t_gnl	**buf;

	buf = lst;
	while (*buf)
	{
		if ((*buf)->fd == fd)
			return (*buf);
		buf = &(*buf)->next;
	}
	if (*buf == NULL)
	{
		*buf = malloc(sizeof(**buf));
		(*buf)->next = NULL;
		(*buf)->s = NULL;
		(*buf)->fd = fd;
	}
	return (*buf);
}

int						reader(char **line, t_gnl *lst, int res, char *n)
{
	char				*buf;
	char				*cut;

	buf = (char *)(malloc(sizeof(char) * (BUFF_SIZE + 1)));
	while ((res = read(lst->fd, buf, BUFF_SIZE)))
	{
		if (res == -1)
			return (-1);
		buf[res] = '\0';
		if ((n = ft_strchr(buf, ENDL)))
		{
			cut = ft_strsub(buf, 0, n - buf);
			*line = strjoin_free(*line, cut, 1);
			lst->s = ft_strdup(buf + (n - buf) + 1);
			free(buf);
			return (1);
		}
		else
			*line = strjoin_free(*line, buf, 0);
	}
	if (res == 0)
		free(buf);
	if (**line == '\0' && res == 0)
		return (0);
	return (1);
}

int						get_next_line(const int fd, char **line)
{
	static	t_gnl		*lst;
	t_gnl				*buf;
	int					res;

	res = 0;
	if (fd < 0 || !line)
		return (-1);
	if (*line)
		*line = NULL;
	*line = ft_strdup("");
	buf = find_fd(&lst, fd);
	res = cut(line, buf);
	if (res == 1)
		return (1);
	res = reader(line, buf, 0, NULL);
	if (res == 0)
		free(*line);
	return (res);
}
