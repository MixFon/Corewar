/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_comment_champ.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:20:20 by widraugr          #+#    #+#             */
/*   Updated: 2020/03/02 10:50:42 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	skip_tail_name_commet(t_assm *assm, char *line)
{
	while (*line)
	{
		if (*line == COMMENT_CHAR || *line == EXTRA_COMMENT_CHAR)
			return ;
		if (*line != ' ' && *line != '\t')
			error("Error name", assm);
		line++;
	}
}

void	close_files(t_assm *assm)
{
	ft_strdel(&assm->name_cor);
	close(assm->fd_cor);
	close(assm->fd_s);
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
		{
			skip_tail_name_commet(assm, line + 1);
			return ;
		}
		assm->head.prog_name[++i] = *line;
		line++;
	}
	assm->head.prog_name[++i] = '\n';
	if (get_next_line(assm->fd_s, &temp) == 0)
		error("Error name champion.", assm);
	assm->counter_line++;
	read_name_champion(temp, assm);
	ft_strdel(&temp);
}

void	read_comment_champion(char *line, t_assm *assm)
{
	static int	i = -1;
	char		*temp;

	while (*line)
	{
		if (*line == '"' || i >= COMMENT_LENGTH)
		{
			skip_tail_name_commet(assm, line + 1);
			return ;
		}
		assm->head.comment[++i] = *line;
		line++;
	}
	assm->head.comment[++i] = '\n';
	if (get_next_line(assm->fd_s, &temp) == 0)
		error("Error comment champion.", assm);
	assm->counter_line++;
	read_comment_champion(temp, assm);
	ft_strdel(&temp);
}
