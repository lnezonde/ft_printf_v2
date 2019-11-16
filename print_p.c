/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:59:42 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/16 18:00:00 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(char **ptr, t_data_stock data)
{
	if (data.width > 14 && data.dir == '+')
		print_zeros(data.width - 13, ' ');
	ft_putstr("0x", 2);
	print_uxx((unsigned long)ptr, 'x', data);
	if (data.width > 14 && data.dir == '-')
		print_zeros(data.width - 13, ' ');
	return (0);
}
