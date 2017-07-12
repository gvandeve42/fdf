/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:32:05 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/22 18:43:24 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_rm_minus(char *str)
{
	char	*rsp;

	rsp = ft_strdup(str + 1);
	free(str);
	return (rsp);
}

char	*ft_add_0x(char *str)
{
	char	*rsp;

	rsp = ft_strjoin("0x", str);
	return (rsp);
}

int		ft_wstrlen(wchar_t *str)
{
	unsigned char	*test;
	int				i;

	i = 0;
	while (*str != '\0')
	{
		test = (unsigned char*)str;
		if ((*test & 0xf0) == 0xf0)
			i += 4;
		else if ((*test & 0xe0) == 0xe0)
			i += 3;
		else if ((*test & 0xc0) == 0xc0)
			i += 2;
		else if ((*test & 0x80) == 0)
			i++;
		str++;
	}
	return (i);
}

wchar_t	*ft_null(wchar_t *str)
{
	char	*null;
	wchar_t	*anchor;

	str = (wchar_t*)ft_memalloc(7 * sizeof(wchar_t));
	anchor = str;
	null = "(null)";
	while (*null != '\0')
		*str++ = *null++;
	return (anchor);
}

void	ft_safe_str_iter(t_ans *ans, char *str, int i)
{
	while (i-- > 0 && *str != '\0')
		ft_safe_cpy(ans, *str++);
}
