/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:34:19 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/22 18:26:07 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_xu(t_ans *ans, va_list arg)
{
	ans->upper = TRUE;
	ft_x(ans, arg);
}

void	ft_p(t_ans *ans, va_list arg)
{
	ans->sharp = TRUE;
	ans->h_flag = FALSE;
	ans->l_flag = TRUE;
	ans->sign = 'P';
	ft_x(ans, arg);
}

void	ft_c(t_ans *ans, va_list arg)
{
	wchar_t		c;

	if (ans->l_flag == 1)
		c = ft_wmask(va_arg(arg, int), ans);
	else
		c = va_arg(arg, int);
	if (c == 0)
		ft_digit_zero_c0(ans);
	else
		ft_digit_zero_prec_str_c(ans, (char*)&c);
}

void	ft_cu(t_ans *ans, va_list arg)
{
	ans->h_flag = 0;
	ans->l_flag = 1;
	ft_c(ans, arg);
}

void	ft_s(t_ans *ans, va_list arg)
{
	wchar_t			*str;
	wchar_t			wstr[2048];
	int				i;
	int				prec_tmp;

	i = 0;
	prec_tmp = ans->prec;
	str = va_arg(arg, wchar_t*);
	if (str == NULL)
		str = (ans->l_flag == 1) ? ft_null(str) : (wchar_t*)"(null)";
	if (ans->l_flag == 1)
	{
		while (str[i] != '\0')
		{
			wstr[i] = (wchar_t)ft_wmask(str[i], ans);
			i++;
		}
		wstr[i] = '\0';
		ans->prec = prec_tmp;
		ft_digit_zero_prec_wstr(ans, wstr);
	}
	else
		ft_digit_zero_prec_str(ans, (char*)str);
}
