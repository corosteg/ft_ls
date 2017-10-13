/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 14:27:34 by corosteg          #+#    #+#             */
/*   Updated: 2017/09/30 14:57:15 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main5(int ac, int a, char **av, t_ls tab)
{
	while (a < ac)
	{
		if (av[a][ft_strlen(av[a]) - 1] == '/' &&
				av[a][0] != '/')
		{
			tab.path = av[a];
			tab.aff_bl = 42;
		}
		printf("%s\n", av[a]);
		ft_ls(ft_strdup(av[a]), tab);
		a++;
		if (a < ac)
			ft_print("\n");
	}
	return (0);
}

int			main4(int ac, int a, char **av, t_ls tab)
{
	if ((a - ac) < -1)
		return (main5(ac, a, av, tab));
	while (a < ac)
	{
		if (av[a][ft_strlen(av[a]) - 1] == '/' &&
				av[a][0] != '/')
		{
			tab.path = av[a];
			tab.aff_bl = 42;
		}
		ft_ls(ft_strdup(av[a]), tab);
		a++;
	}
	return (0);
}
