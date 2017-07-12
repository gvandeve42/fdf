/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:35:07 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/22 18:26:22 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_su(t_ans *ans, va_list arg)
{
	ans->h_flag = 0;
	ans->l_flag = 1;
	ft_s(ans, arg);
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

void	ft_b(t_ans *ans, va_list arg)
{
	uintmax_t	nb;
	char		*str;

	nb = ft_gstconv(ans, arg);
	ans->sp_flag = FALSE;
	ans->plus = FALSE;
	ans->sharp = FALSE;
	str = ft_utoa_base(nb, 2);
	ft_digit_zero_prec_dgt_x(ans, str);
	free(str);
}
