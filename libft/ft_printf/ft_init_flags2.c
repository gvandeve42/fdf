/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:30:36 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/22 18:33:10 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_zero(t_ans *ans)
{
	ans->zero = TRUE;
}

void	ft_init_prec(t_ans *ans, char **frm)
{
	*frm += 1;
	ans->prec = ft_atoi(*frm);
	while (ft_isdigit(**frm))
		*frm += 1;
}

void	ft_init_sharp(t_ans *ans)
{
	ans->sharp = TRUE;
}

void	ft_init_sp(t_ans *ans)
{
	ans->sp_flag = TRUE;
}

void	ft_init_h(t_ans *ans)
{
	ans->h_flag += 1;
}
