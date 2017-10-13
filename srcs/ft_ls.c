/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 18:54:45 by corosteg          #+#    #+#             */
/*   Updated: 2017/09/30 14:51:36 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			error_print(char *path, t_ls tab)
{
	int		i;

	i = ft_strlen(path);
	i--;
	if (path[i] == '/')
	{
		path[i] = '\0';
		i--;
	}
	while (path[i] && path[i] != '/')
		i--;
	if (tab.a == 1 || path[0] != '.')
	{
		ft_print("ft_ls: ");
		if (!ft_strncmp(path, "./", 2))
			perror(&path[2]);
		if (ft_strncmp(path, "./", 2))
			perror(&path[i + 1]);
	}
	else
	{
		ft_print("ft_ls: ");
		perror(&path[i + 1]);
	}
	return (0);
}

int			ft_ls(char *path, t_ls tab)
{
	DIR				*rep;
	t_ent			*list;
	struct dirent	*ent;

	list = NULL;
	if (path[ft_strlen(path) - 1] != '/')
		path = ft_strfreejoin(path, "/", 0);
	if ((rep = opendir(path)) == NULL)
		return (error_print(path, tab));
	while ((ent = readdir(rep)))
		if (check_uni(ent->d_name))
			list = stock_files_info(list, ent, path, tab);
	list = sort_list(list, tab);
	tab = stock_more_info(list, list, tab);
	ls_print(list, tab);
	if (tab.br == 1)
		big_r(list, tab);
	closedir(rep);
	erase_all(list);
	free(tab.cblocks);
	tab.cblocks = NULL;
	free(path);
	return (0);
}

int			main3(int ac, int a, char **av, t_ls tab)
{
	while (a < ac)
	{
		if (av[ac - 1][ft_strlen(av[ac - 1]) - 1] == '/' &&
				av[ac - 1][0] != '/')
		{
			tab.path = av[ac - 1];
			tab.aff_bl = 42;
		}
		ft_ls(ft_strdup(av[ac - 1]), tab);
		ac--;
	}
	return (0);
}

int			main2(int ac, int a, char **av, t_ls tab)
{
	if ((a - ac) < -1)
		while (a < ac)
		{
			if (av[ac - 1][ft_strlen(av[ac - 1]) - 1] == '/' &&
					av[ac - 1][0] != '/')
			{
				tab.path = av[ac - 1];
				tab.aff_bl = 42;
			}
			ft_print("%s:\n", av[ac - 1]);
			ft_ls(ft_strdup(av[ac - 1]), tab);
			ac--;
			if (a < ac)
				ft_print("\n", av[ac - 1]);
		}
	else
		return (main3(ac, a, av, tab));
	return (0);
}

int			main(int ac, char **av)
{
	int		a;
	t_ls	tab;

	a = 1;
	tab = (t_ls){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL};
	while (a < ac && av[a][0] == '-' && av[a][1] != '\0')
	{
		tab = check_flags(av[a], tab);
		if (tab.zero == 1)
			return (1);
		a++;
	}
	if (a == ac)
		ft_ls(ft_strdup("./"), tab);
	else if (tab.r == 0)
		return (main2(ac, a, av, tab));
	else
		return (main4(ac, a, av, tab));
	return (0);
}
