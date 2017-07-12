/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:11:34 by gvandeve          #+#    #+#             */
/*   Updated: 2017/02/09 17:02:26 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_scan(unsigned long long int n, int base)
{
	int		len;

	len = 0;
	while (n > (base - (unsigned long long int)1))
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

char		*ft_utoa_base(unsigned long long int n, int base)
{
	int						len;
	char					*str;

	len = ft_scan(n, base);
	if ((str = (char*)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	ft_insert(str, n, len, base);
	str[len] = '\0';
	return (str);
}
