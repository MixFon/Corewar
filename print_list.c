
void	print_liest(t_assm *assm)
{
	t_lbl *lbl;	
	t_gab *gab;	
	
	lbl = assm->lbl;
	ft_putstr("lbl->name ");
	ft_putendl(lbl->name);
	while (lbl)
	{
		gab = lbl->gab;
		while (gab)
		{
			ft_putstr("pos_write ");
			ft_putnbr_fd(gab->pos_write, 1);
			ft_putstr("\n");
			//ft_putendl(lbl->name);
			gab = gab->next;
		}
		lbl = lbl->next;
	}
	
}
