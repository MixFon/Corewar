/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:34:27 by widraugr          #+#    #+#             */
/*   Updated: 2020/02/24 14:20:25 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	i++;
	while (j < i)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
		j++;
	}
	return (NULL);
}
