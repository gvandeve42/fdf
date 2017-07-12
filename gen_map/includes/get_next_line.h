/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:52:15 by gvandeve          #+#    #+#             */
/*   Updated: 2017/04/06 16:46:44 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 1000

typedef struct			s_fdls
{
	int					index;
	char				*str;
	struct s_fdls		*next;
}						t_fdls;

int						get_next_line(int fd, char **line);
void					get_free_lst(t_fdls *fd_list);

#endif
