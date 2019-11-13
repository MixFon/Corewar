/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:51:31 by widraugr          #+#    #+#             */
/*   Updated: 2019/03/25 10:10:54 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_numwrld(char const *s, char c)
{
	unsigned int num;

	num = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s == c && *(s + 1) != c)
			num++;
		s++;
	}
	if (*(s - 1) && *(s - 1) != c)
		num++;
	return (num);
}

static size_t	ft_strclen(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static	char	**ft_strfree(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	int		wrld;
	int		i;
	int		num;
	char	**arr;

	i = 0;
	num = 0;
	if (!s)
		return (NULL);
	wrld = ft_numwrld(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (wrld + 1))))
		return (NULL);
	while (i < wrld)
	{
		while (*(s + num) == c)
			num++;
		if (!(arr[i] = ft_strsub(s, num, ft_strclen((char *)(s + num), c))))
			return (ft_strfree(arr, i));
		while (*(s + num) != c)
			num++;
		i++;
	}
	arr[i] = (void *)0;
	return (arr);
}
