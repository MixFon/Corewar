/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:38:15 by widraugr          #+#    #+#             */
/*   Updated: 2019/02/07 10:42:11 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_strnew_wchar(size_t size)
{
	wchar_t *str;

	if (size == (size_t)(-1))
		return (NULL);
	if (!(str = (wchar_t *)malloc(sizeof(wchar_t) * (size + 1))))
		return (NULL);
	str = (wchar_t *)ft_memset(str, '\0', size + 1);
	return (str);
}
