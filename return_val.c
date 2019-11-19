/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_val.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:04:10 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/19 19:12:24 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		s_len(char *str, t_data_stock data)
{
	int len;

	len = ft_strlen(str);
	if (data.precision < len && data.precision != -1)
		len = data.precision;
	if (data.width > len)
		len += data.width - len;
	return (len);
}

int		c_len(t_data_stock data)
{
	int len;

	len = 1;
	if (data.width > len)
		len += data.width - 1;
	return (len);
}

int		p_len(char **ptr, t_data_stock data)
{
	int len;

	len = ft_nbr_size((unsigned long)ptr, 'x') + 2;
	if (ptr == NULL)
		len = 3;
	if (ptr == NULL && data.precision == 0)
		len--;
	if (data.precision > len)
		len += data.precision - len + 2;
	if (data.width > len)
		len += data.width - len;
	return (len);
}

int		uxx_len(unsigned long nb, t_data_stock data)
{
	int len;

	if (nb == 0 && data.precision == 0 && data.width == -1)
		return (0);
	len = ft_nbr_size(nb, data.type);
	if (data.width > len)
		len += data.width - len;
	if (data.precision > len)
		len += data.precision - len;
	return (len);
}

int		di_len(int nb, t_data_stock data)
{
	int len;

	len = 0;
	if (nb == 0 && data.precision == 0 && data.width == -1)
		return (0);
	len = ft_nbr_size_int(nb);
	if (data.width <= len && data.precision == -1 && data.width != -1
		&& nb < 0)
		len++;
	if (data.width > len)
		len += data.width - len;
	if (data.precision > len)
		len += data.precision - len;
	if (data.width > data.precision && nb < 0)
		len--;
	if (nb < 0)
		len++;
	return (len);
}
