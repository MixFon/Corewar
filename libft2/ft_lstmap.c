/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 09:19:56 by widraugr          #+#    #+#             */
/*   Updated: 2018/12/28 13:21:30 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*firptr;

	if (!lst)
		return (NULL);
	newlist = f(lst);
	firptr = newlist;
	while (lst->next)
	{
		lst = lst->next;
		if (!(newlist->next = f(lst)))
			return (NULL);
		newlist = newlist->next;
	}
	return (firptr);
}
