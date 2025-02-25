/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:41:46 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/20 16:27:53 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

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
void			ft_putstr(char *str, int l);
int				print_zeros(int n, char c);
int				ft_nbr_size(unsigned long nb, char type);
int				print_uxx(unsigned long nb, t_data_stock data);
int				ft_nbr_size_int(int nb);
char			istype(char c);

int				print_long(unsigned long nb, char type);
int				print_c(char c, t_data_stock data);
int				print_di(int nb, t_data_stock data);
int				print_s(char *str, t_data_stock data);
int				print_p(char **ptr, t_data_stock data);

int				s_len(char *str, t_data_stock data);
int				c_len(t_data_stock data);
int				p_len(char **ptr, t_data_stock data);
int				uxx_len(unsigned long nb, t_data_stock data);
int				di_len(int nb, t_data_stock data);

t_data_stock	read_data(const char **str, va_list param);

#endif
