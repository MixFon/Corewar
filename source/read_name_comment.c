/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_name_comment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:23:59 by widraugr          #+#    #+#             */
/*   Updated: 2020/02/26 10:24:41 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	working_comment(char *line, t_assm *assm)
{
	while (*line)
	{
		if (*line == '"')
		{
			read_comment_champion(line + 1, assm);
			return ;
		}
		line++;
	}
	error("Error name", assm);
}

int		working_dot(t_assm *assm, char *line, int *bl_name_comm)
{
	if (!(ft_strncmp(line, NAME_CMD_STRING, 5)))
	{
		working_name(line + 5, assm);
		(*bl_name_comm)++;
		return (0);
	}
	else if (!(ft_strncmp(line, COMMENT_CMD_STRING, 8)))
	{
		working_comment(line + 8, assm);
		(*bl_name_comm)++;
		return (1);
	}
	else
		error("Lexical error.", assm);
	return (1);
}

int		search_char(t_assm *assm, char *line, int *bl_name_comm)
{
	while (*line)
	{
		if (*line == COMMENT_CHAR || *line == EXTRA_COMMENT_CHAR)
			return (0);
		if (*line == '.')
			return (working_dot(assm, line, bl_name_comm));
		if (ft_isprint(*line))
			error("Syntax error at token", assm);
		line++;
	}
	return (0);
}

void	read_name_comment(t_assm *assm)
{
	char	*line;
	int		bl_name_comm;

	line = NULL;
	bl_name_comm = 0;
	while (get_next_line(assm->fd_s, &line))
	{
		assm->counter_line++;
		search_char(assm, line, &bl_name_comm);
		if (bl_name_comm == 2)
		{
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
}
