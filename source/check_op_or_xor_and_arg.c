/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op_or_xor_and_arg.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:32:02 by widraugr          #+#    #+#             */
/*   Updated: 2019/11/13 12:12:49 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

char	*read_arguments(t_assm *assm, t_arg *arg, char *start)
{
	while (*start)
	{
		if (ft_isdigit(*start) || *start == ':' || *start == '-')
			start = read_ind_adg(assm, arg, start);
		if (*start == '%')
			start = read_dir_adg(assm, arg, start);
		if (*start == 'r')
			start = read_reg_adg(assm, arg, start + 1);
		if (ft_isalpha(*start))
			error("Error argument.", assm);
		if (*start == ',')
			return (start);
		if (*start == '#')
		{
			while (*start)
				start++;
			return (start);
		}
		if (*start == '\0')
			continue ;
		start++;
	}
	return (start);
}

t_opr	*get_arg_opr(t_assm *assm, char *start)
{
	t_opr *opr;

	if (!(opr = (t_opr *)malloc(sizeof(t_opr))))
		sys_err("Error malloc\n");
	init_opt(opr);
	start = read_arguments(assm, &opr->args[0], start);
	if (*start == ',')
	{
		start++;
		opr->count_args++;
	}
	start = read_arguments(assm, &opr->args[1], start);
	if (*start == ',')
	{
		start++;
		opr->count_args++;
	}
	start = read_arguments(assm, &opr->args[2], start);
	return (opr);
}

void	check_op_ld_lld_arg(t_assm *assm, t_opr *opr)
{
	if (opr->count_args != 2)
		error("Error arguments instruction.", assm);
	if (opr->args[0].bl_dir == 0 && opr->args[0].bl_ind == 0)
		error("Error first arguments instruction.", assm);
	if (opr->args[0].bl_reg == C_REG)
		error("Error first arguments instruction.", assm);
	if (opr->args[1].bl_reg == 0)
		error("Error second arguments instruction.", assm);
	if (opr->args[1].bl_ind == C_IND || opr->args[1].bl_dir == C_DIR)
		error("Error second arguments instruction.", assm);
	if (opr->args[2].bl_dir == C_DIR || opr->args[2].bl_ind == C_IND ||
			opr->args[2].bl_reg == C_REG)
		error("Error three arguments instruction.", assm);
}

void	check_op_st_arg(t_assm *assm, t_opr *opr)
{
	if (opr->count_args != 2)
		error("Error arguments instruction.", assm);
	if (opr->args[0].bl_reg == 0)
		error("Error first arguments instruction.", assm);
	if (opr->args[0].bl_ind == C_IND || opr->args[0].bl_dir == C_DIR)
		error("Error first arguments instruction.", assm);
	if (opr->args[1].bl_reg == 0 && opr->args[1].bl_ind == 0)
		error("Error second arguments instruction.", assm);
	if (opr->args[1].bl_dir == C_DIR)
		error("Error second arguments instruction.", assm);
	if (opr->args[2].bl_dir == C_DIR || opr->args[2].bl_ind == C_IND ||
			opr->args[2].bl_reg == C_REG)
		error("Error three arguments instruction.", assm);
}

/*
** The function cheacks the arguments of 4 instruction: or, xor, and.
*/

void	check_op_or_xor_and_arg(t_assm *assm, t_opr *opr)
{
	if (opr->count_args != 3)
		error("Error arguments instruction.", assm);
	if (opr->args[0].bl_reg == 0 && opr->args[0].bl_ind == 0 &&
			opr->args[0].bl_dir == 0)
		error("Error first arguments instruction.", assm);
	if (opr->args[1].bl_reg == 0 && opr->args[1].bl_ind == 0 &&
			opr->args[1].bl_dir == 0)
		error("Error second arguments instruction.", assm);
	if (opr->args[2].bl_reg == 0)
		error("Error three arguments instruction.", assm);
	if (opr->args[2].bl_dir == C_DIR || opr->args[2].bl_ind == C_IND)
		error("Error three arguments instruction.", assm);
}
