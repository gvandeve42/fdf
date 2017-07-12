/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:29:13 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/11 16:18:04 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*anchor;

	if ((new = ft_lstnew((f(lst))->content, (f(lst))->content_size)) == NULL)
		return (NULL);
	anchor = new;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new->next = ft_lstnew((f(lst))->content, (f(lst))->content_size);
		new = new->next;
	}
	return (anchor);
}
