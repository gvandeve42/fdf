/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:09:47 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/11 14:33:25 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int		ft_search_n(char *bg, char *ltl, size_t len)
{
	while (*bg == *ltl && len > 0 && *bg != '\0')
	{
		bg++;
		ltl++;
		len--;
	}
	if (*ltl == '\0')
		return (1);
	else
		return (0);
}

char			*ft_strnstr(const char *big, const char *ltl, size_t len)
{
	char	*little;
	char	*bg;

	little = (char*)ltl;
	bg = (char*)big;
	if (*ltl == '\0')
		return (bg);
	while (*bg != '\0' && len > 0)
	{
		if (*bg == *little)
			if (ft_search_n(bg, little, len) == 1)
				return (bg);
		bg++;
		len--;
	}
	return (NULL);
}
