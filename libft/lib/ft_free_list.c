/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 16:40:15 by gvandeve          #+#    #+#             */
/*   Updated: 2017/04/06 16:44:04 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		get_free_lst(t_fdls *fd_list)
{
	if (fd_list->next != NULL)
		free(fd_list->next);
	free(fd_list->str);
	free(fd_list);
	return ;
}
