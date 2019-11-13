/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:04:37 by widraugr          #+#    #+#             */
/*   Updated: 2018/12/06 10:32:16 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_rtnarr(char const *s, size_t i, size_t l)
{
	size_t	n;
	char	*str;

	n = 0;
	if (!(str = (char *)malloc(sizeof(char) * (l - i) + 1)))
		return (NULL);
	while (i <= l)
	{
		str[n] = s[i];
		i++;
		n++;
	}
	str[n - 1] = '\0';
	return (str);
}

static char	*ft_rtnnull(void)
{
	char *str;

	str = (char *)malloc(sizeof(char) * 1);
	*str = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	l;

	i = 0;
	if (!s)
		return (NULL);
	l = ft_strlen(s);
	while (s[i] == ',' || s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
		i++;
	while (s[l - 1] == ',' || s[l - 1] == '\n' ||
			s[l - 1] == ' ' || s[l - 1] == '\t')
		l--;
	if (s[i] == '\0')
		return (ft_rtnnull());
	else
		return (ft_rtnarr(s, i, l));
}
