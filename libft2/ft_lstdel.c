/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:34:50 by widraugr          #+#    #+#             */
/*   Updated: 2018/12/07 16:02:19 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*iter;

	while (*alst)
	{
		iter = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = iter;
	}
	alst = NULL;
}
