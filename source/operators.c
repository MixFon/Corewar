
/*
void	op_ld(t_assm *assm, t_opr *opr)
{
	unsigned char code_args;

	check_op_ld_lld_arg(assm, opr);
	code_args = get_code_arg(opr);
	ft_putchar_fd(0x02, assm->fd_cor);
	ft_putchar_fd(code_args, assm->fd_cor);
	assm->pos_glob += 2;
	opr->info.oct_start = 2;
	opr->info.size_dir = DIR_SIZE;
	opr->info.bl_code_arg = 1;
	all_arg(assm, &opr->info, &opr->args[0]);
	all_arg(assm, &opr->info, &opr->args[1]);
	ft_putendl("Operation ld finish.------------------------------------");
}

void	op_st(t_assm *assm, t_opr *opr)
{
	unsigned char code_args;

	check_op_st_arg(assm, opr);
	code_args = get_code_arg(opr);
	ft_putchar_fd(0x03, assm->fd_cor);
	ft_putchar_fd(code_args, assm->fd_cor);
	assm->pos_glob += 2;
	opr->info.oct_start = 2;
	opr->info.size_dir = DIR_SIZE;
	opr->info.bl_code_arg = 1;
	all_arg(assm, &opr->info, &opr->args[0]);
	all_arg(assm, &opr->info, &opr->args[1]);
	ft_putendl("Operation st finish.------------------------------------");
}

void	op_or(t_assm *assm, t_opr *opr)
{
	unsigned char code_args;

	check_op_or_xor_and_arg(assm, opr);
	code_args = get_code_arg(opr);
	ft_putchar_fd(0x07, assm->fd_cor);
	ft_putchar_fd(code_args, assm->fd_cor);
	assm->pos_glob += 2;
	opr->info.oct_start = 2;
	opr->info.size_dir = DIR_SIZE;
	opr->info.bl_code_arg = 1;
	all_arg(assm, &opr->info, &opr->args[0]);
	all_arg(assm, &opr->info, &opr->args[1]);
	all_arg(assm, &opr->info, &opr->args[2]);
	ft_putendl("Operation or finish.------------------------------------");
}

void	op_lldi(t_assm *assm, t_opr *opr)
{
	unsigned char code_args;

	check_op_ldi_lldi_arg(assm, opr);
	code_args = get_code_arg(opr);
	ft_putchar_fd(0x0e, assm->fd_cor);
	ft_putchar_fd(code_args, assm->fd_cor);
	assm->pos_glob += 2;
	opr->info.oct_start = 2;
	opr->info.size_dir = 2;
	opr->info.bl_code_arg = 1;
	all_arg(assm, &opr->info, &opr->args[0]);
	all_arg(assm, &opr->info, &opr->args[1]);
	all_arg(assm, &opr->info, &opr->args[2]);
	ft_putendl("Operation lldi finish.------------------------------------");
}

void	op_fork(t_assm *assm, t_opr *opr)
{
	unsigned char code_args;

	//check_op_fork_lfork_zjmp_live_arg(assm, opr);
	code_args = get_code_arg(opr);
	ft_putchar_fd(0x0c, assm->fd_cor);
	assm->pos_glob += 1;
	opr->info.oct_start = 1;
	opr->info.size_dir = 2;
	opr->info.bl_code_arg = 0;
	all_arg(assm, &opr->info, &opr->args[0]);
	ft_putendl("Operation fork finish.------------------------------------");
}

void	op_zjmp(t_assm *assm, t_opr *opr)
{
	unsigned char code_args;

	//check_op_fork_lfork_zjmp_live_arg(assm, opr);
	code_args = get_code_arg(opr);
	ft_putchar_fd(0x09, assm->fd_cor);
	assm->pos_glob += 1;
	opr->info.oct_start = 1;
	opr->info.size_dir = 2;
	opr->info.bl_code_arg = 0;
	all_arg(assm, &opr->info, &opr->args[0]);
	ft_putendl("Operation zjmp finish.------------------------------------");
}

void	op_live(t_assm *assm, t_opr *opr)
{
	unsigned char code_args;

	//check_op_fork_lfork_zjmp_live_arg(assm, opr);
	code_args = get_code_arg(opr);
	ft_putchar_fd(0x01, assm->fd_cor);
	assm->pos_glob += 1;
	opr->info.oct_start = 1;
	opr->info.size_dir = DIR_SIZE;
	opr->info.bl_code_arg = 0;
	all_arg(assm, &opr->info, &opr->args[0]);
	ft_putendl("Operation live finish.------------------------------------");
}

void	op_lfork(t_assm *assm, t_opr *opr)
{
	unsigned char code_args;

	//check_op_fork_lfork_zjmp_live_arg(assm, opr);
	code_args = get_code_arg(opr);
	ft_putchar_fd(0x0f, assm->fd_cor);
	assm->pos_glob += 1;
	opr->info.oct_start = 1;
	opr->info.size_dir = 2;
	opr->info.bl_code_arg = 0;
	all_arg(assm, &opr->info, &opr->args[0]);
	ft_putendl("Operation lfork finish.------------------------------------");
}

void	op_aff(t_assm *assm, t_opr *opr)
{
	unsigned char code_args;

	check_op_aff_arg(assm, opr);
	code_args = get_code_arg(opr);
	ft_putchar_fd(0x10, assm->fd_cor);
	ft_putchar_fd(code_args, assm->fd_cor);
	assm->pos_glob += 2;
	opr->info.oct_start = 2;
	opr->info.size_dir = DIR_SIZE;
	opr->info.bl_code_arg = 1;
	all_arg(assm, &opr->info, &opr->args[0]);
	ft_putendl("Operation aff finish.------------------------------------");
}

void	op_add(t_assm *assm, t_opr *opr)
{
	unsigned char code_args;

	check_op_add_sub_arg(assm, opr);
	code_args = get_code_arg(opr);
	ft_putchar_fd(0x04, assm->fd_cor);
	ft_putchar_fd(code_args, assm->fd_cor);
	assm->pos_glob += 2;
	opr->info.oct_start = 2;
	opr->info.size_dir = DIR_SIZE;
	opr->info.bl_code_arg = 1;
	all_arg(assm, &opr->info, &opr->args[0]);
	all_arg(assm, &opr->info, &opr->args[1]);
	all_arg(assm, &opr->info, &opr->args[2]);
	ft_putendl("Operation add finish.------------------------------------");
}

void	op_sub(t_assm *assm, t_opr *opr)
{
	unsigned char code_args;

	check_op_add_sub_arg(assm, opr);
	code_args = get_code_arg(opr);
	ft_putchar_fd(0x05, assm->fd_cor);
	ft_putchar_fd(code_args, assm->fd_cor);
	assm->pos_glob += 2;
	opr->info.oct_start = 2;
	opr->info.size_dir = DIR_SIZE;
	opr->info.bl_code_arg = 1;
	all_arg(assm, &opr->info, &opr->args[0]);
	all_arg(assm, &opr->info, &opr->args[1]);
	all_arg(assm, &opr->info, &opr->args[2]);
	ft_putendl("Operation sub finish.------------------------------------");
}

void	op_and(t_assm *assm, t_opr *opr)
{
	unsigned char code_args;

	check_op_or_xor_and_arg(assm, opr);
	code_args = get_code_arg(opr);
	ft_putchar_fd(0x06, assm->fd_cor);
	ft_putchar_fd(code_args, assm->fd_cor);
	assm->pos_glob += 2;
	opr->info.oct_start = 2;
	opr->info.size_dir = DIR_SIZE;
	opr->info.bl_code_arg = 1;
	all_arg(assm, &opr->info, &opr->args[0]);
	all_arg(assm, &opr->info, &opr->args[1]);
	all_arg(assm, &opr->info, &opr->args[2]);
	ft_putendl("Operation and finish.------------------------------------");
}

void	op_xor(t_assm *assm, t_opr *opr)
{
	unsigned char code_args;

	check_op_or_xor_and_arg(assm, opr);
	code_args = get_code_arg(opr);
	ft_putchar_fd(0x08, assm->fd_cor);
	ft_putchar_fd(code_args, assm->fd_cor);
	assm->pos_glob += 2;
	opr->info.oct_start = 2;
	opr->info.size_dir = DIR_SIZE;
	opr->info.bl_code_arg = 1;
	all_arg(assm, &opr->info, &opr->args[0]);
	all_arg(assm, &opr->info, &opr->args[1]);
	all_arg(assm, &opr->info, &opr->args[2]);
	ft_putendl("Operation xor finish.------------------------------------");
}

void	op_ldi(t_assm *assm, t_opr *opr)
{
	unsigned char code_args;

	check_op_ldi_lldi_arg(assm, opr);
	code_args = get_code_arg(opr);
	ft_putchar_fd(0x0a, assm->fd_cor);
	ft_putchar_fd(code_args, assm->fd_cor);
	assm->pos_glob += 2;
	opr->info.oct_start = 2;
	opr->info.size_dir = 2;
	opr->info.bl_code_arg = 1;
	all_arg(assm, &opr->info, &opr->args[0]);
	all_arg(assm, &opr->info, &opr->args[1]);
	all_arg(assm, &opr->info, &opr->args[2]);
	ft_putendl("Operation ldi finish.------------------------------------");
}

void	op_lld(t_assm *assm, t_opr *opr)
{
	unsigned char code_args;

	check_op_ld_lld_arg(assm, opr);
	code_args = get_code_arg(opr);
	ft_putchar_fd(0x0d, assm->fd_cor);
	ft_putchar_fd(code_args, assm->fd_cor);
	assm->pos_glob += 2;
	opr->info.oct_start = 2;
	opr->info.size_dir = DIR_SIZE;
	opr->info.bl_code_arg = 1;
	all_arg(assm, &opr->info, &opr->args[0]);
	all_arg(assm, &opr->info, &opr->args[1]);
	ft_putendl("Operation lld finish.------------------------------------");
}

void	op_sti(t_assm *assm, t_opr *opr)
{
	unsigned char code_args;

	check_op_sti_arg(assm, opr);
	code_args = get_code_arg(opr);
	ft_putchar_fd(0x0b, assm->fd_cor);
	ft_putchar_fd(code_args, assm->fd_cor);
	assm->pos_glob += 2;
	opr->info.oct_start = 2;
	opr->info.size_dir = 2;
	opr->info.bl_code_arg = 1;
	all_arg(assm, &opr->info, &opr->args[0]);
	all_arg(assm, &opr->info, &opr->args[1]);
	all_arg(assm, &opr->info, &opr->args[2]);
	ft_putendl("Operation sti finish.------------------------------------");
}
*/

