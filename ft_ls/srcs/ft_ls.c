/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 18:54:45 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/29 16:42:47 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			error_print(char *path, t_ls tab)
{
	if (tab.a == 1 || path[0] != '.')
	{
		ft_print("ft_ls: ");
		if (!ft_strncmp(path, "./", 2))
			perror(&path[2]);
		if (ft_strncmp(path, "./", 2))
			perror(path);
	}
	else
		return (0);
	return (0);
}

t_ls		initialize_tab(t_ls tab)
{
	tab.br = 0;
	tab.a = 0;
	tab.l = 0;
	tab.r = 0;
	tab.t = 0;
	tab.prpath = 0;
	tab.blocks = 0;
	tab.zero = 0;
	tab.cblocks = NULL;
	tab.err_name = NULL;
	return (tab);
}

int			ft_ls(char *path, t_ls tab)
{
	DIR				*rep;
	s_ent			*list;
	struct dirent	*ent;

	list = NULL;
	if (path[ft_strlen(path) - 1] != '/')
		path = ft_strfreejoin(path, "/", 0);
	if ((rep = opendir(path)) == NULL)
		return (error_print(path, tab));
	while ((ent = readdir(rep)))
		list = stock_files_info(list, ent, path, tab);
	list = sort_list(list, tab);
	tab = stock_more_info(list, list, tab);
	ls_print(list, tab, 0);
	if (tab.br == 1)
		big_r(list, tab);
	closedir(rep);
	erase_all(list);
	free(tab.cblocks);
	tab.cblocks = NULL;
	free(path);
	return (0);
}

int			main(int ac, char **av)
{
	int		a;
	t_ls	tab;

	a = 1;
	tab = initialize_tab(tab);
	while (a < ac && av[a][0] == '-' && av[a][1] != '\0')
	{
		tab = check_flags(av[a], tab);
		if (tab.zero == 1)
			return (0);
		a++;
	}
	if (a == ac)
		ft_ls(ft_strdup("./"), tab);
	else
		while (a < ac)
		{
				ft_ls(ft_strdup(av[a]), tab);
			a++;
		}
	return (0);
}
