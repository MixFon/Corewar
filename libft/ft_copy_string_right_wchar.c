/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_string_right_wchar.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:14:35 by widraugr          #+#    #+#             */
/*   Updated: 2019/02/08 12:37:58 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_copy_string_right_wchar(wchar_t *str1, wchar_t *str2)
{
	int	len1;
	int	len2;

	len1 = (int)ft_strlen_wchar(str1);
	len2 = (int)ft_strlen_wchar(str2);
	if (len1 >= len2)
	{
		ft_strdel_wchar(&str2);
		return (str1);
	}
	else
	{
		while (len2 >= 0 && len1 >= 0)
			str2[len2--] = str1[len1--];
		ft_strdel_wchar(&str1);
		return (str2);
	}
}
