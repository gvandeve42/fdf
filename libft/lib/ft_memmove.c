/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:06:02 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/08 11:04:28 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s_dst;
	char	*s_src;

	s_dst = (char*)dst;
	s_src = (char*)src;
	if (s_src > s_dst)
		ft_memcpy(s_dst, s_src, len);
	else
	{
		while (len > 0)
		{
			s_dst[(len - 1)] = s_src[(len - 1)];
			len--;
		}
	}
	return (dst);
}
