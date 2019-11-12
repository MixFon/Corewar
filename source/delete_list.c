
#include "../include/asm.h"

int		isprint_char(int c)
{
	if (c >= 33 && c <= 126)
		return (1);
	return (0);
}

void	working_instruction(t_assm *assm, char *line)
{
	while (*line)
	{
		if (*line == COMMENT_CHAR)
			return ;
		if (isprint_char(*line))
		{
			instruction(assm, line);
			return ;
		}
		line++;
	}
}

void	read_instruction(t_assm *assm)
{
	char	*line;

	line = NULL;
	while (get_next_line(assm->fd_s, &line))
	{
		assm->counter_line++;
		working_instruction(assm, line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

void	delete_list_gab(t_gab *gab)
{
	t_gab *temp;

	temp = gab;
	while(gab)
	{
		gab = gab->next;
		free(temp);
		temp = gab;
	}
}

void	delete_list(t_assm *assm)
{
	t_lbl *lbl;

	lbl = assm->lbl;
	while (assm->lbl)
	{
		assm->lbl = assm->lbl->next;
		ft_strdel(&lbl->name);
		delete_list_gab(lbl->gab);
		free(lbl);
		lbl = assm->lbl;
	}
	assm->lbl = NULL;
}
