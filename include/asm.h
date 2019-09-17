/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 09:43:41 by widraugr          #+#    #+#             */
/*   Updated: 2019/09/17 16:58:55 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ASM_H
# define	ASM_H

# include <unistd.h>
# include "../libft/libft.h"
# include "op.h"
# include <fcntl.h>

typedef struct	s_assm
{
	int				fd_cor;
	int				fd_s;
	size_t			octet;
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
	struct s_gab	*arg;
}					t_lbl;

typedef struct		s_gab
{
	size_t			pos;
	unsigned int	oct;
	unsigned int	oct_start;
	struct s_gab	*next;
}					t_gab;

typedef struct		s_arg
{
	unsigned int	dir;
	short			ind;
	char			reg;
}					t_arg;

typedef struct		s_opr
{
	t_arg			fir;
	t_arg			sec;
	t_arg			three;
	short			comma;
}					t_opr;

void	working_instruction(t_assm *assm, char *line);

#endif
