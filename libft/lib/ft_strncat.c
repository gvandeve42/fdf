/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:34:20 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/04 16:52:13 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*start;

	start = s1;
	while (*s1 != '\0')
		s1++;
	while (*s2 != '\0' && n > 0)
	{
		*s1++ = *s2++;
		n--;
	}
	*s1++ = '\0';
	return (start);
}
