/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:49:45 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/07 18:12:39 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*new;
	char	*anchor;

	if ((new = ft_strdup((char*)s)) == NULL)
		return (NULL);
	anchor = new;
	while (*new != '\0')
	{
		*new = f(*new);
		new++;
	}
	return (anchor);
}
