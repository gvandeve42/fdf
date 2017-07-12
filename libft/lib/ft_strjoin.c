/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:46:28 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/07 19:52:47 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	unsigned int	length;
	char			*new;
	char			*anchor;

	length = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	if ((new = (char*)malloc((length + 1) * sizeof(char))) == NULL)
		return (NULL);
	anchor = new;
	while (*s1 != '\0')
		*new++ = *s1++;
	while (*s2 != '\0')
		*new++ = *s2++;
	*new = '\0';
	return (anchor);
}
