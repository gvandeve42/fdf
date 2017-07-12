/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:36:35 by ryaoi             #+#    #+#             */
/*   Updated: 2017/06/09 15:30:43 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_str2del(char ***tab)
{
	int			i;

	i = 0;
	if (*tab == NULL)
		return ;
	while ((*tab)[i])
	{
		if ((*tab)[i] != NULL)
			free((*tab)[i]);
		i++;
	}
	free(*tab);
}
