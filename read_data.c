/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:56:28 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/19 17:57:44 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		istype(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'v'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int		which_nb(const char **str)
{
	int i;

	i = 0;
	if (**str > '9' && **str < '0')
		return (-1);
	while (**str <= '9' && **str >= '0')
	{
		i = i * 10 + (**str - '0');
		(*str)++;
	}
	return (i);
}

static int		which_width(const char **str, char *data_dir, va_list param)
{
	int width;

	width = 0;
	if (**str == '*')
	{
		(*str)++;
		width = va_arg(param, int);
		if (width < 0)
		{
			*data_dir = '-';
			width *= -1;
		}
		return (width);
	}
	return (which_nb(str));
}

static int		which_precision(const char **str, va_list param)
{
	int precision;

	precision = -1;
	(*str)++;
	if (**str > '9' && **str < '0')
		return (0);
	if (**str == '*')
	{
		(*str)++;
		precision = va_arg(param, int);
		if (precision < 0)
			precision = -1;
		return (precision);
	}
	return (which_nb(str));
}

int				read_zero(char c, char *data_zero, char data_dir)
{
	if (c == '0')
	{
		*data_zero = '0';
		return (1);
	}
	if (data_dir == '-' && *data_zero == '0')
		*data_zero = ' ';
	return (0);
}

t_data_stock	read_data(const char **str, va_list param)
{
	t_data_stock	data;
	int				i;

	data.dir = '+';
	data.precision = -1;
	data.type = '\0';
	data.width = -1;
	data.zero = ' ';
	i = 0;
	while (**str && !istype(**str))
	{
		if (**str == '-' && ((*str)++))
			data.dir = '-';
		else if (read_zero(**str, &data.zero, data.dir))
			(*str)++;
		else if ((**str > '0' && **str <= '9') || **str == '*')
			data.width = which_width(str, &data.dir, param);
		else if (**str == '.')
			data.precision = which_precision(str, param);
		else
			(*str)++;
	}
	if (istype(**str) == 1)
		data.type = *(*str)++;
	return (data);
}
