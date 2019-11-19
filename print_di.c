/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:00:11 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/19 18:34:16 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(long nb)
{
	if (nb < 0)
		nb *= -1;
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar('0' + nb % 10);
}

static int	print_di_pos(int nb, t_data_stock data)
{
	print_uxx(nb, data);
	return (di_len(nb, data));
}

static int	print_di_neg(int nb, t_data_stock data)
{
	int len;
	int add;

	add = 1;
	if (data.width > data.precision)
		add = 0;
	len = ft_nbr_size_int(nb) - add;
	if (data.precision != -1)
		data.zero = ' ';
	if (data.precision > len)
		len = data.precision - add;
	if (data.precision == -1 && data.zero == '0')
		ft_putchar('-');
	if (data.width > len && data.dir == '+')
		print_zeros(data.width - len, data.zero);
	if (data.zero == ' ')
		ft_putchar('-');
	if (data.precision > ft_nbr_size_int(nb))
	{
		len = ft_nbr_size_int(nb) - 1;
		print_zeros(data.precision - len, '0');
		len = data.precision - add;
	}
	ft_putnbr(nb);
	if (data.width > len && data.dir == '-')
		print_zeros(data.width - len, ' ');
	return (di_len(nb, data));
}

int			print_di(int nb, t_data_stock data)
{
	if (nb == 0 && data.precision == 0)
	{
		print_zeros(data.width + 1, ' ');
		return (di_len(nb, data));
	}
	if (nb >= 0)
		return (print_di_pos(nb, data));
	else
		return (print_di_neg(nb, data));
}
