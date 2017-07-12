/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:28:47 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/11 14:22:22 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	while ((*alst) != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		(*alst) = (*alst)->next;
	}
	alst = NULL;
}
