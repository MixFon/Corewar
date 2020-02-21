/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:42:15 by widraugr          #+#    #+#             */
/*   Updated: 2020/02/21 16:27:31 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	five_char_operator(t_assm *assm, char *start)
{
	t_opr	*opr;
	int		up;

	up = 5;
	opr = get_arg_opr(assm, start + up);
	if (!(ft_strncmp(start, "lfork", up)))
		op_all(assm, opr, 0x0210f, check_op_fork_lfork_zjmp_live_arg);
	else
		error("Unknown instruction.", assm);
	delete_opr(&opr);
}

void	three_char_operator(t_assm *assm, char *start)
{
	t_opr	*opr;
	int		up;

	up = 3;
	opr = get_arg_opr(assm, start + up);
	if (!(ft_strncmp(start, "aff", up)))
		op_all(assm, opr, 0x14210, check_op_aff_arg);
	else if (!(ft_strncmp(start, "add", up)))
		op_all(assm, opr, 0x14204, check_op_add_sub_arg);
	else if (!(ft_strncmp(start, "sub", up)))
		op_all(assm, opr, 0x14205, check_op_add_sub_arg);
	else if (!(ft_strncmp(start, "and", up)))
		op_all(assm, opr, 0x14206, check_op_or_xor_and_arg);
	else if (!(ft_strncmp(start, "xor", up)))
		op_all(assm, opr, 0x14208, check_op_or_xor_and_arg);
	else if (!(ft_strncmp(start, "ldi", up)))
		op_all(assm, opr, 0x1220a, check_op_ldi_lldi_arg);
	else if (!(ft_strncmp(start, "lld", up)))
		op_all(assm, opr, 0x1420d, check_op_ld_lld_arg);
	else if (!(ft_strncmp(start, "sti", up)))
		op_all(assm, opr, 0x1220b, check_op_sti_arg);
	else
		error("Unknown instruction.", assm);
	delete_opr(&opr);
}

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
	char *start;

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

/*
** 1 если это печатный символ, кроме пробела.
*/

int		isprint_char(int c)
{
	if (c >= 33 && c <= 126)
		return (1);
	return (0);
}
