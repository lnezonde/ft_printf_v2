/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:57:03 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/19 16:48:17 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s(char *str, t_data_stock data)
{
	int len;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (data.precision < len && data.precision != -1)
		len = data.precision;
	if (data.width > len && data.dir == '+')
		print_zeros(data.width - len + 1, data.zero);
	ft_putstr(str, len);
	if (data.width > len && data.dir == '-')
		print_zeros(data.width - len + 1, ' ');
	return (s_len(str, data));
}
