/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:49:58 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/16 17:49:27 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(long nb, char *base)
{
	int		i;
	int		tmp;
	char	c;

	i = 0;
	while (base[i])
		i++;
	tmp = nb / i;
	c = base[nb % i];
	if (tmp != 0)
	{
		nb = nb / i;
		ft_putnbr_base(nb, base);
	}
	ft_putchar(c);
}

int	print_uxx(unsigned long nb, int type, t_data_stock data)
{
	char *base;

	base = "0123456789";
	if (type == 'x')
		base = "0123456789abcdef";
	else if (type == 'X')
		base = "0123456789ABCDEF";
	ft_putnbr_base(nb, base);
	return (0);
}
