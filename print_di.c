/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:00:11 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/19 14:00:28 by lnezonde         ###   ########.fr       */
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
		ft_putnbr(nb / 10);
	ft_putchar('0' + nb % 10);
}

static int	print_di_pos(int nb, t_data_stock data)
{
	int len;

	len = ft_nbr_size(nb, data.type) - 1;
	if (data.precision != -1)
		data.zero = ' ';
	if (data.precision > len)
		len = data.precision - 1;
	if (data.width > len && data.dir == '+')
		print_zeros(data.width - len, data.zero);
	if (data.precision > len)
	{
		len = ft_nbr_size(nb, data.type) - 1;
		print_zeros(data.precision - len, '0');
		len = data.precision - 1;
	}
	ft_putnbr(nb);
	if (data.width > len && data.dir == '-')
		print_zeros(data.width - len, ' ');
	return (0);
}

static int	print_di_neg(int nb, t_data_stock data)
{
	int len;

	len = ft_nbr_size(nb, data.type) - 1;
	if (data.precision != -1)
		data.zero = ' ';
	if (data.precision > len)
		len = data.precision - 1;
	if (data.width > len && data.dir == '+')
		print_zeros(data.width - len, data.zero);
	if (data.precision > len)
	{
		len = ft_nbr_size(nb, data.type) - 1;
		print_zeros(data.precision - len, '0');
		len = data.precision - 1;
	}
	ft_putnbr(nb);
	if (data.width > len && data.dir == '-')
		print_zeros(data.width - len, ' ');
	return (0);
}

int		print_di(int nb, t_data_stock data)
{
	if (nb == 0 && data.precision == 0)
	{
		print_zeros(data.width + 1, ' ');
		return (0);
	}
	if (nb > 0)
		return(print_di_pos(nb , data));
	else
		return(print_di_neg(nb , data));
}
