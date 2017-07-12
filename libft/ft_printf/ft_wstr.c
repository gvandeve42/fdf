/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 19:59:50 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/22 18:51:42 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_sign_gestion_str(t_ans *ans, wchar_t *str, char c)
{
	if (ans->moins == TRUE)
	{
		(ans->prec == -1) ? ft_safe_wstr(ans, str) : (void)str;
		(ans->prec > 0) ? ft_safe_wstr_iter(ans, str, ans->prec) : (void)str;
		ft_safe_iter(ans, c, ans->digit);
	}
	else
	{
		ft_safe_iter(ans, c, ans->digit);
		(ans->prec == -1) ? ft_safe_wstr(ans, str) : (void)str;
		(ans->prec > 0) ? ft_safe_wstr_iter(ans, str, ans->prec) : (void)str;
	}
}

void		ft_digit_zero_prec_wstr(t_ans *ans, wchar_t *str)
{
	char	c;

	c = ' ';
	if (ans->moins == FALSE)
		if (ans->zero == TRUE)
			c = '0';
	if (ans->digit > 0)
	{
		if (ans->prec > -1)
			ans->digit -= (ft_wstrlen(str) > ans->prec) ?
				ans->prec : ft_wstrlen(str);
		else
			ans->digit -= ft_wstrlen(str);
		ft_sign_gestion_str(ans, str, c);
	}
	else
		ft_safe_wstr(ans, str);
}
