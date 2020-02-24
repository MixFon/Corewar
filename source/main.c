/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:30:44 by widraugr          #+#    #+#             */
/*   Updated: 2020/02/24 13:31:03 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int		get_figur_write(size_t position, t_gab *gab)
{
	int	num;

	num = position - gab->pos_write + gab->oct_start;
	return (num);
}

void	write_in_position(t_assm *assm, t_lbl *lbl, int fd_cor)
{
	t_gab	*gab;
	int		b;

	gab = lbl->gab;
	while (gab)
	{
		if (lseek(fd_cor, gab->pos_write, SEEK_SET) == -1L)
			sys_err("Seek Error\n");
		b = get_figur_write(lbl->position, gab);
		to_plase_code_str(assm, gab->pos_write, &b, gab->oct_count);
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
			sys_err("Not lable Error\n");
		write_in_position(assm, lbl, assm->fd_cor);
		lbl = lbl->next;
	}
}

void	write_bot_size(t_assm *assm)
{
	size_t bot_size;

	bot_size = assm->pos_glob - LEN_HEAD;
	if (lseek(assm->fd_cor, 8 + PROG_NAME_LENGTH, SEEK_SET) == -1L)
		sys_err("Seek Error\n");
	to_plase_code_str(assm, 8 + PROG_NAME_LENGTH, &bot_size, 4);
}

int		main(int ac, char **av)
{
	t_assm	assm;

	if (ac != 2)
		sys_err("Error!\nUse ./asm namefile.s\n");
	init(&assm);
	open_file_s(&assm, av[1]);
	read_name_comment(&assm);
	write_header(&assm);
	read_instruction(&assm);
	write_bot_size(&assm);
	weite_figur_lable(&assm);
	write_code_str_to_file(&assm, av[1]);
	delete_code_str(&assm);
	delete_list(&assm);
	close_files(&assm);
	ft_putendl("Done!");
	return (0);
}
