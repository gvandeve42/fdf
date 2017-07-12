/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:39:06 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/08 11:17:33 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char*)s1 != *(unsigned char*)s2)
			return (*(unsigned char*)s1 - *(unsigned char*)s2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}
