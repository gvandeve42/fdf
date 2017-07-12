/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:02:51 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/05 15:46:32 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_atoi(const char *str)
{
	char	*tmp;
	int		result;
	int		sign;

	tmp = (char*)str;
	result = 0;
	sign = 0;
	while (*tmp >= 0 && *tmp <= 32)
		tmp++;
	if (*tmp == '+' || *tmp == '-')
	{
		if (*tmp == '-')
			sign = 1;
		tmp++;
	}
	while (*tmp >= '0' && *tmp <= '9')
	{
		result *= 10;
		result += (*tmp - '0');
		tmp++;
	}
	if (sign == 1)
		result = -result;
	return (result);
}
