/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:49:58 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/15 18:32:49 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_uxx(unsigned int nb, int type, t_data_stock data)
{
	return (0);
}

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
