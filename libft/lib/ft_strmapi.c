/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:13:13 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/07 19:02:57 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*new;
	char	*anchor;
	int		i;

	i = 0;
	if ((new = ft_strdup((char*)s)) == NULL)
		return (NULL);
	anchor = new;
	while (new[i])
	{
		new[i] = f(i, new[i]);
		i++;
	}
	return (anchor);
}
