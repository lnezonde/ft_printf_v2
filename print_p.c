/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:59:42 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/19 12:26:01 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(char **ptr, t_data_stock data)
{
	int len;
	char *pref;

	pref = "0x";
	len = ft_nbr_size((unsigned long)ptr, 'x') + 1;
	if (ptr == NULL)
		pref = "0x0";
	if (data.width > len && data.dir == '+')
		print_zeros(data.width - len, ' ');
	ft_putstr(pref, ft_strlen(pref));
	if (ptr != NULL)
		print_long((unsigned long)ptr, 'x');
	if (data.width > len && data.dir == '-')
		print_zeros(data.width - len, ' ');
	return (0);
}
