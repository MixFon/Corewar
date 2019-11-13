/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:24:38 by widraugr          #+#    #+#             */
/*   Updated: 2019/01/31 10:14:40 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_recprint(char *str, intmax_t neg)
{
	int		i;

	i = ft_strlen(str) - 1;
	if (neg == -1)
		ft_putchar('-');
	if (*str == '\0')
		ft_putchar('0');
	while (i >= 0)
	{
		ft_putchar(str[i]);
		i--;
	}
}

void			ft_putnbr(intmax_t n)
{
	intmax_t		num;
	char			str[20];
	int				i;
	int				neg;

	i = 0;
	num = n;
	neg = 0;
	if (n < 0)
	{
		neg = -1;
		num = num * (-1);
	}
	while (num != 0)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	str[i] = '\0';
	ft_recprint(str, neg);
}
