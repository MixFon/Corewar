/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag_spetia_type.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:16:50 by widraugr          #+#    #+#             */
/*   Updated: 2019/02/08 12:24:46 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_chack_flag(t_format *lst, char flag)
{
	int i;

	i = -1;
	while (++i < 5)
		if (lst->flag[i] == flag)
			return (1);
	return (0);
}

void	ft_check_special_type(char *iter, t_format *lst)
{
	if (*iter == 'U' || *iter == 'D' || *iter == 'O')
	{
		lst->size[0] = 'l';
		lst->size[1] = 'l';
	}
}
