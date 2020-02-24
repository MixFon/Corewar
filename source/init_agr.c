/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_agr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:28:02 by widraugr          #+#    #+#             */
/*   Updated: 2020/02/24 12:18:07 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	print_gab_list(t_gab *gab)
{
	while (gab != NULL)
	{
		ft_printf("\tpos_write = {%d} oct_count = {%d} oct_start = [%d]\n",
			gab->pos_write - LEN_HEAD, gab->oct_count, gab->oct_start);
		gab = gab->next;
	}
}

void	print_list(t_lbl *lbl)
{
	ft_putendl("List:");
	while (lbl)
	{
		ft_printf("lable = {%s} position = {%d} bl = [%d]\n", lbl->name,
				lbl->position - LEN_HEAD, lbl->bl);
		print_gab_list(lbl->gab);
		lbl = lbl->next;
	}
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
