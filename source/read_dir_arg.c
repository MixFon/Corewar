/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:29:07 by widraugr          #+#    #+#             */
/*   Updated: 2019/11/13 13:22:06 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	init_opt(t_opr *opr)
{
	init_arg(&opr->args[0]);
	init_arg(&opr->args[1]);
	init_arg(&opr->args[2]);
	opr->count_args = 1;
	opr->info.size_dir = 0;
	opr->info.bl_code_arg = 0;
	opr->info.oct_start = 0;
}

char	*create_lable_arg(char *start, t_arg *arg)
{
	char *temp;

	temp = start;
	while (islablechar(*start) && *start != '\0')
		start++;
	arg->lable = ft_strnew(start - temp);
	ft_strncpy(arg->lable, temp, start - temp);
	return (start);
}

char	*read_ind_adg(t_arg *arg, char *start)
{
	arg->bl_ind = C_IND;
	if (*start == ':')
	{
		start = create_lable_arg((start + 1), arg);
		return (start);
	}
	arg->ind = ft_atoi(start);
	while (ft_isdigit(*start) || *start == '-')
		start++;
	return (start);
}

char	*read_reg_adg(t_assm *assm, t_arg *arg, char *start)
{
	if (!ft_isdigit(*start))
		error("Error registr.", assm);
	arg->bl_reg = C_REG;
	arg->reg = ft_atoi(start);
	if (arg->reg > REG_NUMBER || arg->reg <= 0)
		error("Error number registr.", assm);
	while (ft_isdigit(*start))
		start++;
	return (start);
}

char	*read_dir_adg(t_arg *arg, char *start)
{
	start++;
	arg->bl_dir = C_DIR;
	if (ft_isdigit(*start) || *start == '-')
		arg->dir = ft_atoi(start);
	else if (*start == ':')
		start = create_lable_arg(start + 1, arg);
	while (ft_isdigit(*start) || *start == '-')
		start++;
	return (start);
}
