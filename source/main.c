/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:30:44 by widraugr          #+#    #+#             */
/*   Updated: 2020/02/21 21:53:49 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int		get_figur_write(size_t position, t_gab *gab)
{
	int	num;

	num = position - gab->pos_write + gab->oct_start;
	return (num);
}

void	write_in_position(t_lbl *lbl, int fd_cor)
{
	t_gab	*gab;
	int		b;

	gab = lbl->gab;
	while (gab)
	{
		if (lseek(fd_cor, gab->pos_write, SEEK_SET) == -1L)
			sys_err("Seek Error\n");
		b = get_figur_write(lbl->position, gab);
		ft_printf("code_str [%x]", code_str[len_str]);
		ft_printf("\n[%x]\n", b);
		//write_big_endian(fd_cor, &b, gab->oct_count);
		to_plase_code_str(gab->pos_write, &b, gab->oct_count);
		gab = gab->next;
	}
}

void	weite_figur_lable(t_assm *assm)
{
	t_lbl *lbl;

	lbl = assm->lbl;
	while (lbl)
	{
		if (lbl->bl == 0)
			sys_err_rm(assm, "Not lable Error\n");
		write_in_position(lbl, assm->fd_cor);
		lbl = lbl->next;
	}
}

void	write_bot_size(t_assm *assm)
{
	size_t bot_size;

	bot_size = assm->pos_glob - LEN_HEAD;
	if (lseek(assm->fd_cor, 8 + PROG_NAME_LENGTH, SEEK_SET) == -1L)
		sys_err("Seek Error\n");
	//первый - куда пишем, второй - что пришем, третий - сколько байт пишем
	to_plase_code_str(8 + PROG_NAME_LENGTH, &bot_size, 4);
	//write_big_endian(assm->fd_cor, &bot_size, 4);
}

int		main(int ac, char **av)
{
	t_assm	assm;

	len_str = 0;
	if (ac != 2)
		sys_err("Error!\nUse ./asm namefile.s\n");
	open_file_s(&assm, av[1]);
	create_file_cor(&assm, av[1]);
	read_name_comment(&assm);
	write_header(&assm);
	read_instruction(&assm);
	write_bot_size(&assm);
	weite_figur_lable(&assm);
	write_code_str_to_file();
	delete_list(&assm);
	close_files(&assm);
	ft_putendl("Done!");
	return (0);
}
