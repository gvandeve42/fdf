/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:30:01 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/07 16:39:48 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	if ((new = (char*)malloc((size + 1) * sizeof(char))) == NULL)
		return (NULL);
	bzero(new, size + 1);
	return (new);
}
