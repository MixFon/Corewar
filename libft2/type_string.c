/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:21:00 by widraugr          #+#    #+#             */
/*   Updated: 2019/02/11 13:33:29 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sourse(char **arg, char **str_wid, int *flag, t_format *lst)
{
	if (*arg == NULL)
	{
		*arg = ft_strdup("(null)");
		*flag = 1;
	}
	if (ft_chack_flag(lst, '0') && !ft_chack_flag(lst, '-'))
		*str_wid = ft_strnew_char('0', lst->width);
	else
		*str_wid = ft_strnew_char(' ', lst->width);
}

void	ft_put_str_without_size(t_format *lst, va_list lst_arg)
{
	char	*str_wid;
	char	*str_exac;
	char	*str_res;
	char	*arg;
	int		flag;

	flag = 0;
	arg = va_arg(lst_arg, char*);
	ft_sourse(&arg, &str_wid, &flag, lst);
	if (lst->exactness == 0 && lst->dot == 0)
		str_exac = ft_strdup(arg);
	else
	{
		str_exac = ft_strnew_char(' ', lst->exactness);
		str_exac = ft_strncpy(str_exac, arg, lst->exactness);
	}
	if (ft_chack_flag(lst, '-'))
		str_res = ft_copy_string_left(str_exac, str_wid);
	else
		str_res = ft_copy_string_right(str_exac, str_wid);
	if (flag)
		ft_strdel(&arg);
	ft_putstr(str_res);
	lst->len_str = ft_strlen(str_res);
	ft_strdel(&str_res);
}

void	ft_sourse_wchar(wchar_t **arg, wchar_t **str_wid, int *flag,
		t_format *lst)
{
	if (*arg == NULL)
	{
		*arg = ft_strdup_wchar(L"(null)");
		*flag = 1;
	}
	*str_wid = ft_strnew_char_wchar(L' ', lst->width);
}

/*
** Wchar_t
*/

void	ft_wchar_str(t_format *lst, va_list lst_arg)
{
	wchar_t	*str_wid;
	wchar_t	*str_exac;
	wchar_t	*str_res;
	wchar_t	*arg;
	int		flag;

	flag = 0;
	arg = va_arg(lst_arg, wchar_t*);
	ft_sourse_wchar(&arg, &str_wid, &flag, lst);
	if (lst->exactness == 0 && lst->dot == 0)
		str_exac = ft_strdup_wchar(arg);
	else
	{
		str_exac = ft_strnew_char_wchar(L' ', lst->exactness);
		str_exac = ft_strncpy_wchar(str_exac, arg, lst->exactness);
	}
	if (ft_chack_flag(lst, '-'))
		str_res = ft_copy_string_left_wchar(str_exac, str_wid);
	else
		str_res = ft_copy_string_right_wchar(str_exac, str_wid);
	if (flag)
		ft_strdel_wchar(&arg);
	ft_putstr_wchar(str_res);
	lst->len_str = ft_strlen_wchar(str_res);
	ft_strdel_wchar(&str_res);
}

void	ft_put_string(t_format *lst, va_list lst_arg, char s)
{
	if (s == 's')
		ft_put_str_without_size(lst, lst_arg);
	else	if (s == 'S')
		ft_wchar_str(lst, lst_arg);
}
