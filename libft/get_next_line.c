/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 13:26:36 by ravard            #+#    #+#             */
/*   Updated: 2016/06/01 19:09:42 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_lst			*search_fd_statyk(int fd, t_lst *list)
{
	t_lst	*tmp;
	t_lst	*new;

	tmp = NULL;
	if (list)
	{
		while (list->prev)
			list = list->prev;
		while (list)
		{
			if (list->fd == fd)
				return (list);
			tmp = list;
			list = list->next;
		}
	}
	new = (t_lst *)malloc(sizeof(t_lst));
	new->fd = fd;
	new->s = NULL;
	new->prev = tmp;
	new->next = NULL;
	if (tmp)
		tmp->next = new;
	return (new);
}

static int				ft_read(t_lst *list)
{
	int	ret;
	int	i;

	ret = read(list->fd, list->s, BUFF_SIZE);
	if (ret == -1)
		return (-1);
	else if (ret == 0)
		return (0);
	i = ret - 1;
	while (++i < BUFF_SIZE)
		list->s[i] = '\0';
	return (ret);
}

static int				looking_for_line(t_lst *list)
{
	int	i;

	i = -1;
	while (list->s[++i])
		if (list->s[i] == '\n')
			return (i);
	return (-1);
}

static int				fill_line(t_lst *list, char **line)
{
	int		n;
	char	*tmp;

	if ((n = looking_for_line(list)) == -1)
	{
		tmp = ft_strnew(ft_strlen(*line) + ft_strlen(list->s));
		ft_strcpy(tmp, *line);
		ft_strcat(tmp, list->s);
		free(*line);
		*line = ft_strdup(tmp);
		free(tmp);
		ft_strclr(list->s);
		return (0);
	}
	else
	{
		tmp = ft_strnew(ft_strlen(*line) + n);
		ft_strcpy(tmp, *line);
		ft_strncat(tmp, list->s, n);
		free(*line);
		*line = ft_strdup(tmp);
		free(tmp);
		ft_memmove(list->s, list->s + n + 1, ft_strlen(list->s) - n);
		return (1);
	}
}

int						get_next_line(int const fd, char **line)
{
	static t_lst		*list = NULL;
	int					ret;

	if (line == NULL || fd < 0 || fd == 1 ||
			fd == 2 || BUFF_SIZE <= 0)
		return (-1);
	*line = ft_strnew(0);
	list = search_fd_statyk(fd, list);
	if (list->s == NULL)
		list->s = ft_strnew(BUFF_SIZE);
	if (ft_strlen(list->s) == 0)
	{
		ret = ft_read(list);
		if (ret == -1)
			return (-1);
		else if (ret == 0)
			return (0);
	}
	while (fill_line(list, line) == 0 &&
			ft_read(list) != 0)
		;
	return (1);
}
