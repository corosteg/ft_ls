/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_file_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:21:36 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/09 17:36:58 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

s_ent		*assign_prev(s_ent *list, s_ent *tmp)
{
	s_ent	*elem;

	elem = list;
	while (elem->next != tmp)
		elem = elem->next;
	return (elem);
}

s_ent		*stock_info(s_ent *elem, struct dirent *ent, char *path)
{
	elem->next = NULL;
	elem->file = ent;
	if ((stat(ft_strjoin(path, elem->file->d_name), &elem->fstat)) == -1)
		error_print(path);
	elem->usr = getpwuid(elem->fstat.st_uid);
	elem->group = getgrgid(elem->fstat.st_gid);
	return (elem);
}

s_ent		*stock_files_info(s_ent *list, struct dirent *ent, char *path)
{
	s_ent		*tmp;
	char		*tmp2;

	tmp = list;
	if (list == NULL)
	{
		list = (s_ent*)malloc(sizeof(s_ent));
		list = stock_info(list, ent, path);
		list->prev = NULL;
		return (list);
	}
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = (s_ent*)malloc(sizeof(s_ent));
	tmp = tmp->next;
	tmp = stock_info(tmp, ent, path);
	tmp->prev = assign_prev(list, tmp);
	return (list);
}
