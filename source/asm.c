/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:30:44 by widraugr          #+#    #+#             */
/*   Updated: 2019/09/19 16:21:06 by widraugr         ###   ########.fr       */
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
	assm->counter_column = 1;
	assm->pos_glob = 0;
	assm->lbl = NULL;
	ft_memset(assm->head.prog_name, 0x00, PROG_NAME_LENGTH);
	ft_memset(assm->head.comment, 0x00, COMMENT_LENGTH);
}

void	open_file_s(t_assm *assm, char *name)
{
	init(assm);
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
	assm->counter_column = 1;
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

int		islablechar(char c)
{
	if ((c >= 97 && c <= 122) || (c >= 48 && c <= 57) || c == 95)
		return (1);
	return (0);
}

void	check_lable(t_assm *assm, char *start, char *line)
{
	while (start < line)
	{
		if (!islablechar(*start))
		{
			assm->counter_column -= line - start;
			error("Error lable char." ,assm);
		}
		start++;
	}
}

t_lbl	*create_lable(char *start, char *end)
{
	t_lbl	*new;
	int		len;

	len = end - start;
	if (!(new = (t_lbl*)malloc(sizeof(t_lbl))))
		sys_err("Eror malloc\n");
	if (!(new->name = ft_strnew(len)))
		sys_err("Eror malloc\n");
	ft_strncpy(new->name, start, len);
	ft_printf("\nNew lbl name = {%s}\n", new->name);
	new->next = NULL;
	new->bl = 0;
	new->gab = NULL;
	return (new);
}

int		search_dub_lable(t_lbl *lbl, char *start, char *line)
{
	t_lbl	*temp;
	int		len;
	int		len_str;
	int		diff;

	temp = lbl;
	diff = line - start;
	while (lbl)
	{
		len = ft_strlen(lbl->name);
		len_str = (len > diff ? len : diff);
		if (!(ft_strncmp(start, lbl->name, len_str)))
		{
			if (lbl->bl == 0)
				lbl->bl = 1;
			return (1);
		}
		lbl = lbl->next;
	}
	return (0);
}

void	add_lable_list(t_assm *assm, char *start, char *line)
{
	t_lbl *lbl;

	if (!assm->lbl)
	{
		assm->lbl = create_lable(start, line);
		return ;
	}
	if (search_dub_lable(assm->lbl, start, line))
		return ;
	lbl = create_lable(start, line);
	lbl->next = assm->lbl;
	assm->lbl = lbl;
}

void	print_gab_list(t_gab *gab)
{
	while (gab != NULL)
	{
		ft_printf("\tpos_write = {%d} oct_count = {%d} oct_start = [%d]\n",
			gab->pos_write, gab->oct_count, gab->oct_start);
		gab = gab->next;
	}
}

void	print_list(t_lbl *lbl)
{
	ft_putendl("List:");
	while (lbl)
	{	
		ft_printf("lable = {%s} position = {%d} bl = [%d]\n", lbl->name, lbl->position, lbl->bl);
		print_gab_list(lbl->gab);
		lbl = lbl->next;
	}
}

void	working_lable(t_assm *assm, char *start, char *line)
{
	//write(1, start, line - start);
	check_lable(assm, start, line);
	add_lable_list(assm, start, line);
	assm->lbl->bl = 1;
	assm->lbl->position = assm->pos_glob;
	print_list(assm->lbl);
	working_instruction(assm, line + 1);
}

int		isdigit_per_colon(int c)
{
	if ((c <= 58 && c >= 48) || c == 37)
		return (1);
	return (0);
}

void	init_arg(t_arg *arg)
{
	arg->dir = 0;
	arg->ind = 0;
	arg->reg = 0;
	arg->lable = NULL;
	arg->bl_ind = 0;
	arg->bl_dir = 0;
	arg->bl_reg = 0;
}

void	init_opt(t_opr *opr)
{
	init_arg(&opr->fir);
	init_arg(&opr->sec);
	init_arg(&opr->three);
	opr->count_args = 1;
	opr->info.size_dir = 0;
	opr->info.bl_code_arg = 0;
}

char	*create_lable_arg(char *start, t_arg *arg)
{
	char *temp;

	temp = start;
	while(islablechar(*start) && *start != '\0')
		start++;
	arg->lable = ft_strnew(start - temp);
	ft_strncpy(arg->lable, temp, start - temp);
	return (start);
}

char	*read_ind_adg(t_assm *assm, t_arg *arg, char *start)
{
	arg->bl_ind = C_IND;
	if (*start == ':')
	{
		start = create_lable_arg((start + 1), arg);
		return (start);
	}
	arg->ind = ft_atoi(start);
	while (ft_isdigit(*start) || *start == '-')
		start++;
	//ft_printf("start = !{%s}! fir.ind [%d]\n", start, opr->fir.ind);
	return (start);
}

char	*read_reg_adg(t_arg *arg, char *start)
{
	if (!ft_isdigit(*start))
		sys_err("Error registr.\n");
	arg->bl_reg = C_REG;
	arg->reg = ft_atoi(start);
	if (arg->reg >= REG_NUMBER || arg->reg <= 0)
		sys_err("Error number registr\n");
	while (ft_isdigit(*start))
		start++;
	//ft_printf("start = !{%s}! fir.reg [%d]\n", start, opr->fir.reg);
	return (start);
}

char	*read_dir_adg(t_assm *assm, t_arg *arg, char *start)
{
	start++;
	arg->bl_dir = C_DIR;
	if (ft_isdigit(*start) || *start == '-')
		arg->dir = ft_atoi(start);
	else if (*start == ':')
		start = create_lable_arg(start + 1, arg);
	while (ft_isdigit(*start) || *start == '-')
		start++;
	//ft_printf("start = !{%s}! fir.reg [%d]\n", start, opr->fir.reg);
	return (start);
}

void	print_opr(t_opr *opr)
{
	ft_printf("Count args = {%d}\n", opr->count_args);
	ft_printf("Arg1 dir {%d} ind  [%d]  reg  [%d] bl_ind [%d] bl_dir [%d] bl_reg [%d] lable {%s}\n",
			opr->fir.dir, opr->fir.ind, opr->fir.reg, opr->fir.bl_ind, opr->fir.bl_dir, opr->fir.bl_reg, opr->fir.lable);
	ft_printf("Arg2 dir {%d} ind  [%d]  reg  [%d] bl_ind [%d] bl_dir [%d] bl_reg [%d] lable {%s}\n",
			opr->sec.dir, opr->sec.ind, opr->sec.reg, opr->sec.bl_ind, opr->sec.bl_dir, opr->sec.bl_reg, opr->sec.lable);
	ft_printf("Arg3 dir {%d} ind  [%d]  reg  [%d] bl_ind [%d] bl_dir [%d] bl_reg [%d] lable {%s}\n",
			opr->three.dir, opr->three.ind, opr->three.reg, opr->three.bl_ind, opr->three.bl_dir, opr->three.bl_reg, opr->three.lable);
}

char	*read_arguments(t_assm *assm, t_arg *arg, char *start)
{
	while (*start)
	{
		if (ft_isdigit(*start) || *start == ':'|| *start == '-')
			start = read_ind_adg(assm, arg, start);
		if (*start == '%')
			start = read_dir_adg(assm, arg, start);
		if (*start == 'r')
			start = read_reg_adg(arg, start + 1);
		if (ft_isalpha(*start))
			error("Error argument", assm);
		if (*start == ',')
			return (start);
		if (*start == '\0')
			continue ;
		start++;
	}
	return (start);
}

t_opr	*get_arg_opr(t_assm *assm, char *start)
{
	t_opr *opr;

	if(!(opr = (t_opr *)malloc(sizeof(t_opr))))
		sys_err("Error malloc\n");
	init_opt(opr);
	start = read_arguments(assm, &opr->fir, start);
	if (*start == ',')
	{
		start++;
		opr->count_args++;
	}
	start = read_arguments(assm, &opr->sec, start);
	if (*start == ',')
	{
		start++;
		opr->count_args++;
	}
	start = read_arguments(assm, &opr->three, start);
	print_opr(opr);
	//error("Error operator.", assm);
	return (opr);
}

void	cheak_op_ld_arg(t_assm *assm, t_opr *opr)
{
	if (opr->count_args != 2)
		error("Error arguments opiration.", assm);
	if (opr->fir.bl_reg == C_REG)
		error("Error first arguments opiration.", assm);
	if (opr->sec.bl_dir == C_DIR || opr->sec.bl_ind == C_IND)
		error("Error second arguments opiration.", assm);
	if (opr->three.bl_dir == C_DIR || opr->three.bl_ind == C_IND || opr->three.bl_reg == C_REG)
		error("Error three arguments opiration.", assm);
}

unsigned char get_code_arg(t_opr *opr)
{
	unsigned char code;

	code = opr->fir.bl_ind | opr->fir.bl_dir | opr->fir.bl_reg;
	ft_printf("code = {%#x}\n", code);
	code = code << 2;	
	ft_printf("code = {%#x}\n", code);
	code = code | opr->sec.bl_ind | opr->sec.bl_dir | opr->sec.bl_reg;
	ft_printf("code = {%#x}\n", code);
	code = code << 2;	
	ft_printf("code = {%#x}\n", code);
	code = code | opr->three.bl_ind | opr->three.bl_dir | opr->three.bl_reg;
	ft_printf("code = {%#x}\n", code);
	code = code << 2;	
	ft_printf("code = {%#x}\n", code);
	return (code);
}

int		write_big_endian(int fd, void *bits, int len_bits)
{
	int	count_oct;

	count_oct = 0;
	while (len_bits > 0)
	{
		len_bits--;
		if ((count_oct += write(fd, (unsigned char *)bits + len_bits, 1)) == -1)
			sys_err("Error write\n");
	}
	ft_printf("Write count oct {%d}\n", count_oct);
	return (count_oct);
}

t_lbl	*get_lbl(t_lbl **lbl, char *lable)
{
	t_lbl *temp;

	temp = *lbl;
	while(temp)
	{
		if (!ft_strcmp(temp->name, lable))
		{
			ft_printf("Find lable name is {%s}\n", temp->name);
			return (temp);	
		}
		temp = temp->next;
	}
	temp = create_lable(lable, lable + ft_strlen(lable));	
	temp->next = *lbl;
	*lbl = temp;
	(*lbl)->bl = 0;
	(*lbl)->position = 0;
	ft_printf("Lable {%s} not find\n", lable);
	ft_printf("Create {%s}\n", lable);
	return (temp);
}

t_gab	*new_gab(t_assm *assm,t_info *info, t_arg *arg)
{
	t_gab *new;

	if (!(new = (t_gab *)malloc(sizeof(t_gab))))
		sys_err("Error malloc.\n");
	if (arg->bl_dir != 0)
	{
		new->oct_start = (info->bl_code_arg == 1 ? 2 : 0);
		new->oct_count = info->size_dir;
	}
	else if (arg->bl_ind != 0)
	{
		new->oct_start = 2;
		new->oct_count = 2;
	}
	new->pos_write = assm->pos_glob;
	new->next = NULL;
	return (new);
}

void	search_lbl(t_assm *assm, t_info *info, t_arg *arg)
{
	t_gab *gab;
	t_lbl *lbl;

	gab = new_gab(assm, info, arg);
	lbl = get_lbl(&assm->lbl, arg->lable);
	//lbl->gab = gab;
	if (lbl->gab == NULL)
		lbl->gab = gab;
	else
	{
		gab->next = lbl->gab;
		lbl->gab = gab;
	}
	print_list(assm->lbl);
}

void	first_arg(t_assm *assm, t_opr *opr)
{
	if (opr->fir.lable != NULL)
		search_lbl(assm, &opr->info, &opr->fir);
	if (opr->fir.bl_ind != 0)
		assm->pos_glob += write_big_endian(assm->fd_cor, &opr->fir.ind, IND_SIZE);
	if (opr->fir.bl_dir != 0)
		assm->pos_glob += write_big_endian(assm->fd_cor, &opr->fir.dir, DIR_SIZE);
}

void	second_arg(t_assm *assm, t_opr *opr)
{
	if (opr->sec.bl_reg != 0)
		assm->pos_glob += write_big_endian(assm->fd_cor, &opr->sec.reg, 1);
}

void	op_ld(t_assm *assm, t_opr *opr)
{
	unsigned char code_args;

	cheak_op_ld_arg(assm, opr);
	code_args = get_code_arg(opr);
	ft_putchar_fd(0x02, assm->fd_cor);
	ft_putchar_fd(code_args, assm->fd_cor);
	assm->pos_glob += 2;
	opr->info.size_dir = DIR_SIZE;
	opr->info.bl_code_arg = 1;
	first_arg(assm, opr);
	second_arg(assm, opr);
	ft_putendl("Operation ld finish.------------------------------------");
}

void	two_char_operator(t_assm *assm, char *start)
{	
	t_opr *opr;

	opr = get_arg_opr(assm, start + 2);
	if (!(ft_strncmp(start, "ld", 2)))
		op_ld(assm, opr);
	else if (!(ft_strncmp(start, "or", 2)))
		ft_putendl("Operation OR.");
	else if (!(ft_strncmp(start, "st", 2)))
		ft_putendl("Operation ST.");
	else
		error("Error operator.", assm);
	free(opr);
}

void	working_operation(t_assm *assm, char *start, char *line)
{
	size_t	len;

	len = line - start;
	if (len == 3)
		ft_putendl("THREE CHAR.");
	else if (len == 4)
		ft_putendl("FOUR CHAR.");
	else if (len == 2)
	{
		ft_putendl("TWO CHAR.");
		two_char_operator(assm, start);
	}
	else if (len == 5)
		ft_putendl("FIVE CHAR.");
	else
		error("Error operator.", assm);
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
			working_lable(assm, start, line);
			return ;
		}
		if (*line == DIRECT_CHAR || *line == ' ')
		{
			ft_putendl("DIRECT_CHAR and SPACE");
			working_operation(assm, start, line);
			//Оработать ошибку неправильного имень функции.
			return ;
		}
		assm->counter_column++;
		line++;
	}
}

int		isprint_char(int c)
{
	if (c >= 33 && c <= 126)
		return (1);
	return (0);
}

void	working_instruction(t_assm *assm, char *line)
{
	ft_printf("line = {%s}\n", line); 
	while (*line)
	{
		if (*line == COMMENT_CHAR)
			return ;
		if (isprint_char(*line))
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
		assm->counter_column = 1;
		working_instruction(assm, line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

void	delete_list(t_assm *assm)
{
	t_lbl *lbl;

	lbl = assm->lbl;
	while (assm->lbl)
	{
		ft_strdel(&lbl->name);
		free(lbl);
		assm->lbl = assm->lbl->next;
		lbl = assm->lbl;
	}
}

int		main(int ac, char **av)
{
	t_assm	assm;
	if (ac != 2)
		sys_err("Error!\nUse ./asm namefile.s\n");
	open_file_s(&assm, av[1]);
	read_name_comment(&assm);
	create_file_cor(&assm, av[1]);
	write_header(&assm);
	read_instruction(&assm);
	delete_list(&assm);
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
