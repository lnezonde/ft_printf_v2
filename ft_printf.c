/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:48:58 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/18 17:18:07 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	multi_print(const char **str, va_list param)
{
	t_data_stock	data;

	data = read_data(str, param);
	if (data.type == 'c')
		return (print_c(va_arg(param, int), data));
	if (data.type == 's')
		return (print_s(va_arg(param, char *), data));
	if (data.type == 'p')
		return (print_p(va_arg(param, char **), data));
	if (data.type == 'd' || data.type == 'i')
		return (print_di(va_arg(param, int), data));
	if (data.type == 'u')
		return (print_uxx(va_arg(param, unsigned int), data));
	if (data.type == 'x')
		return (print_uxx(va_arg(param, unsigned int), data));
	if (data.type == 'X')
		return (print_uxx(va_arg(param, unsigned int), data));
	if (data.type == '%')
		return (print_c('%', data));
	return (0);
}

int			ft_printf(const char *str, ...)
{
	va_list	param;
	int		len;

	len = 0;
	va_start(param, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += multi_print(&str, param);
		}
		else
		{
			write(1, &str[0], 1);
			str++;
			len++;
		}
	}
	va_end(param);
	return (len);
}
