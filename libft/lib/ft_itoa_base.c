/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:11:34 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/13 18:19:42 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_scan(unsigned long long int n, int base)
{
	int		len;

	len = 0;
	while (n > (base - (unsigned long long)1))
	{
		len++;
		n /= base;
	}
	len++;
	return (len);
}

static void	ft_insert(char *str, unsigned long long int n, int len, int base)
{
	while (len > 0)
	{
		if (base > 10 && (n % base) > 9)
			str[len - 1] = (n % base) + 'a' - 10;
		else
			str[len - 1] = (n % base) + '0';
		len--;
		n /= base;
	}
}

char		*ft_itoa_base(long long int n, int base)
{
	unsigned long long int	res;
	int						len;
	int						neg;
	char					*str;

	neg = 0;
	res = n;
	if (n < 0)
	{
		res = (n * -1);
		neg = 1;
	}
	len = ft_scan(res, base);
	len = (neg ? len + 1 : len);
	if ((str = (char*)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	ft_insert(str, res, len, base);
	str[len] = '\0';
	str[0] = (neg ? '-' : str[0]);
	return (str);
}
