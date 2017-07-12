/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 13:29:01 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/22 18:33:23 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_l(t_ans *ans)
{
	ans->l_flag += 1;
}

void	ft_init_j(t_ans *ans)
{
	ans->j_flag = TRUE;
}

void	ft_init_z(t_ans *ans)
{
	ans->z_flag = TRUE;
}
