
#include "../include/asm.h"

char	*read_ind_adg(t_assm *assm, t_arg *arg, char *start)
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

char	*read_dir_adg(t_assm *assm, t_arg *arg, char *start)
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

char	*read_arguments(t_assm *assm, t_arg *arg, char *start)
{
	while (*start)
	{
		if (ft_isdigit(*start) || *start == ':'|| *start == '-')
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

	if(!(opr = (t_opr *)malloc(sizeof(t_opr))))
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
