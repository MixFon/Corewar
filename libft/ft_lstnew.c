/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_lstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:04:14 by widraugr          #+#    #+#             */
/*   Updated: 2018/12/20 14:49:25 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newl;

	if (!(newl = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		newl->content = NULL;
		newl->content_size = 0;
	}
	else
	{
		if (!(newl->content = ft_memalloc(content_size)))
			return (NULL);
		newl->content = ft_memmove(newl->content, content, content_size);
		newl->content_size = content_size;
	}
	newl->next = NULL;
	return (newl);
}
