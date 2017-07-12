/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:35:20 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/22 18:37:53 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_moins(t_ans *ans, char *str, char c)
{
	(ans->plus == TRUE) ? ft_safe_cpy(ans, ans->sign) : (void)str;
	(ans->prec > 0) ? ft_safe_iter(ans, '0', ans->prec) : (void)str;
	(*str != '0') ? ft_safe_str(ans, str) : (void)str;
	(*str == '0' && ans->prec == -1) ? ft_safe_str(ans, str) : (void)str;
	(*str == '0' && ans->sharp == FALSE && ans->prec == 0) ?
		ft_safe_cpy(ans, ' ') : (void)str;
	ft_safe_iter(ans, c, ans->digit);
}

static void		ft_plus(t_ans *ans, char *str, char c)
{
	if (ans->plus == TRUE && c == '0' && ans->digit > 0)
	{
		ft_safe_cpy(ans, ans->sign);
		ans->plus = FALSE;
	}
	ft_safe_iter(ans, c, ans->digit);
	(ans->plus == TRUE) ? ft_safe_cpy(ans, ans->sign) : (void)str;
	(ans->prec > 0) ? ft_safe_iter(ans, '0', ans->prec) : (void)str;
	(*str != '0') ? ft_safe_str(ans, str) : (void)str;
	(*str == '0' && ans->prec == -1) ?
		ft_safe_str(ans, str) : (void)str;
	(*str == '0' && ans->sharp == FALSE && ans->prec == 0) ?
		ft_safe_cpy(ans, ' ') : (void)str;
}

static void		ft_sign_gestion_dgt(t_ans *ans, char *str, char c)
{
	if (ans->sp_flag == TRUE && ans->plus == FALSE)
	{
		ft_safe_cpy(ans, ' ');
		ans->digit--;
	}
	if (ans->sharp == TRUE && ans->prec < 1)
	{
		ans->prec = 1;
		ans->digit = (ans->digit > 0 && *str != '0') ?
			ans->digit - 1 : ans->digit;
	}
	(ans->sp_flag == TRUE) ? ft_safe_cpy(ans, ' ') : (void)str;
	if (ans->moins == TRUE)
		ft_moins(ans, str, c);
	else
		ft_plus(ans, str, c);
}

static void		ft_nfgestion(t_ans *ans, char *str)
{
	(ans->sharp == TRUE) ? ft_safe_cpy(ans, '0') : (void)str;
	(ans->sp_flag == TRUE && ans->plus == FALSE) ?
		ft_safe_cpy(ans, ' ') : (void)str;
	(ans->plus == TRUE || ans->sign == '-') ?
		ft_safe_cpy(ans, ans->sign) : (void)str;
	(ans->prec > 0) ?
		ft_safe_iter(ans, '0', (ans->prec - ft_strlen(str))) : (void)str;
	if (*str == '0' && ans->sharp == FALSE)
		(ans->prec == -1) ? ft_safe_str(ans, str) : (void)str;
	else if (*str != '0')
		ft_safe_str(ans, str);
}

void			ft_digit_zero_prec_dgt_o(t_ans *ans, char *str)
{
	char	c;

	c = ' ';
	ans->plus = (ans->sign == '-') ? TRUE : ans->plus;
	if (ans->moins == FALSE)
		if (ans->zero == TRUE && ans->prec == -1)
			c = '0';
	if (ans->digit > 0)
	{
		if (ans->prec > -1)
		{
			ans->digit -= (ans->prec > (int)ft_strlen(str)) ?
				ans->prec : (int)ft_strlen(str);
			ans->prec -= (ans->prec == 0 || *str == '0') ? 0 : ft_strlen(str);
		}
		else
			ans->digit -= ft_strlen(str);
		(ans->plus == TRUE || ans->sign == '-') ? ans->digit-- : (void)str;
		ft_sign_gestion_dgt(ans, str, c);
	}
	else
		ft_nfgestion(ans, str);
}
