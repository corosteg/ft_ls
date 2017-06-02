/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 18:54:45 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/02 18:10:48 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls		*initialize_tab(t_ls *tab)
{
	tab->br = 0;
	tab->a = 0;
	tab->l = 0;
	tab->r = 0;
	tab->t = 0;
	return (tab);
}

s_ent		*stock_files_info(s_ent *list, char *path)
{
	s_ent		*tmp;

	path = NULL;
	tmp = list;
	while(tmp)
		tmp = tmp->next;
	tmp = (s_ent*)malloc(sizeof(s_ent));
	tmp->next = NULL;
	return (tmp);
}

void		ft_ls(char *path, t_ls *tab)
{
	s_ent		*list;

	tab = NULL;
	list = NULL;
	list = stock_files_info(list, path);
}

int			main(int ac, char **av)
{
	int		a;
	t_ls	*tab;

	a = 1;
	tab = (t_ls*)malloc(sizeof(tab));
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
		while (a < ac)
		{
			ft_ls(av[a], tab);
			a++;
		}
	return (0);
}
