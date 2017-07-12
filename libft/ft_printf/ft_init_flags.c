/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:03:59 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/22 18:41:09 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const t_tabflag		g_tflag[] =
{
	{'+', &ft_init_plus},
	{'-', &ft_init_moins},
	{'0', &ft_init_zero},
	{'#', &ft_init_sharp},
	{' ', &ft_init_sp},
	{'h', &ft_init_h},
	{'l', &ft_init_l},
	{'j', &ft_init_j},
	{'z', &ft_init_z},
	{'\0', NULL}
};

const t_tabconv	g_tconv[] =
{
	{'%', &ft_prct},
	{'c', &ft_c},
	{'C', &ft_cu},
	{'D', &ft_du},
	{'d', &ft_d},
	{'u', &ft_u},
	{'U', &ft_uu},
	{'i', &ft_d},
	{'s', &ft_s},
	{'S', &ft_su},
	{'o', &ft_o},
	{'O', &ft_ou},
	{'x', &ft_x},
	{'X', &ft_xu},
	{'b', &ft_b},
	{'p', &ft_p},
	{'\0', NULL}
};

void	ft_init_digit(char **str, t_ans *ans)
{
	ans->digit = ft_atoi(*str);
	while (ft_isdigit(**str))
		*str += 1;
}

void	ft_exec_init(char **str, t_ans *ans)
{
	int	i;

	i = 0;
	while (g_tflag[i].c != **str && g_tflag[i].c != '\0')
		i++;
	if (g_tflag[i].c != '\0')
		g_tflag[i].f(ans);
}

void	ft_proceed_conv(char c, t_ans *ans, va_list arg)
{
	int	i;

	i = 0;
	while (g_tconv[i].conv != c && g_tconv[i].conv != '\0')
		i++;
	if (g_tconv[i].conv != '\0')
		g_tconv[i].f(ans, arg);
}

void	ft_init_plus(t_ans *ans)
{
	ans->plus = TRUE;
}

void	ft_init_moins(t_ans *ans)
{
	ans->moins = TRUE;
}
