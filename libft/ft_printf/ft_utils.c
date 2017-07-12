/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:03:46 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/22 18:42:36 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_safe_cpy(t_ans *ans, unsigned char c)
{
	if (ans->i_b == BUFF_SIZE)
	{
		write(1, (ans->buff), BUFF_SIZE);
		ft_bzero((ans->buff), BUFF_SIZE);
		ans->i_b = 0;
		ans->rtn += BUFF_SIZE;
	}
	ans->buff[ans->i_b] = c;
	ans->i_b++;
}

void		ft_safe_str(t_ans *ans, char *str)
{
	while (*str != '\0')
		ft_safe_cpy(ans, *str++);
}

void		ft_safe_iter(t_ans *ans, char c, int nb)
{
	while (nb-- > 0)
		ft_safe_cpy(ans, c);
}

t_bool		ft_is_flag(char c)
{
	char	*flag_lst;

	flag_lst = "+-0.# hljz";
	while (*flag_lst != '\0')
		if (c == *flag_lst++)
			return (TRUE);
	return (FALSE);
}

t_bool		ft_is_conv(char c)
{
	char	*conv_lst;

	conv_lst = "%cCDduUisSoOxXbp";
	while (*conv_lst != '\0')
		if (c == *conv_lst++)
			return (TRUE);
	return (FALSE);
}
