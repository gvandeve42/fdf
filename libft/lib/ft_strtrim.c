/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:04:58 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/08 11:25:24 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_scan_forward(char *s, size_t length)
{
	size_t	result;

	result = 0;
	while (result < length &&
			(s[result] == ' ' ||
			s[result] == '\n' ||
			s[result] == '\t'))
		result++;
	return (result);
}

static size_t	ft_scan_backward(char *s, size_t length)
{
	size_t	total;

	total = length;
	while (s[length - 1] &&
			(s[length - 1] == ' ' ||
			s[length - 1] == '\n' ||
			s[length - 1] == '\t'))
		length--;
	return (total - length);
}

char			*ft_strtrim(const char *s)
{
	size_t	clean_start;
	size_t	clean_end;
	char	*new;
	char	*anchor;
	size_t	sht_len;

	if ((clean_start = ft_scan_forward((char*)s, ft_strlen((char*)s))) ==
		ft_strlen((char*)s))
		return ("");
	clean_end = ft_scan_backward((char*)s, ft_strlen((char*)s));
	sht_len = ft_strlen((char*)s) - clean_start - clean_end + 1;
	if ((new = (char*)malloc((sht_len) * sizeof(char))) == NULL)
		return (NULL);
	anchor = new;
	while (clean_start < (ft_strlen((char*)s) - clean_end))
		*new++ = s[clean_start++];
	*new = '\0';
	return (anchor);
}
