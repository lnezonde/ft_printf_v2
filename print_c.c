/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:00:29 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/19 12:28:18 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_c(char c, t_data_stock data)
{
	if (data.width > 1 && data.dir == '+')
		print_zeros(data.width, data.zero);
	ft_putchar(c);
	if (data.width > 1 && data.dir == '-')
		print_zeros(data.width, ' ');
	return (0);
}
