/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 19:34:28 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/04 20:38:40 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char*)s;
	while (*tmp != '\0')
	{
		if (*tmp == c)
			return (tmp);
		tmp++;
	}
	if (*tmp == c)
		return (tmp);
	return (NULL);
}
