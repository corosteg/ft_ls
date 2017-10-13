/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_file_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:21:36 by corosteg          #+#    #+#             */
/*   Updated: 2017/09/29 17:18:53 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ent		*create_link(t_ent *link)
{
	link = (t_ent*)malloc(sizeof(t_ent));
	link->i = 42;
	link->path = NULL;
	link->rights = NULL;
	link->size = NULL;
	link->nlink = NULL;
	link->link = NULL;
	link->date = NULL;
	link->file = NULL;
	link->usr = NULL;
	link->group = NULL;
	link->gr_name = NULL;
	link->usr_name = NULL;
	link->file = NULL;
	link->next = NULL;
	link->usr = NULL;
	link->group = NULL;
	link->prev = NULL;
	return (link);
}

t_ent		*assign_prev(t_ent *list, t_ent *tmp)
{
	t_ent	*elem;

	elem = list;
	while (elem->next != tmp)
		elem = elem->next;
	return (elem);
}

int			check_link(t_ent *tmp)
{
	char	buf[256];
	int		ret;

	if ((ret = readlink(tmp->path, buf, 256)) != -1)
	{
		buf[ret] = '\0';
		tmp->link = ft_strdup(buf);
		return (1);
	}
	else
		tmp->link = NULL;
	return (0);
}

t_ent		*stock_info(t_ent *elem, struct dirent *ent, char *path, t_ls tab)
{
	elem->next = NULL;
	elem->file = malloc(sizeof(elem->file));
	elem->file->d_name = ft_strdup(ent->d_name);
	elem->path = ft_strfreejoin(path, elem->file->d_name, 0);
	if ((stat(elem->path, &elem->fstat)) == -1)
	{
		elem->i = error_print(elem->file->d_name, tab);
	}
	if (check_link(elem))
	{
		if ((lstat(elem->path, &elem->fstat)) == -1)
			elem->i = error_print(elem->file->d_name, tab);
		if (tab.l == 1)
		{
			elem->file->d_name = ft_strfreejoin(elem->file->d_name, " -> ", 1);
			elem->file->d_name =
				ft_strfreejoin(elem->file->d_name, elem->link, 1);
		}
	}
	return (elem);
}

t_ent		*stock_files_info(t_ent *list,
				struct dirent *ent, char *path, t_ls tab)
{
	t_ent		*tmp;

	tmp = list;
	if (list == NULL)
	{
		list = create_link(list);
		list = stock_info(list, ent, path, tab);
		list->prev = NULL;
		return (list);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_link(tmp);
	tmp = tmp->next;
	tmp = stock_info(tmp, ent, path, tab);
	tmp->prev = assign_prev(list, tmp);
	return (list);
}
