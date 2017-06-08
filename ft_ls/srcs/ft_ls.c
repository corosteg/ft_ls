/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 18:54:45 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/08 19:42:17 by corosteg         ###   ########.fr       */
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

s_ent		*stock_files_info(s_ent *list, struct dirent *ent, char *path)
{
	s_ent		*tmp;
	char		*tmp2;

	tmp = list;
	tmp2 = ft_strdup(path);
	if (list == NULL)
	{
		list = (s_ent*)malloc(sizeof(s_ent));
		list->next = NULL;
		list->file = ent;
		if ((stat(ft_strjoin(tmp2, list->file->d_name), &list->fstat)) == -1)
			error_print(tmp2);
		free(tmp2);
		return (list);
	}
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = (s_ent*)malloc(sizeof(s_ent));
	tmp = tmp->next;
	tmp->next = NULL;
	tmp->file = ent;
	if (stat(ft_strjoin(tmp2, tmp->file->d_name), &tmp->fstat) == -1)
		error_print(tmp2);
	free(tmp2);
	return (list);
}

void		print_list(s_ent *list)
{
	while (list)
	{
		printf("%s = %lli\n", list->file->d_name, list->fstat.st_size);
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
