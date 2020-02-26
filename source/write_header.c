/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:17:41 by widraugr          #+#    #+#             */
/*   Updated: 2020/02/26 10:26:21 by widraugr         ###   ########.fr       */
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
	int		i;

	i = -1;
	len = ft_strlen(name);
	dot_cor = ft_strnew(len + 2);
	while (++i < (int)len - 1)
		dot_cor[i] = name[i];
	ft_strcat(dot_cor, "cor");
	return (dot_cor);
}

void	init(t_assm *assm)
{
	assm->counter_line = 0;
	assm->len_str = 0;
	assm->pos_glob = LEN_HEAD;
	assm->lbl = NULL;
	assm->size_str_malloc = LEN_MALLOK;
	ft_memset(assm->head.prog_name, 0x00, PROG_NAME_LENGTH);
	ft_memset(assm->head.comment, 0x00, COMMENT_LENGTH);
	if (!(assm->code_str = (unsigned char *)malloc(sizeof(unsigned char) *
					assm->size_str_malloc)))
		sys_err("Error malloc.");
	ft_memset(assm->code_str, 0x00, assm->size_str_malloc);
}

void	open_file_s(t_assm *assm, char *name)
{
	char *tmp;

	if (!((tmp = ft_strstr(name, ".s")) && (name - tmp) != 0
			&& ft_strlen(tmp) == 2))
		sys_err("Error file name.\n");
	if ((assm->fd_s = open(name, O_RDONLY)) == -1)
		sys_err("File not opened.\n");
}

void	write_header(t_assm *assm)
{
	int		sector;

	sector = COREWAR_EXEC_MAGIC;
	write_big_endian(assm, assm->fd_cor, &sector, 4);
	sector = 0x00;
	write_prog_name_and_comment(assm, assm->head.prog_name, PROG_NAME_LENGTH);
	write_big_endian(assm, assm->fd_cor, &sector, 4);
	write_big_endian(assm, assm->fd_cor, &sector, 4);
	write_prog_name_and_comment(assm, assm->head.comment, COMMENT_LENGTH);
	write_big_endian(assm, assm->fd_cor, &sector, 4);
}
