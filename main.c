/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:17:31 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/19 14:14:39 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main()
{
	char *str;
	int i;

	str = "test";
	i = ft_printf("ft_printf : [%7d]\n", -17);
	printf("%i\n", i);
	i = printf("printf :    [%7d]\n", -17);
	printf("%i\n", i);
	return (0);
}
