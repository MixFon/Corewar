/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_code_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:38:33 by widraugr          #+#    #+#             */
/*   Updated: 2020/02/21 19:09:31 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void			write_code_str(unsigned char *bit)
{
	static size_t i = 0;
	
	//ft_putchar('a');
	//ft_putchar('c');
	ft_printf("%x", *bit);
	code_str[len_str] = *bit;
	len_str++;
	i++;
}

void	write_code_str_to_file(void)
{
	int fd_file;

	if (!(fd_file = open("./file", O_WRONLY | O_TRUNC | O_CREAT,
					S_IREAD | S_IWRITE)))
		sys_err("Error create file.\n");
	//ft_printf("len = {%d} code_str = [%s]\n", ft_strlen(code_str), code_str);
	if ((write(fd_file, &code_str, len_str) == -1))
		sys_err("Error write file.\n");
}

void	write_prog_name_and_comment(char *name_prog, size_t size)
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
			write_code_str((unsigned char *)name_prog);
			name_prog++;
		}
		else
			write_code_str(&sector);
	}
}

/*
** Записывает в указанное место
*/
void	to_plase_code_str(size_t plase, void *bits, int len_bits)
{
	int i;

	i = 0;
	while (len_bits > 0)
	{
		len_bits--;
		code_str[plase + i] = *((unsigned char *)bits + len_bits);
		//write_code_str((unsigned char *)bits + len_bits);
		i++;
	}
}

/*
** Записывает в конец строки.
*/
void	to_code_str(int code_op)
{
	code_str[len_str] = (unsigned char)code_op;
	len_str++;
}	
