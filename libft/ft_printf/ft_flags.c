/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:13:28 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/20 18:01:03 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_digit(t_ans *ans, char *str)
{
	if (ans->digit > 0)
	{
		if (ans->moins == TRUE)
		{
			ft_safe_str(ans, str);
			ft_safe_iter(ans, ' ', ans->digit);
		}
		else
		{
			ft_safe_iter(ans, ' ', ans->digit);
			ft_safe_str(ans, str);
		}
	}
	else
		ft_safe_str(ans, str);
}

void	ft_digit_zero(t_ans *ans, char *str)
{
	char	c;

	c = ' ';
	if (ans->moins == FALSE)
		if (ans->zero == TRUE)
			c = '0';
	if (ans->digit > 0)
	{
		if (ans->moins == TRUE)
		{
			ft_safe_str(ans, str);
			ft_safe_iter(ans, c, (ans->digit - 1));
		}
		else
		{
			ft_safe_iter(ans, c, (ans->digit - 1));
			ft_safe_str(ans, str);
		}
	}
	else
		ft_safe_str(ans, str);
}

void	ft_digit_zero_c0(t_ans *ans)
{
	char	c;

	c = ' ';
	if (ans->moins == FALSE)
		if (ans->zero == TRUE)
			c = '0';
	if (ans->digit > 0)
	{
		if (ans->moins == TRUE)
		{
			ft_safe_cpy(ans, 0);
			ft_safe_iter(ans, c, (ans->digit - 1));
		}
		else
		{
			ft_safe_iter(ans, c, (ans->digit - 1));
			ft_safe_cpy(ans, 0);
		}
	}
	else
		ft_safe_cpy(ans, 0);
}
