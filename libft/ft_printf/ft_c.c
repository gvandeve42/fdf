/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 16:47:02 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/22 18:17:42 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_sign_gestion_str(t_ans *ans, char *str, char c)
{
	if (ans->moins == TRUE)
	{
		(ans->prec == -1) ? ft_safe_str(ans, str) : (void)str;
		(ans->prec > 0) ? ft_safe_str_iter(ans, str, ans->prec) : (void)str;
		ft_safe_iter(ans, c, ans->digit);
	}
	else
	{
		ft_safe_iter(ans, c, ans->digit);
		(ans->prec == -1) ? ft_safe_str(ans, str) : (void)str;
		(ans->prec > 0) ? ft_safe_str_iter(ans, str, ans->prec) : (void)str;
	}
}

void		ft_digit_zero_prec_str_c(t_ans *ans, char *str)
{
	char	c;

	c = ' ';
	if (ans->moins == FALSE)
		if (ans->zero == TRUE)
			c = '0';
	ans->prec = (ans->prec == 0) ? -1 : ans->prec;
	if (ans->digit > 0)
	{
		if (ans->prec > -1)
			ans->digit -= ((int)ft_strlen(str) > ans->prec) ?
				ans->prec : (int)ft_strlen(str);
		else
			ans->digit -= ft_strlen(str);
		ft_sign_gestion_str(ans, str, c);
	}
	else
		ft_safe_str(ans, str);
}
