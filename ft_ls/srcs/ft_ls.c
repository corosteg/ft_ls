/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 18:54:45 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/01 19:43:08 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		initialize_tab(t_ls *tab)
{
	tab->br = 0;
	tab->a = 0;
	tab->l = 0;
	tab->r = 0;
	tab->t = 0;
}

void		ft_ls(char *path, t_ls *tab)
{
	
}

int			main(int ac, char **av)
{
	int		a;
	char	*path;
	t_ls	*tab;

	a = 1;
	initialize_tab(tab);
	while (a < ac && av[a][0] == '-' && av[a][1] != '\0')
	{
		if (check_flags(av[a], tab) == 0)
			return (0);
		a++;
	}
	if (a == ac)
		ft_ls("./", tab);
	else
	{
		while (a < ac)
		{
			ft_ls(av[a], tab);
			a++;
		}
	}
	return (0);
}
