/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:21:15 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/19 15:34:56 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_zeros(int n, char c)
{
	int i;

	i = 0;
	while (n-- > 1)
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);

}

int		ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

void	ft_putstr(char *str, int l)
{
	int i;

	i = 0;
	while (str[i] && i < l)
		ft_putchar(str[i++]);
}

int		ft_nbr_size(unsigned long nb, char type)
{
	int i;
	int size_base;

	i = 0;
	size_base = 10;
	if (type == 'x' || type == 'X')
		size_base = 16;
	while (nb / size_base != 0)
	{
		nb /= size_base;
		i++;
	}
	return (i + 1);
}

int		ft_nbr_size_int(int nb)
{
	int i;

	i = 0;
	while (nb / 10 != 0)
	{
		nb /= 10;
		i++;
	}
	return (i + 1);
}
