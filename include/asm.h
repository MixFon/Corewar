#ifndef		ASM_H
# define	ASM_H

# include <unistd.h>
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct	s_assm
{
	int			fd_cor;
	int			fd_s;
	size_t		octet;
}				t_assm;


#endif
