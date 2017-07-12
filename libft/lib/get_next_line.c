/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:01:11 by gvandeve          #+#    #+#             */
/*   Updated: 2017/04/06 16:44:40 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_work_on_strings(int i, char **line, char **st_line)
{
	char			*tmp;
	char			*tmp2;

	*line = (char*)ft_memalloc((i + 1) * sizeof(char));
	ft_memmove((void*)*line, (void*)(*st_line), ((i) * sizeof(char)));
	(*line)[i] = '\0';
	if ((*st_line)[i] == '\n')
	{
		tmp = &((*st_line)[i + 1]);
		tmp2 = ft_strdup(tmp);
	}
	else
	{
		tmp2 = (char*)malloc(sizeof(char));
		*tmp2 = '\0';
	}
	free(*st_line);
	*st_line = tmp2;
	return (1);
}

static int		ft_proceed_gnl(int fd, char **line,
								char **st_line, char *buff)
{
	char			*tmp;
	int				is_read;
	int				i;

	i = 0;
	if (**st_line != '\0')
	{
		while ((*st_line)[i] != '\0' && (*st_line)[i] != '\n')
			i++;
		if ((*st_line)[i] == '\n')
			return (ft_work_on_strings(i, line, st_line));
	}
	if ((is_read = read(fd, buff, BUFF_SIZE)) < 0)
		return (-1);
	else if (is_read != 0)
	{
		buff[is_read] = '\0';
		tmp = ft_strjoin(*st_line, buff);
		free(*st_line);
		*st_line = tmp;
		return (ft_proceed_gnl(fd, line, st_line, buff));
	}
	if (**st_line != '\0' && is_read == 0)
		return (ft_work_on_strings(i, line, st_line));
	return (0);
}

static t_fdls	*ft_create_elem(t_fdls *elem, int fd)
{
	if ((elem = (t_fdls*)ft_memalloc(sizeof(t_fdls))) == NULL)
		return (NULL);
	elem->index = fd;
	elem->str = (char*)ft_memalloc(sizeof(char));
	*(elem->str) = '\0';
	elem->next = NULL;
	return (elem);
}

static t_fdls	*ft_find_fd(t_fdls **lst, int fd)
{
	t_fdls			*tmp;

	tmp = (*lst);
	if (*lst == NULL)
	{
		*lst = ft_create_elem(*lst, fd);
	}
	else
	{
		while (tmp->next != NULL)
		{
			if (tmp->index == fd)
				return (tmp);
			tmp = tmp->next;
		}
		if (tmp->index == fd)
			return (tmp);
		tmp = ft_create_elem(tmp, fd);
		tmp->next = *lst;
		*lst = tmp;
	}
	return (*lst);
}

int				get_next_line(int fd, char **line)
{
	static t_fdls	*fd_list;
	int				rtn;
	t_fdls			*tmp;
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || fd == 1 || fd == 2)
		return (-1);
	tmp = ft_find_fd(&fd_list, fd);
	if ((rtn = ft_proceed_gnl(fd, line, &tmp->str, buff)) == 0)
		get_free_lst(fd_list);
	return (rtn);
}
