/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 09:43:41 by widraugr          #+#    #+#             */
/*   Updated: 2019/09/23 17:21:26 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ASM_H
# define	ASM_H

# include <unistd.h>
# include "../libft/libft.h"
# include "op.h"
# include <fcntl.h>

# define C_REG		0x1
# define C_DIR		0x2
# define C_IND		0x3

# define LEN_HEAD	(4+PROG_NAME_LENGTH+4+COMMENT_LENGTH+4+4)

typedef struct	s_assm
{
	int				fd_cor;
	int				fd_s;
	size_t			pos_glob;
	size_t			counter_line;
	size_t			counter_column;
	t_header_s		head;
	struct s_lbl	*lbl;
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
	t_arg			fir;
	t_arg			sec;
	t_arg			three;
	short			count_args;
	struct s_info	info;
}					t_opr;


int		write_big_endian(int fd, void *bits, int len_bits);
void	working_instruction(t_assm *assm, char *line);

#endif
