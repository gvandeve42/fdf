/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:04:39 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/05 16:27:10 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*b_b;

	b_b = (char*)b;
	while (len > 0)
	{
		*b_b = (unsigned char)c;
		b_b++;
		len--;
	}
	return (b);
}
