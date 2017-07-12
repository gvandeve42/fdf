/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:33:19 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/22 18:25:24 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_o(t_ans *ans, va_list arg)
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
	str = ft_utoa_base(nb, 8);
	ans->sp_flag = FALSE;
	ans->plus = FALSE;
	ft_digit_zero_prec_dgt_o(ans, str);
	free(str);
}

void				ft_ou(t_ans *ans, va_list arg)
{
	ans->h_flag = 0;
	ans->l_flag = 1;
	ft_o(ans, arg);
}

static uintmax_t	ft_gstconv(t_ans *ans, va_list arg)
{
	uintmax_t	nb;

	if (ans->h_flag == 1)
		nb = (unsigned short)va_arg(arg, unsigned int);
	else if (ans->h_flag == 2)
		nb = (unsigned char)va_arg(arg, unsigned int);
	else if (ans->l_flag == 1)
		nb = va_arg(arg, unsigned long int);
	else if (ans->l_flag == 2)
		nb = va_arg(arg, unsigned long long int);
	else if (ans->j_flag == 1)
		nb = va_arg(arg, uintmax_t);
	else if (ans->z_flag == 1)
		nb = va_arg(arg, size_t);
	else
		nb = va_arg(arg, unsigned int);
	return (nb);
}

void				ft_x(t_ans *ans, va_list arg)
{
	uintmax_t	nb;
	char		*str;
	int			i;

	nb = ft_gstconv(ans, arg);
	if (nb == 0 && ans->sign != 'P')
		ans->sign = '0';
	i = 0;
	str = ft_utoa_base(nb, 16);
	if (ans->upper == TRUE)
		while (str[i] != '\0')
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	ans->sp_flag = FALSE;
	ans->digit = ((ans->sharp == TRUE && nb != 0) ||
					ans->sign == 'P') ? ans->digit - 2 : ans->digit;
	ans->plus = FALSE;
	str[0] = (ans->sign == 'P' && nb == 0 && ans->prec >= 0) ? 0 : str[0];
	ft_digit_zero_prec_dgt_x(ans, str);
	free(str);
}
