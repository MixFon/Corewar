/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_comment_champ.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:20:20 by widraugr          #+#    #+#             */
/*   Updated: 2020/02/25 13:23:29 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	close_files(t_assm *assm)
{
	ft_strdel(&assm->name_cor);
	close(assm->fd_cor);
	close(assm->fd_s);
}

void	print_liest(t_assm *assm)
{
	t_lbl *lbl;	
	t_gab *gab;	
	
	lbl = assm->lbl;
	ft_putstr("lbl->name ");
	ft_putendl(lbl->name);
	while (lbl)
	{
		gab = lbl->gab;
		while (gab)
		{
			ft_putstr("pos_write ");
			ft_putnbr_fd(gab->pos_write, 1);
			ft_putstr("\n");
			//ft_putendl(lbl->name);
			gab = gab->next;
		}
		lbl = lbl->next;
	}
	
}

void	error(const char *msg, t_assm *assm)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(" Line [", 2);
	ft_putnbr_fd(assm->counter_line, 2);
	ft_putstr_fd("].\n", 2);
	exit(0);
}

void	read_name_champion(char *line, t_assm *assm)
{
	static int	i = -1;
	char		*temp;

	while (*line)
	{
		if (*line == '"' || i >= PROG_NAME_LENGTH)
			return ;
		assm->head.prog_name[++i] = *line;
		line++;
	}
	assm->head.prog_name[++i] = '\n';
	get_next_line(assm->fd_s, &temp);
	assm->counter_line++;
	read_name_champion(temp, assm);
	ft_strdel(&temp);
}

void	working_name(char *line, t_assm *assm)
{
	while (*line)
	{
		if (*line == '"')
		{
			read_name_champion(line + 1, assm);
			return ;
		}
		line++;
	}
	error("Error name", assm);
}

void	read_comment_champion(char *line, t_assm *assm)
{
	static int	i = -1;
	char		*temp;

	while (*line)
	{
		if (*line == '"' || i >= COMMENT_LENGTH)
			return ;
		assm->head.comment[++i] = *line;
		line++;
	}
	assm->head.comment[++i] = '\n';
	get_next_line(assm->fd_s, &temp);
	assm->counter_line++;
	read_comment_champion(temp, assm);
	ft_strdel(&temp);
}
