/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 18:54:45 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/03 16:49:10 by corosteg         ###   ########.fr       */
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

s_ent		*stock_files_info(s_ent *list, DIR *rep)
{
	s_ent		*tmp;

	tmp = list;
	while(tmp)
		tmp = tmp->next;
	tmp = (s_ent*)malloc(sizeof(s_ent));
	tmp->next = NULL;
	return (tmp);
}

/*char		*change_path(char *path)
{
	char	*str;
	int		i;
	int		a;

	a = 2;
	i = 0;
	str = ft_strdup("./");
	while (path[i])
	{
		str[a] = path[i];
		a++;
		i++;
	}
	return (str);
}*/

int			error_print(char *path)
{
		ft_print("ls: ");
	if (!ft_strncmp(path, "./", 2))
		perror(&path[2]);
	if (ft_strncmp(path, "./", 2))
		perror(path);
	return (0);
}

int			ft_ls(char *path, t_ls *tab)
{
	DIR			*rep;
	s_ent		*list;

	tab = NULL;
	list = NULL;
	if (!(rep = opendir(path)))
		return (error_print(path));
	while ((ent = readdir(rep)))
	{
		list = stock_files_info(list, ent);
		if (tab->t == 1)
			list = sort_list(list);
	}
	return (0);
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
