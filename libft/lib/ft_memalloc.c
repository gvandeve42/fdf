/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:10:03 by gvandeve          #+#    #+#             */
/*   Updated: 2017/06/05 13:58:56 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;
	char	*res;

	if ((mem = (char*)malloc(size * sizeof(char))) == NULL)
		exit(3);
	res = mem;
	while (size > 0)
	{
		*mem = '\0';
		mem++;
		size--;
	}
	return ((void*)res);
}
