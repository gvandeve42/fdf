/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:15:10 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/08 11:20:25 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*new;
	char	*anchor;

	if (!s[start] || (ft_strlen((char*)s) - start) < len)
		return (NULL);
	else if ((new = (char*)malloc(((len + 1) * sizeof(char)))) == NULL)
		return (NULL);
	else
	{
		anchor = new;
		while (len > 0)
		{
			*new++ = s[start++];
			len--;
		}
		*new = '\0';
	}
	return (anchor);
}
