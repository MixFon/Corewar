/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:08:53 by widraugr          #+#    #+#             */
/*   Updated: 2019/02/07 10:49:45 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_strdup_wchar(const wchar_t *s1)
{
	int		i;
	wchar_t	*str_cop;

	i = 0;
	while (s1[i])
		i++;
	if (!(str_cop = (wchar_t*)malloc(sizeof(wchar_t) * (i + 1))))
		return (0);
	i = 0;
	while (s1[i])
	{
		str_cop[i] = s1[i];
		i++;
	}
	str_cop[i] = L'\0';
	return (str_cop);
}
