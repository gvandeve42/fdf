/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:35:23 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/07 13:58:56 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s_dst;
	char	*s_src;

	s_dst = (char*)dst;
	s_src = (char*)src;
	while (n > 0)
	{
		*s_dst++ = *s_src++;
		n--;
	}
	return (dst);
}
