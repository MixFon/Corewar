/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_lbl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:38:11 by widraugr          #+#    #+#             */
/*   Updated: 2020/02/24 13:26:06 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

unsigned char	get_code_arg(t_opr *opr)
{
	unsigned char code;

	code = opr->args[0].bl_ind | opr->args[0].bl_dir | opr->args[0].bl_reg;
	code = code << 2;
	code = code | opr->args[1].bl_ind | opr->args[1].bl_dir |
		opr->args[1].bl_reg;
	code = code << 2;
	code = code | opr->args[2].bl_ind | opr->args[2].bl_dir |
		opr->args[2].bl_reg;
	code = code << 2;
	return (code);
}

int				write_big_endian(t_assm *assm, int fd, void *bits, int len_bits)
{
	int	count_oct;

	count_oct = 0;
	fd = 0;
	while (len_bits > 0)
	{
		len_bits--;
		write_code_str(assm, (unsigned char *)bits + len_bits);
		count_oct++;
	}
	return (count_oct);
}

t_lbl			*get_lbl(t_lbl **lbl, char *lable)
{
	t_lbl *temp;

	temp = *lbl;
	while (temp)
	{
		if (!ft_strcmp(temp->name, lable))
			return (temp);
		temp = temp->next;
	}
	temp = create_lable(lable, lable + ft_strlen(lable));
	temp->next = *lbl;
	*lbl = temp;
	(*lbl)->bl = 0;
	(*lbl)->position = LEN_HEAD;
	return (temp);
}

t_gab			*new_gab(t_assm *assm, t_info **info, t_arg *arg)
{
	t_gab *new;

	if (!(new = (t_gab *)malloc(sizeof(t_gab))))
		sys_err("Error malloc.\n");
	if (arg->bl_dir != 0)
	{
		new->oct_start = ((*info)->bl_code_arg == 1 ? (*info)->oct_start : 1);
		new->oct_count = (*info)->size_dir;
	}
	else if (arg->bl_ind != 0)
	{
		new->oct_start = (*info)->oct_start;
		new->oct_count = 2;
	}
	else if (arg->bl_reg != 0)
	{
		new->oct_start = (*info)->oct_start;
		new->oct_count = 1;
	}
	new->pos_write = assm->pos_glob;
	new->next = NULL;
	return (new);
}

void			search_lbl(t_assm *assm, t_info *info, t_arg *arg)
{
	t_gab *gab;
	t_lbl *lbl;

	gab = new_gab(assm, &info, arg);
	lbl = get_lbl(&assm->lbl, arg->lable);
	if (lbl->gab == NULL)
		lbl->gab = gab;
	else
	{
		gab->next = lbl->gab;
		lbl->gab = gab;
	}
}
