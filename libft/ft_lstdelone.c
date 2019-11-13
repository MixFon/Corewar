/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:25:37 by widraugr          #+#    #+#             */
/*   Updated: 2018/12/07 15:20:20 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del) (void *, size_t))
{
	size_t	size;
	void	*ptr;

	size = (*alst)->content_size;
	ptr = (*alst)->content;
	del(ptr, size);
	free(*alst);
	*alst = NULL;
}
