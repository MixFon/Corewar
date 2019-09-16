/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 09:43:41 by widraugr          #+#    #+#             */
/*   Updated: 2019/09/16 17:10:16 by widraugr         ###   ########.fr       */
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
	struct s_arg	*arg;
}					t_lbl;

typedef struct		s_arg
{
	size_t			pos;
	unsigned int	oct;
	unsigned int	oct_start;
	struct s_arg	*next;
}					t_arg;

void	working_instruction(t_assm *assm, char *line);

#endif
