/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_char_operator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:40:34 by widraugr          #+#    #+#             */
/*   Updated: 2020/02/24 13:24:46 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	all_arg(t_assm *assm, t_info *info, t_arg *arg)
{
	int	delta;

	delta = 0;
	if (arg->lable != NULL)
		search_lbl(assm, info, arg);
	if (arg->bl_ind != 0)
		delta += write_big_endian(assm, assm->fd_cor, &arg->ind, IND_SIZE);
	if (arg->bl_dir != 0)
		delta += write_big_endian(assm, assm->fd_cor,
				&arg->dir, info->size_dir);
	if (arg->bl_reg != 0)
		delta += write_big_endian(assm, assm->fd_cor, &arg->reg, 1);
	assm->pos_glob += delta;
	info->oct_start += delta;
}

void	delete_opr(t_opr **opr)
{
	ft_strdel(&(*opr)->args[0].lable);
	ft_strdel(&(*opr)->args[1].lable);
	ft_strdel(&(*opr)->args[2].lable);
	free(*opr);
}

void	op_all(t_assm *assm, t_opr *opr, int code,
		void (*func)(t_assm*, t_opr*))
{
	unsigned char	code_args;
	int				temp;
	int				i;

	i = -1;
	(*func)(assm, opr);
	code_args = get_code_arg(opr);
	temp = code & 0xff;
	to_code_str(assm, temp);
	temp = (code >> 16) & 0xf;
	opr->info.bl_code_arg = temp;
	if (temp)
		to_code_str(assm, code_args);
	temp = (code >> 8) & 0xf;
	assm->pos_glob += temp;
	opr->info.oct_start = temp;
	temp = (code >> 12) & 0xf;
	opr->info.size_dir = temp;
	while (--opr->count_args >= 0)
		all_arg(assm, &opr->info, &opr->args[++i]);
}

void	two_char_operator(t_assm *assm, char *start)
{
	t_opr *opr;

	opr = get_arg_opr(assm, start + 2);
	if (!(ft_strncmp(start, "ld", 2)))
		op_all(assm, opr, 0x14202, check_op_ld_lld_arg);
	else if (!(ft_strncmp(start, "st", 2)))
		op_all(assm, opr, 0x14203, check_op_st_arg);
	else if (!(ft_strncmp(start, "or", 2)))
		op_all(assm, opr, 0x14207, check_op_or_xor_and_arg);
	else
		error("Unknown instruction.", assm);
	delete_opr(&opr);
}

void	four_char_operator(t_assm *assm, char *start)
{
	t_opr	*opr;
	int		up;

	up = 4;
	opr = get_arg_opr(assm, start + up);
	if (!(ft_strncmp(start, "lldi", up)))
		op_all(assm, opr, 0x1220e, check_op_ldi_lldi_arg);
	else if (!(ft_strncmp(start, "fork", up)))
		op_all(assm, opr, 0x0210c, check_op_fork_lfork_zjmp_live_arg);
	else if (!(ft_strncmp(start, "zjmp", up)))
		op_all(assm, opr, 0x02109, check_op_fork_lfork_zjmp_live_arg);
	else if (!(ft_strncmp(start, "live", up)))
		op_all(assm, opr, 0x04101, check_op_fork_lfork_zjmp_live_arg);
	else
		error("Unknown instruction.", assm);
	delete_opr(&opr);
}
