/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:41:46 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/15 17:05:08 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h> // a suprimer

typedef	struct
{
	char		dir;
	char		zero;
	int			width;
	int			precision;
	char		type;
}				t_data_stock;

int				ft_printf(const char *str, ...);
void			ft_putchar(char c);
int				ft_strlen(char *str);

int				print_uxx(unsigned int nb, int type, t_data_stock data);
int				print_c(char c, t_data_stock data);
int				print_di(int nb, t_data_stock data);
int				print_s(char *str, t_data_stock data);
int				print_p(char **ptr, t_data_stock data);

t_data_stock	read_data(const char **str, va_list param);
#endif
