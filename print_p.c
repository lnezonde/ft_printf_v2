/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:59:42 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/19 19:07:37 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(char **ptr, t_data_stock data)
{
	int		len;
	char	*pref;

	pref = "0x";
	len = ft_nbr_size((unsigned long)ptr, 'x') + 1;
	if (data.precision == 0)
		len--;
	if (ptr == NULL && data.precision != 0)
		pref = "0x0";
	if (data.width > len && data.dir == '+' && data. precision <= len)
		print_zeros(data.width - len, ' ');
	else if (data.precision > len)
		print_zeros(data.width - data.precision - 1, ' ');
	ft_putstr(pref, ft_strlen(pref));
	if (data.precision > len)
		print_zeros(data.precision - len + 2, '0');
	if (ptr != NULL)
		print_long((unsigned long)ptr, 'x');
	if (data.width > len && data.dir == '-')
		print_zeros(data.width - len, ' ');
	return (p_len(ptr, data));
}
