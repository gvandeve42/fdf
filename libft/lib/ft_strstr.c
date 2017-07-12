/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 20:49:10 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/08 11:20:02 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int		ft_search(char *bg, char *ltl)
{
	while (*bg == *ltl && *bg != '\0')
	{
		bg++;
		ltl++;
	}
	if (*ltl == '\0')
		return (1);
	else
		return (0);
}

char			*ft_strstr(const char *big, const char *little)
{
	char	*ltl;
	char	*bg;

	ltl = (char*)little;
	bg = (char*)big;
	if (*little == '\0')
		return (bg);
	while (*bg != '\0')
	{
		if (*bg == *ltl)
			if (ft_search(bg, ltl))
				return (bg);
		bg++;
	}
	return (NULL);
}
