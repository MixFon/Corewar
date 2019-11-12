
#include "../include/asm.h"

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
	while(islablechar(*start) && *start != '\0')
		start++;
	arg->lable = ft_strnew(start - temp);
	ft_strncpy(arg->lable, temp, start - temp);
	return (start);
}
