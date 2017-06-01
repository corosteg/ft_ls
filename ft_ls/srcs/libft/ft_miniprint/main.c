/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:04:03 by corosteg          #+#    #+#             */
/*   Updated: 2017/05/31 16:39:05 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			main()
{
	int		i = 0;
	char	*str = "toto";

//	ft_printf("ft_printf = %d %s \n", 10, str);
//	   printf("   printf = %d %s \n", 10, str);
//	   printf("   printf =  %d%d%d %djdjd \n", i, 10, 10, 100);
//	ft_printf("ft_printf =  %d%d%d %djdjd \n", i, 10, 10, 100);
//	   printf("   printf = %s  %d  %s%% \n", "lsls", 1, "un");
//	ft_printf("ft_printf = %s  %d  %s%% \n", "lsls", 1, "un");
	ft_printf("ft_printf = %d %s %d %s \n", i, str, 10, "coucou");
//	   printf("   printf = %d %s %d %s \n", i, str, 10, "coucou");
//	while ((ft_printf(" %d", i) == printf(" %d", i)) && i < 2147483647 && printf("\n"))
//		i = 2147483648;
	return (0);
}
