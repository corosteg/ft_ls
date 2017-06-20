/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_file_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:21:36 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/20 16:04:26 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

s_ent		*create_link(s_ent *link)
{
	link = (s_ent*)malloc(sizeof(s_ent));
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
	return (link);
}

s_ent		*assign_prev(s_ent *list, s_ent *tmp)
{
	s_ent	*elem;

	elem = list;
	while (elem->next != tmp)
		elem = elem->next;
	return (elem);
}

int			check_link(s_ent *tmp)
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

s_ent		*stock_info(s_ent *elem, struct dirent *ent, char *path)
{
	elem->next = NULL;
	elem->file = (file*)malloc(sizeof(file));
	elem->file->d_name = ft_strdup(ent->d_name);
	if ((stat(ft_strjoin(path, elem->file->d_name), &elem->fstat)) == -1)
		error_print(path);
	elem->path = ft_strjoin(path, elem->file->d_name);
	if (check_link(elem))
		if ((lstat(elem->path, &elem->fstat)) == -1)
			error_print(path);
	return (elem);
}

s_ent		*stock_files_info(s_ent *list, struct dirent *ent, char *path)
{
	s_ent		*tmp;
	char		*tmp2;

	tmp = list;
	if (list == NULL)
	{
		list = create_link(list);
		list = stock_info(list, ent, path);
		list->prev = NULL;
		return (list);
	}
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = create_link(tmp);
	tmp = tmp->next;
	tmp = stock_info(tmp, ent, path);
	tmp->prev = assign_prev(list, tmp);
	return (list);
}
