/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:17:31 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/19 15:45:19 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main()
{
	char *str;
	int i;

	str = "test";
	i = ft_printf("ft_printf : [%5.3d]\n", -48);
	printf("%i\n", i);
	i = printf("printf :    [%5.3d]\n", -48);
	printf("%i\n", i);
	return (0);
}
