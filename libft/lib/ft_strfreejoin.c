/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfreejoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 10:14:53 by gvandeve          #+#    #+#             */
/*   Updated: 2017/02/17 16:34:14 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strfreejoin(char *s1, char *s2, int opt)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (opt == 1)
		free(s1);
	if (opt == 2)
		free(s2);
	if (opt == 3)
	{
		free(s1);
		free(s2);
	}
	return (tmp);
}
