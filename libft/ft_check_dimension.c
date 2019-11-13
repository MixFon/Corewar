/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dimension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:42:02 by widraugr          #+#    #+#             */
/*   Updated: 2019/02/08 11:45:44 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_check_dimension(t_format *lst, va_list lst_arg)
{
	intmax_t	arg;

	arg = va_arg(lst_arg, intmax_t);
	if (lst->size[0] == 'h' && lst->size[1] == '\0')
		arg = (short int)arg;
	else	if (lst->size[0] == 'h' && lst->size[1] == 'h')
		arg = (signed char)arg;
	else	if (lst->size[0] == 'l' && lst->size[1] == '\0')
		arg = (long int)arg;
	else	if (lst->size[0] == 'l' && lst->size[1] == 'l')
		arg = (long long int)arg;
	else	if (lst->size[0] == 'j' && lst->size[1] == '\0')
		arg = (intmax_t)arg;
	else	if (lst->size[0] == 'z' && lst->size[1] == '\0')
		arg = (size_t)arg;
	else
		arg = (int)arg;
	return (arg);
}
