
#include "../include/asm.h"

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
			opr->args[0].bl_dir == 0 )
		error("Error first arguments instruction.", assm);
	if (opr->args[1].bl_reg == 0 && opr->args[1].bl_ind == 0 &&
			opr->args[1].bl_dir == 0 )
		error("Error second arguments instruction.", assm);
	if (opr->args[2].bl_reg == 0)
		error("Error three arguments instruction.", assm);
	if (opr->args[2].bl_dir == C_DIR || opr->args[2].bl_ind == C_IND)
		error("Error three arguments instruction.", assm);
}

/*
** The function cheacks the arguments of 2 instruction: ldi, lldi.
*/

void	check_op_ldi_lldi_arg(t_assm *assm, t_opr *opr)
{
	if (opr->count_args != 3)
		error("Error arguments instruction.", assm);
	if (opr->args[0].bl_reg == 0 && opr->args[0].bl_ind == 0 &&
			opr->args[0].bl_dir == 0 )
		error("Error first arguments instruction.", assm);
	if (opr->args[1].bl_reg == 0 && opr->args[1].bl_dir == 0 )
		error("Error second arguments instruction.", assm);
	if (opr->args[2].bl_reg == 0)
		error("Error three arguments instruction.", assm);
	if (opr->args[1].bl_ind == C_IND)
		error("Error second arguments instruction.", assm);
	if (opr->args[2].bl_dir == C_DIR || opr->args[2].bl_ind == C_IND)
		error("Error three arguments instruction.", assm);
}

/*
** The function cheacks the arguments of 4 instruction: fork, lfork, zjmp, live.
*/

void	check_op_fork_lfork_zjmp_live_arg(t_assm *assm, t_opr *opr)
{
	if (opr->count_args != 1)
		error("Error arguments instruction.", assm);
	if (opr->args[0].bl_dir == 0)
		error("Error first arguments instruction.", assm);
	if (opr->args[0].bl_ind == C_IND || opr->args[0].bl_reg == C_REG)
		error("Error first arguments instruction.", assm);
	if (opr->args[1].bl_ind == C_IND || opr->args[1].bl_dir == C_DIR ||
			opr->args[1].bl_reg == C_REG)
		error("Error second arguments instruction.", assm);
	if (opr->args[2].bl_dir == C_DIR || opr->args[2].bl_ind == C_IND ||
			opr->args[2].bl_reg == C_REG)
		error("Error three arguments instruction.", assm);
}
