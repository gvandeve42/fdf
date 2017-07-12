/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:04:45 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/22 18:19:54 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prct(t_ans *ans, va_list arg)
{
	(void)arg;
	ft_digit_zero(ans, "%");
}

void	ft_d(t_ans *ans, va_list arg)
{
	intmax_t	nb;
	char		*str;

	if (ans->h_flag == 1)
		nb = (short)va_arg(arg, int);
	else if (ans->h_flag == 2)
		nb = (char)va_arg(arg, int);
	else if (ans->l_flag == 1)
		nb = va_arg(arg, long int);
	else if (ans->l_flag == 2)
		nb = va_arg(arg, long long int);
	else if (ans->j_flag == 1)
		nb = va_arg(arg, intmax_t);
	else if (ans->z_flag == 1)
		nb = va_arg(arg, size_t);
	else
		nb = va_arg(arg, int);
	ans->sign = (nb < 0) ? '-' : '+';
	ans->sp_flag = (ans->plus == TRUE) ? FALSE : ans->sp_flag;
	str = ft_itoa_base(nb, 10);
	str = (nb < 0) ? ft_rm_minus(str) : str;
	ft_digit_zero_prec_dgt_d(ans, str);
	free(str);
}

void	ft_du(t_ans *ans, va_list arg)
{
	ans->h_flag = 0;
	ans->l_flag = 1;
	ft_d(ans, arg);
}

void	ft_u(t_ans *ans, va_list arg)
{
	uintmax_t	nb;
	char		*str;

	if (ans->h_flag == 1)
		nb = (unsigned short)va_arg(arg, unsigned int);
	else if (ans->h_flag == 2)
		nb = (unsigned char)va_arg(arg, unsigned int);
	else if (ans->l_flag == 1)
		nb = va_arg(arg, unsigned long int);
	else if (ans->l_flag == 2)
		nb = va_arg(arg, unsigned long long int);
	else if (ans->j_flag == 1)
		nb = va_arg(arg, intmax_t);
	else if (ans->z_flag == 1)
		nb = va_arg(arg, size_t);
	else
		nb = va_arg(arg, unsigned int);
	str = ft_utoa_base(nb, 10);
	ans->sp_flag = FALSE;
	ans->plus = FALSE;
	ft_digit_zero_prec_dgt_d(ans, str);
	free(str);
}

void	ft_uu(t_ans *ans, va_list arg)
{
	ans->h_flag = 0;
	ans->l_flag = 1;
	ft_u(ans, arg);
}
