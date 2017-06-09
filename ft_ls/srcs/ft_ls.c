/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 18:54:45 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/09 17:57:50 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			error_print(char *path)
{
		ft_print("ft_ls: ");
	if (!ft_strncmp(path, "./", 2))
		perror(&path[2]);
	if (ft_strncmp(path, "./", 2))
		perror(path);
	return (0);
}

t_ls		initialize_tab(t_ls tab)
{
	tab.br = 0;
	tab.a = 0;
	tab.l = 0;
	tab.r = 0;
	tab.t = 0;
	return (tab);
}

void		print_list(s_ent *list)
{
	while (list)
	{
		if (S_ISREG(list->fstat.st_mode))
			printf ("is file ");
		//if (S_IRSUR == list->fstat.st_mode)
		//	printf ("droit de lecture ");
		printf("%s = %s\n", list->file->d_name, ctime(&list->fstat.st_mtime));
		list = list->next;
	}
}

int			ft_ls(char *path, t_ls tab)
{
	DIR				*rep;
	s_ent			*list;
	struct dirent	*ent;

	list = NULL;
	if (!(rep = opendir(path)))
		return (error_print(path));
	while ((ent = readdir(rep)))
		list = stock_files_info(list, ent, path);
	list = sort_list(list, tab);
	print_list(list);
	return (0);
}

int			main(int ac, char **av)
{
	int		a;
	t_ls	tab;

	a = 1;
	initialize_tab(tab);
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
