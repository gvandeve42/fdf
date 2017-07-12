/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:42:07 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/08 11:17:10 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char*)src == (unsigned char)c)
		{
			*(unsigned char*)dst++ = *(unsigned char*)src++;
			return (dst);
		}
		*(unsigned char*)dst++ = *(unsigned char*)src++;
		n--;
	}
	return (NULL);
}
