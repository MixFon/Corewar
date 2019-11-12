
#include "../include/asm.h"

void	check_op_aff_arg(t_assm *assm, t_opr *opr)
{
	if (opr->count_args != 1)
		error("Error arguments instruction.", assm);
	if (opr->args[0].bl_reg == 0)
		error("Error first arguments instruction.", assm);
	if (opr->args[0].bl_ind == C_IND || opr->args[0].bl_dir == C_DIR)
		error("Error first arguments instruction.", assm);
	if (opr->args[1].bl_ind == C_IND || opr->args[1].bl_dir == C_DIR ||
			opr->args[1].bl_reg == C_REG)
		error("Error second arguments instruction.", assm);
	if (opr->args[2].bl_dir == C_DIR || opr->args[2].bl_ind == C_IND ||
			opr->args[2].bl_reg == C_REG)
		error("Error three arguments instruction.", assm);
}

void	check_op_add_sub_arg(t_assm *assm, t_opr *opr)
{
	if (opr->count_args != 3)
		error("Error arguments instruction.", assm);
	if (opr->args[0].bl_reg == 0)
		error("Error first arguments instruction.", assm);
	if (opr->args[0].bl_ind == C_IND || opr->args[0].bl_dir == C_DIR)
		error("Error first arguments instruction.", assm);
	if (opr->args[1].bl_reg == 0)
		error("Error second arguments instruction.", assm);
	if (opr->args[1].bl_ind == C_IND || opr->args[1].bl_dir == C_DIR)
		error("Error second arguments instruction.", assm);
	if (opr->args[2].bl_reg == 0)
		error("Error three arguments instruction.", assm);
	if (opr->args[2].bl_ind == C_IND || opr->args[2].bl_dir == C_DIR)
		error("Error three arguments instruction.", assm);
}

void	check_op_sti_arg(t_assm *assm, t_opr *opr)
{
	if (opr->count_args != 3)
		error("Error arguments instruction.", assm);
	if (opr->args[0].bl_reg == 0)
		error("Error first arguments instruction.", assm);
	if (opr->args[0].bl_ind == C_IND || opr->args[0].bl_dir == C_DIR)
		error("Error first arguments instruction.", assm);
	if (opr->args[1].bl_reg == 0 && opr->args[1].bl_dir == 0 &&
			opr->args[1].bl_ind == 0)
		error("Error second arguments instruction.", assm);
	if (opr->args[2].bl_reg == 0 && opr->args[2].bl_dir == 0)
		error("Error three arguments instruction.", assm);
	if (opr->args[2].bl_ind == C_IND)
		error("Error three arguments instruction.", assm);
}

unsigned char get_code_arg(t_opr *opr)
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

int		write_big_endian(int fd, void *bits, int len_bits)
{
	int	count_oct;

	count_oct = 0;
	while (len_bits > 0)
	{
		len_bits--;
		if ((count_oct += write(fd, (unsigned char *)bits + len_bits,
						1)) == -1)
			sys_err("Error write\n");
	}
	return (count_oct);
}
