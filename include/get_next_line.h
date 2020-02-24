/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:35:37 by widraugr          #+#    #+#             */
/*   Updated: 2020/02/24 14:04:46 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4096

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_lst
{
	char			*tail;
	int				fd;
	struct s_lst	*next;
	struct s_lst	*first_lst;
}					t_newlst;

int					get_next_line(const int fd, char **line);

#endif
