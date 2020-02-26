/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 09:43:41 by widraugr          #+#    #+#             */
/*   Updated: 2020/02/26 11:10:04 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <unistd.h>
# include "libft.h"
# include "op.h"
# include <fcntl.h>

# define C_REG		0x1
# define C_DIR		0x2
# define C_IND		0x3
# define LEN_HEAD	2192
# define LEN_MALLOK	8704

typedef struct		s_assm
{
	int				fd_cor;
	int				fd_s;
	char			*name_cor;
	size_t			pos_glob;
	size_t			counter_line;
	t_header_s		head;
	struct s_lbl	*lbl;
	unsigned char	*code_str;
	size_t			len_str;
	size_t			size_str_malloc;
}					t_assm;

typedef struct		s_lbl
{
	char			*name;
	int				bl;
	size_t			position;
	struct s_lbl	*next;
	struct s_gab	*gab;
}					t_lbl;

typedef struct		s_gab
{
	size_t			pos_write;
	short			oct_count;
	short			oct_start;
	struct s_gab	*next;
}					t_gab;

typedef struct		s_arg
{
	int				dir;
	short			ind;
	char			reg;
	char			*lable;
	unsigned char	bl_dir;
	unsigned char	bl_ind;
	unsigned char	bl_reg;
}					t_arg;

typedef struct		s_info
{
	short			size_dir;
	short			bl_code_arg;
	short			oct_start;
}					t_info;

typedef struct		s_opr
{
	t_arg			args[3];
	short			count_args;
	struct s_info	info;
}					t_opr;

/*
** File write_header.c
*/
int					check_name(char *name);
char				*dot_cor(char *name);
void				init(t_assm *assm);
void				open_file_s(t_assm *assm, char *name);
void				write_header(t_assm *assm);
/*
** File read_comment_champion.c
*/
void				close_files(t_assm *assm);
void				error(const char *msg, t_assm *assm);
void				read_name_champion(char *line, t_assm *assm);
void				working_name(char *line, t_assm *assm);
void				read_comment_champion(char *line, t_assm *assm);
/*
** File read_name_comment.c
*/
void				working_comment(char *line, t_assm *assm);
int					working_dot(t_assm *assm, char *line, int *bl_name_comm);
int					search_char(t_assm *assm, char *line, int *bl_name_comm);
void				read_name_comment(t_assm *assm);
/*
** File add_lable_list.c
*/
int					islablechar(char c);
void				check_lable(t_assm *assm, char *start, char *line);
t_lbl				*create_lable(char *start, char *end);
int					search_dub_lable(t_assm *assm, t_lbl *lbl, char *start,
		char *line);
void				add_lable_list(t_assm *assm, char *start, char *line);
/*
** File init_arg.c
*/
int					is_char_end_line(char c);
void				working_lable(t_assm *assm, char *start, char *line);
int					isdigit_per_colon(int c);
void				init_arg(t_arg *arg);
/*
** File read_dir_adg.c
*/
void				init_opt(t_opr *opr);
char				*create_lable_arg(char *start, t_arg *arg);
char				*read_ind_adg(t_arg *arg, char *start);
char				*read_reg_adg(t_assm *assm, t_arg *arg, char *start);
char				*read_dir_adg(t_arg *arg, char *start);
/*
** File check_op_or_xor_and_arg.c
*/
char				*read_arguments(t_assm *assm, t_arg *arg, char *start);
t_opr				*get_arg_opr(t_assm *assm, char *start);
void				check_op_ld_lld_arg(t_assm *assm, t_opr *opr);
void				check_op_st_arg(t_assm *assm, t_opr *opr);
void				check_op_or_xor_and_arg(t_assm *assm, t_opr *opr);
/*
** File check_op_sti_arg.c
*/
void				check_op_ldi_lldi_arg(t_assm *assm, t_opr *opr);
void				check_op_fork_lfork_zjmp_live_arg(t_assm *assm, t_opr *opr);
void				check_op_aff_arg(t_assm *assm, t_opr *opr);
void				check_op_add_sub_arg(t_assm *assm, t_opr *opr);
void				check_op_sti_arg(t_assm *assm, t_opr *opr);
/*
** File search_lbl.c
*/
unsigned char		get_code_arg(t_opr *opr);
int					write_big_endian(t_assm *assm, int fd,
		void *bits, int len_bits);
t_lbl				*get_lbl(t_lbl **lbl, char *lable);
t_gab				*new_gab(t_assm *assm, t_info **info, t_arg *arg);
void				search_lbl(t_assm *assm, t_info *info, t_arg *arg);
/*
** File four_char_operator.c
*/
void				all_arg(t_assm *assm, t_info *info, t_arg *arg);
void				delete_opr(t_opr **opr);
void				op_all(t_assm *assm, t_opr *opr, int code,
		void (*func)(t_assm*, t_opr*));
void				two_char_operator(t_assm *assm, char *start);
void				four_char_operator(t_assm *assm, char *start);
/*
** File isprint_char.c
*/
void				five_char_operator(t_assm *assm, char *start);
void				three_char_operator(t_assm *assm, char *start);
void				working_operation(t_assm *assm, char *start, char *line);
void				instruction(t_assm *assm, char *line);
int					isprint_char(int c);
/*
** File delete_list.c
*/
void				delete_code_str(t_assm *assm);
void				working_instruction(t_assm *assm, char *line);
void				read_instruction(t_assm *assm);
void				delete_list_gab(t_gab *gab);
void				delete_list(t_assm *assm);
/*
** File main.c
*/
int					get_figur_write(size_t position, t_gab *gab);
void				write_in_position(t_assm *assm, t_lbl *lbl);
void				weite_figur_lable(t_assm *assm);
void				write_bot_size(t_assm *assm);
int					main(int ac, char **av);
/*
** File write_code_str.c
*/
void				write_code_str_to_file(t_assm *assm, char *name);
void				write_prog_name_and_comment(t_assm *assm,
		char *name_prog, size_t size);
void				to_plase_code_str(t_assm *assm, size_t plase,
		void *bits, int len_bits);
void				to_code_str(t_assm *assm, int code_op);
void				write_code_str(t_assm *assm, unsigned char *bit);
#endif
