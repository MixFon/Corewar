/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 09:43:41 by widraugr          #+#    #+#             */
/*   Updated: 2019/09/12 16:50:35 by widraugr         ###   ########.fr       */
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
	int			fd_cor;
	int			fd_s;
	size_t		octet;
	size_t		counter_line;
	size_t		counter_column;
	t_header_s	head;
}				t_assm;

#endif
