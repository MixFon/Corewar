/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lable_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:25:57 by widraugr          #+#    #+#             */
/*   Updated: 2020/02/25 13:46:35 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int		islablechar(char c)
{
	if ((c >= 97 && c <= 122) || (c >= 48 && c <= 57) || c == 95)
		return (1);
	return (0);
}

void	check_lable(t_assm *assm, char *start, char *line)
{
	while (start < line)
	{
		if (!islablechar(*start))
			error("Error lable char.", assm);
		start++;
	}
}

t_lbl	*create_lable(char *start, char *end)
{
	t_lbl	*new;
	int		len;

	len = end - start;
	if (!(new = (t_lbl*)malloc(sizeof(t_lbl))))
		sys_err("Eror malloc\n");
	if (!(new->name = ft_strnew(len)))
		sys_err("Eror malloc\n");
	ft_strncpy(new->name, start, len);
	new->next = NULL;
	new->bl = 0;
	new->gab = NULL;
	return (new);
}

int		search_dub_lable(t_assm *assm, t_lbl *lbl, char *start, char *line)
{
	t_lbl	*temp;
	int		len;
	int		len_str;
	int		diff;

	temp = lbl;
	diff = line - start;
	while (lbl)
	{
		len = ft_strlen(lbl->name);
		len_str = (len > diff ? len : diff);
		if (!(ft_strncmp(start, lbl->name, len_str)))
		{
			if (lbl->bl == 0)
			{
				lbl->position = assm->pos_glob;
				lbl->bl = 1;
			}
			return (1);
		}
		lbl = lbl->next;
	}
	return (0);
}

void	add_lable_list(t_assm *assm, char *start, char *line)
{
	t_lbl *lbl;

	if (!assm->lbl)
	{
		assm->lbl = create_lable(start, line);
		assm->lbl->bl = 1;
		assm->lbl->position = assm->pos_glob;
		return ;
	}
	if (search_dub_lable(assm, assm->lbl, start, line))
		return ;
	lbl = create_lable(start, line);
	lbl->next = assm->lbl;
	assm->lbl = lbl;
	assm->lbl->bl = 1;
	assm->lbl->position = assm->pos_glob;
}
