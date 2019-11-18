/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:59:42 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/18 17:28:10 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(char **ptr, t_data_stock data)
{
	int len;

	len = ft_nbr_size((unsigned long)ptr, 16) + 1;
	if (ptr == NULL)
		len = 1;
	if (data.width > 14 && data.dir == '+')
		print_zeros(data.width - len, ' ');
	ft_putstr("0x", 2);
	if (ptr != NULL)
		print_long((unsigned long)ptr, 'x');
	if (data.width > 14 && data.dir == '-')
		print_zeros(data.width - len, ' ');
	return (0);
}
