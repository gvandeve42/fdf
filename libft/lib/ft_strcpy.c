/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:42:12 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/04 15:57:07 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*start;

	start = dst;
	while (*src != '\0')
		*dst++ = *src++;
	*dst++ = '\0';
	return (start);
}
