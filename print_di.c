/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:00:11 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/18 17:27:22 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			nb = 147483648;
		}
		else
			nb *= -1;
	}
	if (nb >= 10)
		ft_putchar(nb / 10);
	ft_putchar('0' + nb % 10);
}

int			print_di(int nb, t_data_stock data)
{
	(void)nb;
	(void)data;
	ft_putnbr(3);
	return (0);
}
