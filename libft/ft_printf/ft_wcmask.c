/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcmask.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 13:45:48 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/22 18:50:40 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wmask(int nb, t_ans *ans)
{
	wchar_t	lst;

	lst = 0;
	if (nb < 129)
		lst = nb;
	else if (nb < 2049)
	{
		lst += ((0xc0 | ((0x7c0 & nb) >> 6)) + (0x8000 | ((0x3f & nb) << 8)));
		ans->prec = (ans->prec == 1) ? 2 : ans->prec;
	}
	else if (nb < 65537)
	{
		lst += (0xe0 | ((0xf000 & nb) >> 12)) + (0x8000 | ((0xfc0 & nb) << 2)) +
				(0x800000 | ((0x3f & nb) << 16));
		ans->prec = (ans->prec > 0 && ans->prec < 3) ? 3 : ans->prec;
	}
	else if (nb < 2097153)
	{
		lst = (0xf0 | ((0x1c0000 & nb) >> 18)) +
				(0x8000 | ((0x3f000 & nb) >> 4)) +
				(0x800000 | ((0xfc00 & nb) << 6)) +
				(0x80000000 | ((0x3f & nb) << 24));
		ans->prec = (ans->prec > 0 && ans->prec < 4) ? 4 : ans->prec;
	}
	return (lst);
}
