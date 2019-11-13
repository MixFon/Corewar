/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:20:17 by widraugr          #+#    #+#             */
/*   Updated: 2019/02/11 13:25:05 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset_wchar(void *b, wchar_t c, size_t len)
{
	wchar_t	*str;
	size_t	i;

	if (len == 0)
		return (b);
	i = 0;
	str = b;
	while (i < len)
	{
		str[i] = (wchar_t)c;
		i++;
	}
	return (b);
}
