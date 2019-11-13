/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:17:41 by widraugr          #+#    #+#             */
/*   Updated: 2019/11/13 18:58:35 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int		check_name(char *name)
{
	int	i;
	int	bl;

	i = -1;
	bl = 0;
	while (name[++i])
		if (name[i] == '.')
			bl++;
	if (bl != 1)
		return (1);
	if (name[i - 1] == 's' && name[i - 2] == '.')
		return (0);
	return (1);
}

char	*dot_cor(char *name)
{
	char	*dot_cor;
	size_t	len;

	len = ft_strlen(name);
	dot_cor = ft_strnew(len + 2);
	ft_memccpy(dot_cor, name, '.', len);
	ft_strcat(dot_cor, "cor");
	return (dot_cor);
}

void	init(t_assm *assm)
{
	assm->counter_line = 0;
	assm->pos_glob = LEN_HEAD;
	assm->lbl = NULL;
	ft_memset(assm->head.prog_name, 0x00, PROG_NAME_LENGTH);
	ft_memset(assm->head.comment, 0x00, COMMENT_LENGTH);
}

void	open_file_s(t_assm *assm, char *name)
{
	char *tmp;

	init(assm);
	if (!((tmp = ft_strstr(name, ".s")) && (name - tmp) != 0
			&& ft_strlen(tmp) == 2))
		sys_err("Error file name.\n");
	if (!(assm->fd_s = open(name, O_RDONLY)))
		sys_err("File not opened.\n");
}

void	write_header(t_assm *assm)
{
	int		sector;

	sector = COREWAR_EXEC_MAGIC;
	write_big_endian(assm->fd_cor, &sector, 4);
	sector = 0x00;
	write(assm->fd_cor, assm->head.prog_name, PROG_NAME_LENGTH);
	write_big_endian(assm->fd_cor, &sector, 4);
	write_big_endian(assm->fd_cor, &sector, 4);
	write(assm->fd_cor, assm->head.comment, COMMENT_LENGTH);
	write_big_endian(assm->fd_cor, &sector, 4);
}
