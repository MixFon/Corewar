/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:30:44 by widraugr          #+#    #+#             */
/*   Updated: 2019/09/10 14:41:49 by widraugr         ###   ########.fr       */
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
	ft_memccpy(dot_cor, name, '.', len + 2);
	ft_strcat(dot_cor, "cor");
	return (dot_cor);
}

void	create_file(t_assm *assm, char *name)
{
	char *name_cor;

	if(check_name(name))
		sys_err("Error file name.\n");
	name_cor = dot_cor(name);
	if (!(assm->fd = open(name_cor, O_WRONLY | O_TRUNC | O_CREAT,
					S_IREAD | S_IWRITE)))
		sys_err("Error create file.\n");
	ft_strdel(&name_cor);
}

void	write_magic_header(t_assm *assm)
{
	assm->octet = 4;
	ft_putchar_fd(0x00, assm->fd);
	ft_putchar_fd(0xea, assm->fd);
	ft_putchar_fd(0x83, assm->fd);
	ft_putchar_fd(0xf3, assm->fd);
}

void	close_file(t_assm *assm)
{
	close(assm->fd);
}

int		main(int ac, char **av)
{
	t_assm	assm;
	if (ac != 2)
		sys_err("Error!\nUse ./asm namefile.s\n");
	create_file(&assm, av[1]);
	write_magic_header(&assm);
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
