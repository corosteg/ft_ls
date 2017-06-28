/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 13:58:28 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/28 18:55:11 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		swap_list(s_ent *list, s_ent *tmp)
{
	struct file			*tmp_file;
	struct stat			tmp_fstat;
	char				*str;
	char				*tmp_link;

	str = list->path;
	tmp_link = list->link;
	tmp_file = list->file;
	tmp_fstat = list->fstat;
	list->link = tmp->link;
	list->fstat = tmp->fstat;
	list->file = tmp->file;
	list->path = tmp->path;
	tmp->link = tmp_link;
	tmp->file = tmp_file;
	tmp->fstat = tmp_fstat;
	tmp->path = str;
}

s_ent		*sort_simple(s_ent *list)
{
	s_ent		*tmp;
	s_ent		*tmp2;

	tmp = list;
	tmp2 = list;
	while (tmp2)
	{
		while (tmp)
		{
			if (ft_strcmp(tmp2->file->d_name, tmp->file->d_name) > 0)
				swap_list(tmp2, tmp);
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
		tmp = tmp2;
	}
	return (list);
}

s_ent		*sort_t(s_ent *list)
{
	s_ent		*tmp;
	s_ent		*tmp2;

	tmp = list;
	tmp2 = list;
	while (tmp2)
	{
		while (tmp)
		{
			if (tmp2->i != 0 && tmp->i != 0)
				if ((tmp2->fstat.st_mtime - tmp->fstat.st_mtime) < 0)
					swap_list(tmp2, tmp);
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
		tmp = tmp2;
	}
	return (list);
}

s_ent		*sort_list(s_ent *list, t_ls tab)
{
	if (tab.t == 1)
		return (sort_t(list));
	return (sort_simple(list));
}
