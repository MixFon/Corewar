
#include "../include/asm.h"

void	op_all(t_assm *assm, t_opr *opr, int code, void (*func)(t_assm*, t_opr*))
{
	unsigned char	code_args;
	int				temp;
	int				i;

	i = -1;
	(*func)(assm, opr);
	code_args = get_code_arg(opr);
	temp = code & 0xff;
	temp = (code >> 16) & 0xf;
	opr->info.bl_code_arg = temp;
	if (temp)
		ft_putchar_fd(code_args, assm->fd_cor);
	temp = (code >> 8) & 0xf;
	assm->pos_glob += temp;
	opr->info.oct_start = temp;
	temp = (code >> 12) & 0xf;
	opr->info.size_dir = temp;
	while(--opr->count_args >= 0)
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

void	five_char_operator(t_assm *assm, char *start)
{	
	t_opr	*opr;
	int		up;

	up = 5;
	opr = get_arg_opr(assm, start + up);
	if (!(ft_strncmp(start, "lfork", up)))
		op_all(assm, opr, 0x0210f, check_op_fork_lfork_zjmp_live_arg);
	else
		error("Unknown instruction.", assm);
	delete_opr(&opr);
}

void	three_char_operator(t_assm *assm, char *start)
{
	t_opr	*opr;
	int		up;

	up = 3;
	opr = get_arg_opr(assm, start + up);
	if (!(ft_strncmp(start, "aff", up)))
		op_all(assm, opr, 0x14210, check_op_aff_arg);
	else if (!(ft_strncmp(start, "add", up)))
		op_all(assm, opr, 0x14204, check_op_add_sub_arg);
	else if (!(ft_strncmp(start, "sub", up)))
		op_all(assm, opr, 0x14205, check_op_add_sub_arg);
	else if (!(ft_strncmp(start, "and", up)))
		op_all(assm, opr, 0x14206, check_op_or_xor_and_arg);
	else if (!(ft_strncmp(start, "xor", up)))
		op_all(assm, opr, 0x14208, check_op_or_xor_and_arg);
	else if (!(ft_strncmp(start, "ldi", up)))
		op_all(assm, opr, 0x1220a, check_op_ldi_lldi_arg);
	else if (!(ft_strncmp(start, "lld", up)))
		op_all(assm, opr, 0x1420d, check_op_ld_lld_arg);
	else if (!(ft_strncmp(start, "sti", up)))
		op_all(assm, opr, 0x1220b, check_op_sti_arg);
	else
		error("Unknown instruction.", assm);
	delete_opr(&opr);
}
