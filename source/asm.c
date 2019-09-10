/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:30:44 by widraugr          #+#    #+#             */
/*   Updated: 2019/09/10 17:29:24 by widraugr         ###   ########.fr       */
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

void	create_file(t_assm *assm, char *name)
{
	char *name_cor;

	if(check_name(name))
		sys_err("Error file name.\n");
	if (!(assm->fd_s = open(name, O_RDONLY)))
		sys_err("File not opened.\n");
	name_cor = dot_cor(name);
	if (!(assm->fd_cor = open(name_cor, O_WRONLY | O_TRUNC | O_CREAT,
					S_IREAD | S_IWRITE)))
		sys_err("Error create file.\n");
	ft_strdel(&name_cor);
}

void	write_magic_header(t_assm *assm)
{
	assm->octet = 4;
	ft_putchar_fd(0x00, assm->fd_cor);
	ft_putchar_fd(0xea, assm->fd_cor);
	ft_putchar_fd(0x83, assm->fd_cor);
	ft_putchar_fd(0xf3, assm->fd_cor);
}

void	close_file(t_assm *assm)
{
	close(assm->fd_cor);
	close(assm->fd_s);
}

void	write_name_comment(t_assm *assm)
{
	char *line;

	line = NULL;
	while (get_next_line(assm->fd_s, &line))
	{

		ft_putendl(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

int		main(int ac, char **av)
{
	t_assm	assm;
	if (ac != 2)
		sys_err("Error!\nUse ./asm namefile.s\n");
	create_file(&assm, av[1]);
	write_magic_header(&assm);
	write_name_comment(&assm);
	close_file(&assm);
	return (0);
}
/*
	int		fd_new;

	fd_new = open("temp.cor", O_WRONLY | O_TRUNC | O_CREAT, S_IREAD | S_IWRITE);
	ft_printf("fd = {%d}\n", fd_new);
	ft_putchar_fd(0x00, fd_new);
	ft_putchar_fd(0xea, fd_new);
	ft_putchar_fd(0x83, fd_new);
	ft_putchar_fd(0xf3, fd_new);
	ft_putstr_fd("Tching tching(Intercepteur), Bouh!Bouh!(bruits d'anti-jeu)", fd_new);
	close(fd_new);
*/
