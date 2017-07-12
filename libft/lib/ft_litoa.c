/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:02:22 by gvandeve          #+#    #+#             */
/*   Updated: 2017/02/09 17:06:39 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_scan(unsigned long int n)
{
	int		len;

	len = 0;
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	len++;
	return (len);
}

static void	ft_insert(char *str, unsigned long int n, int len)
{
	while (len > 0)
	{
		str[len - 1] = (n % 10) + '0';
		len--;
		n /= 10;
	}
}

char		*ft_litoa(long int n)
{
	unsigned long int		res;
	int						len;
	int						neg;
	char					*str;

	neg = 0;
	res = n;
	if (n < 0)
	{
		res = -n;
		neg = 1;
	}
	len = ft_scan(res);
	len = (neg ? len + 1 : len);
	if ((str = (char*)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	ft_insert(str, res, len);
	str[len] = '\0';
	str[0] = (neg ? '-' : str[0]);
	return (str);
}
