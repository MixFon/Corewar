/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:43:50 by widraugr          #+#    #+#             */
/*   Updated: 2020/02/24 12:06:31 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	working_instruction(t_assm *assm, char *line)
{
	while (*line)
	{
		if (*line == COMMENT_CHAR)
			return ;
		if (isprint_char(*line))
		{
			instruction(assm, line);
			return ;
		}
		line++;
	}
}

void	read_instruction(t_assm *assm)
{
	char	*line;

	line = NULL;
	while (get_next_line(assm->fd_s, &line))
	{
		assm->counter_line++;
		working_instruction(assm, line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

void	delete_list_gab(t_gab *gab)
{
	t_gab *temp;

	temp = gab;
	while (gab)
	{
		gab = gab->next;
		free(temp);
		temp = gab;
	}
}

void	delete_list(t_assm *assm)
{
	t_lbl *lbl;

	lbl = assm->lbl;
	while (assm->lbl)
	{
		assm->lbl = assm->lbl->next;
		ft_strdel(&lbl->name);
		delete_list_gab(lbl->gab);
		free(lbl);
		lbl = assm->lbl;
	}
	assm->lbl = NULL;
}
