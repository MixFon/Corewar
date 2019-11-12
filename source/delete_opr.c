
#include "../include/asm.h"

t_lbl	*get_lbl(t_lbl **lbl, char *lable)
{
	t_lbl *temp;

	temp = *lbl;
	while(temp)
	{
		if (!ft_strcmp(temp->name, lable))
			return (temp);	
		temp = temp->next;
	}
	temp = create_lable(lable, lable + ft_strlen(lable));	
	temp->next = *lbl;
	*lbl = temp;
	(*lbl)->bl = 0;
	(*lbl)->position = LEN_HEAD;
	return (temp);
}

t_gab	*new_gab(t_assm *assm,t_info **info, t_arg *arg)
{
	t_gab *new;

	if (!(new = (t_gab *)malloc(sizeof(t_gab))))
		sys_err("Error malloc.\n");
	if (arg->bl_dir != 0)
	{
		new->oct_start = ((*info)->bl_code_arg == 1 ? (*info)->oct_start : 1);
		new->oct_count = (*info)->size_dir;
	}
	else if (arg->bl_ind != 0)
	{
		new->oct_start = (*info)->oct_start;
		new->oct_count = 2;
	}
	else if (arg->bl_reg != 0)
	{
		new->oct_start = (*info)->oct_start;
		new->oct_count = 1;
	}
	new->pos_write = assm->pos_glob;
	new->next = NULL;
	return (new);
}

void	search_lbl(t_assm *assm, t_info *info, t_arg *arg)
{
	t_gab *gab;
	t_lbl *lbl;

	gab = new_gab(assm, &info, arg);
	lbl = get_lbl(&assm->lbl, arg->lable);
	if (lbl->gab == NULL)
		lbl->gab = gab;
	else
	{
		gab->next = lbl->gab;
		lbl->gab = gab;
	}
}

void	all_arg(t_assm *assm, t_info *info, t_arg *arg)
{
	int	delta;

	delta = 0;
	if (arg->lable != NULL)
		search_lbl(assm, info, arg);
	if (arg->bl_ind != 0)
		delta += write_big_endian(assm->fd_cor, &arg->ind, IND_SIZE);
	if (arg->bl_dir != 0)
		delta += write_big_endian(assm->fd_cor, &arg->dir, info->size_dir);
	if (arg->bl_reg != 0)
		delta += write_big_endian(assm->fd_cor, &arg->reg, 1);
	assm->pos_glob += delta;
	info->oct_start += delta;

}

void	delete_opr(t_opr **opr)
{
	ft_strdel(&(*opr)->args[0].lable);
	ft_strdel(&(*opr)->args[1].lable);
	ft_strdel(&(*opr)->args[2].lable);
	free(*opr);
}
