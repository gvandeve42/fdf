/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 20:39:10 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/04 20:48:52 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	*result;

	tmp = (char*)s;
	result = NULL;
	while (*tmp != '\0')
	{
		if (*tmp == c)
			result = tmp;
		tmp++;
	}
	if (c == '\0' && *tmp == '\0')
		return (tmp);
	else
		return (result);
}
