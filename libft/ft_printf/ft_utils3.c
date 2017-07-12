/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:55:21 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/22 18:52:18 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_first_case(t_ans *ans, unsigned char *test)
{
	ft_safe_cpy(ans, *test);
	ft_safe_cpy(ans, *(test + 1));
	ft_safe_cpy(ans, *(test + 2));
	ft_safe_cpy(ans, *(test + 3));
}

void		ft_safe_wstr(t_ans *ans, wchar_t *str)
{
	unsigned char	*test;

	while (*str != '\0')
	{
		test = (unsigned char*)str;
		if ((*test & 0xf0) == 0xf0)
			ft_first_case(ans, test);
		else if ((*test & 0xe0) == 0xe0)
		{
			ft_safe_cpy(ans, *test);
			ft_safe_cpy(ans, *(test + 1));
			ft_safe_cpy(ans, *(test + 2));
		}
		else if ((*test & 0xc0) == 0xc0)
		{
			ft_safe_cpy(ans, *test);
			ft_safe_cpy(ans, *(test + 1));
		}
		if ((*test & 0x80) == 0)
			ft_safe_cpy(ans, *(test));
		str++;
	}
}

static void	ft_second_case(t_ans *ans, unsigned char *test, int *i)
{
	ft_safe_cpy(ans, *test);
	ft_safe_cpy(ans, *(test + 1));
	ft_safe_cpy(ans, *(test + 2));
	ft_safe_cpy(ans, *(test + 3));
	*i -= 4;
}

static void	ft_third_case(t_ans *ans, unsigned char *test, int *i)
{
	ft_safe_cpy(ans, *test);
	ft_safe_cpy(ans, *(test + 1));
	ft_safe_cpy(ans, *(test + 2));
	*i -= 3;
}

void		ft_safe_wstr_iter(t_ans *ans, wchar_t *str, int i)
{
	unsigned char	*test;

	while (i > 0 && *str != '\0')
	{
		test = (unsigned char*)str;
		if (((*test & 0xf0) == 0xf0) && i > 3)
			ft_second_case(ans, test, &i);
		else if (((*test & 0xe0) == 0xe0) && i > 2)
			ft_third_case(ans, test, &i);
		else if (((*test & 0xc0) == 0xc0) && i > 1)
		{
			ft_safe_cpy(ans, *test);
			ft_safe_cpy(ans, *(test + 1));
			i -= 2;
		}
		else if (((*test & 0x80) == 0) && i > 0)
		{
			ft_safe_cpy(ans, *(test));
			i--;
		}
		str++;
	}
}
