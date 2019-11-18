/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:21:15 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/18 17:12:21 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_zeros(int n, char c)
{
	while (n-- > 1)
		ft_putchar(c);
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

int		ft_nbr_size(unsigned long nb, int size_base)
{
	int i;

	i = 0;
	if (nb < 0)
		i++;
	while (nb / size_base != 0)
	{
		nb /= size_base;
		i++;
	}
	return (i + 1);
}
