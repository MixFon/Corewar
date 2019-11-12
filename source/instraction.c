
#include "../include/asm.h"

void	working_operation(t_assm *assm, char *start, char *line)
{
	size_t	len;

	len = line - start;
	if (len == 3)
		three_char_operator(assm, start);
	else if (len == 4)
		four_char_operator(assm, start);
	else if (len == 2)
		two_char_operator(assm, start);
	else if (len == 5)
		five_char_operator(assm, start);
	else
		error("Unknown instruction.", assm);
}

void	instruction(t_assm *assm, char *line)
{
	char	*start;	

	start = line;
	while (*line)
	{
		if (*line == LABEL_CHAR)
		{
			working_lable(assm, start, line);
			return ;
		}
		if (*line == DIRECT_CHAR || *line == ' ' || *line == '\t')
		{
			working_operation(assm, start, line);
			return ;
		}
		line++;
	}
}
