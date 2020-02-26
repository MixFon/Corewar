/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_agr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:28:02 by widraugr          #+#    #+#             */
/*   Updated: 2020/02/26 10:24:16 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int		is_char_end_line(char c)
{
	if ((c >= 33 && c <= 34) || c == 36 || (c >= 38 && c <= 43)
			|| (c >= 45 && c <= 47) || (c >= 60 && c <= 64)
			|| (c >= 91 && c <= 95) || (c >= 123 && c <= 126))
		return (1);
	return (0);
}

void	working_lable(t_assm *assm, char *start, char *line)
{
	check_lable(assm, start, line);
	add_lable_list(assm, start, line);
	working_instruction(assm, line + 1);
}

int		isdigit_per_colon(int c)
{
	if ((c <= 58 && c >= 48) || c == 37)
		return (1);
	return (0);
}

void	init_arg(t_arg *arg)
{
	arg->dir = 0;
	arg->ind = 0;
	arg->reg = 0;
	arg->lable = NULL;
	arg->bl_ind = 0;
	arg->bl_dir = 0;
	arg->bl_reg = 0;
}
