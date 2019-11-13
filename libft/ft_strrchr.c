/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:16:04 by widraugr          #+#    #+#             */
/*   Updated: 2018/12/11 15:38:16 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	int			j;
	const char	*ptr;

	i = 0;
	j = 0;
	ptr = NULL;
	while (s[i] != '\0')
		i++;
	i++;
	while (j < i)
	{
		if (*s == (unsigned char)c)
			ptr = s;
		s++;
		j++;
	}
	return ((char *)ptr);
}
