/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ans.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 19:14:58 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/22 18:15:19 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ans	*ft_create_ans(void)
{
	t_ans *ans;

	if ((ans = ft_memalloc(sizeof(t_ans))) == NULL)
		exit(-1);
	ft_bzero((&(ans->buff)), BUFF_SIZE);
	ans->prec = -1;
	return (ans);
}

void	ft_clean(t_ans *ans)
{
	ans->zero = 0;
	ans->digit = 0;
	ans->plus = 0;
	ans->moins = 0;
	ans->sharp = 0;
	ans->j_flag = 0;
	ans->z_flag = 0;
	ans->sp_flag = 0;
	ans->h_flag = 0;
	ans->l_flag = 0;
	ans->digit = 0;
	ans->prec = -1;
	ans->upper = 0;
	ans->sign = 0;
}
