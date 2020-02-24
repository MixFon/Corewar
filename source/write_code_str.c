/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_code_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:38:33 by widraugr          #+#    #+#             */
/*   Updated: 2020/02/24 12:20:15 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void			write_code_str(t_assm *assm, unsigned char *bit)
{
	//ft_putchar('a');
	//ft_putchar('c');
	if (assm->len_str + 1 >= assm->size_str_malloc)	
	{
		assm->size_str_malloc *= 2;
		if (!(assm->code_str = (unsigned char *)realloc(assm->code_str,
						sizeof(unsigned char) *	assm->size_str_malloc)))
			sys_err("Error malloc.");
	}
	//ft_printf("%x", *bit);
	assm->code_str[assm->len_str] = *bit;
	assm->code_str[assm->len_str + 1] = '\0';
	//code_str[len_str] = *bit;
	assm->len_str++;
}

void	write_code_str_to_file(t_assm *assm, char *name)
{
	assm->name_cor = dot_cor(name);
	if (!(assm->fd_cor = open(assm->name_cor, O_WRONLY | O_TRUNC | O_CREAT,
					S_IREAD | S_IWRITE)))
		sys_err("Error create file.\n");
	if ((write(assm->fd_cor, assm->code_str, assm->len_str) == -1))
		sys_err("Error write file.\n");
}

void	write_prog_name_and_comment(t_assm *assm, char *name_prog, size_t size)
{
	size_t			i;
	size_t			len;
	unsigned char	sector;

	i = -1;
	
	len = ft_strlen(name_prog);
	//ft_printf("len name_prog {%d}\n", ft_strlen(name_prog));
	sector = 0;
	while (++i < size)
	{
		//ft_putchar('a');
		if (*name_prog != '\0')
		{
			//ft_putchar('b');
			write_code_str(assm, (unsigned char *)name_prog);
			name_prog++;
		}
		else
			write_code_str(assm, &sector);
	}
}

/*
** Записывает в указанное место
*/
void	to_plase_code_str(t_assm *assm, size_t plase, void *bits, int len_bits)
{
	int i;

	i = 0;
	while (len_bits > 0)
	{
		len_bits--;
		assm->code_str[plase + i] = *((unsigned char *)bits + len_bits);
		//write_code_str((unsigned char *)bits + len_bits);
		i++;
	}
}

/*
** Записывает в конец строки.
*/
void	to_code_str(t_assm *assm, int code_op)
{
	assm->code_str[assm->len_str] = (unsigned char)code_op;
	assm->len_str++;
}

void	delete_code_str(t_assm *assm)
{
	free(assm->code_str);
	assm->code_str = NULL;
}
