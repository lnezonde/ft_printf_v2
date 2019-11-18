/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:49:58 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/18 18:27:07 by lnezonde         ###   ########.fr       */
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

int	print_long(unsigned long nb, int type)
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

int	print_uxx(unsigned long nb, t_data_stock data)
{
	int len;

	len = ft_nbr_size(nb, 16) - 1;
	if (data.precision != -1)
		data.zero = ' ';
	if (data.precision > len)
		len = data.precision - 1;
	if (data.width > len && data.dir == '+')
		print_zeros(data.width - len, data.zero);
	if (data.precision > len)
	{
		len = ft_nbr_size(nb, 16) - 1;
		print_zeros(data.precision - len, '0');
		len = data.precision - 1;
	}
	print_long(nb, data.type);
	if (data.width > len && data.dir == '-')
		print_zeros(data.width - len, ' ');
	return (0);
}
