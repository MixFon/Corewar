/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:30:44 by widraugr          #+#    #+#             */
/*   Updated: 2019/09/13 17:38:20 by widraugr         ###   ########.fr       */
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

void	open_file_s(t_assm *assm, char *name)
{
	assm->counter_line = 0;
	assm->counter_column = 0;
	assm->octet = 0;
	ft_memset(assm->head.prog_name, 0x00, PROG_NAME_LENGTH);
	ft_memset(assm->head.comment, 0x00, COMMENT_LENGTH);
	if(check_name(name))
		sys_err("Error file name.\n");
	if (!(assm->fd_s = open(name, O_RDONLY)))
		sys_err("File not opened.\n");
}

void	write_header(t_assm *assm)
{
	//assm->octet = 4;
	int		sector = 4;
	ft_putchar_fd(0x00, assm->fd_cor);
	ft_putchar_fd(0xea, assm->fd_cor);
	ft_putchar_fd(0x83, assm->fd_cor);
	ft_putchar_fd(0xf3, assm->fd_cor);
	write(assm->fd_cor, assm->head.prog_name, PROG_NAME_LENGTH);
	ft_putchar_fd(0x00, assm->fd_cor);
	ft_putchar_fd(0x00, assm->fd_cor);
	ft_putchar_fd(0x00, assm->fd_cor);
	ft_putchar_fd(0x00, assm->fd_cor);
	ft_putchar_fd(0x11, assm->fd_cor);
	ft_putchar_fd(0x11, assm->fd_cor);
	ft_putchar_fd(0x11, assm->fd_cor);
	ft_putchar_fd(0x11, assm->fd_cor);
	write(assm->fd_cor, assm->head.comment, COMMENT_LENGTH);
	ft_putchar_fd(0x00, assm->fd_cor);
	ft_putchar_fd(0x00, assm->fd_cor);
	ft_putchar_fd(0x00, assm->fd_cor);
	ft_putchar_fd(0x00, assm->fd_cor);
}

void	close_files(t_assm *assm)
{
	close(assm->fd_cor);
	close(assm->fd_s);
}

void	error(const char *msg, t_assm *assm)
{
	ft_printf("%s [%d:%d]\n",msg, assm->counter_line, assm->counter_column); 
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
			ft_putendl(assm->head.prog_name);
			return ;
		}
		assm->counter_column++;
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

void	working_comment(char *line, t_assm *assm)
{
	while (*line)
	{
		if (*line == '"')
		{
			read_comment_champion(line + 1, assm);	
			ft_putendl(assm->head.comment);
			return ;
		}
		assm->counter_column++;
		line++;
	}
	error("Error name", assm);

}

int		working_dot(t_assm *assm, char *line)
{
	if (!(ft_strncmp(line, NAME_CMD_STRING, 5)))
	{
		working_name(line + 5, assm);
		return (0);
	}
	else if (!(ft_strncmp(line, COMMENT_CMD_STRING, 8)))
	{
		working_comment(line + 8, assm);
		return (1);
	}
	else
		error("Syntax error at token" ,assm);
	return (1);
}

int		search_char(t_assm *assm, char *line)
{
	assm->counter_column = 0;
	while (*line)
	{
		if (*line == COMMENT_CHAR)
			return (0);
		if (*line == '.')
			return (working_dot(assm, line));
		if (ft_isprint(*line))
			error("Syntax error at token" ,assm);
		assm->counter_column++;
		line++;
	}
	return (0);
}

void	read_name_comment(t_assm *assm)
{
	char	*line;

	line = NULL;
	while (get_next_line(assm->fd_s, &line))
	{
		assm->counter_line++;
		if (search_char(assm, line))
		{
			ft_printf("1111 = {%s}\n", line);
			ft_strdel(&line);
			break ;
		}
		ft_printf("2222 = {%s}\n", line);
		ft_strdel(&line);
	}
	ft_printf("3333 = {%s}\n", line);
	ft_strdel(&line);
}

void	create_file_cor(t_assm *assm, char *name)
{
	char *name_cor;

	name_cor = dot_cor(name);
	if (!(assm->fd_cor = open(name_cor, O_WRONLY | O_TRUNC | O_CREAT,
					S_IREAD | S_IWRITE)))
		sys_err("Error create file.\n");
	ft_strdel(&name_cor);
}

void	instruction(t_assm *assm, char *line)
{
	char	*start;	

	start = line;
	while (*line)
	{
		if (*line == LABEL_CHAR)
		{
			ft_putendl("LABEL_CHAR");
			return ;
		}
		if (*line == DIRECT_CHAR || *line == ' ')
		{
			ft_putendl("DIRECT_CHAR and SPACE");
			return ;
		}
		line++;
	}
}

void	working_instruction(t_assm *assm, char *line)
{
	while (*line)
	{
		if (*line == COMMENT_CHAR)
			return ;
		if (ft_isprint(*line))
		{
			instruction(assm, line);
			return ;
		}
		assm->counter_column++;
		line++;
	}
}

void	read_instruction(t_assm *assm)
{
	char	*line;

	line = NULL;
	ft_putendl("||||			This is instruction!			||||");
	while (get_next_line(assm->fd_s, &line))
	{
		assm->counter_line++;
		working_instruction(assm, line);
		ft_printf("line = {%s}\n", line); 
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

int		main(int ac, char **av)
{
	t_assm	assm;
	if (ac != 2)
		sys_err("Error!\nUse ./asm namefile.s\n");
	open_file_s(&assm, av[1]);
	read_name_comment(&assm);
	read_instruction(&assm);
	create_file_cor(&assm, av[1]);
	write_header(&assm);
	close_files(&assm);
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

	if(lseek(assm->fd_cor, -4,0)==-1L)
		printf("Seek Error\n");
	ft_putchar_fd(0x22, assm->fd_cor);
	ft_putchar_fd(0x22, assm->fd_cor);
	ft_putchar_fd(0x22, assm->fd_cor);
	ft_putchar_fd(0x22, assm->fd_cor);
*/
