/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:13:07 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/16 15:51:23 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		simple_print(s_ent *list, t_ls tab)
{
	
}

int			l_print(s_ent *list, t_ls tab, int i)
{
	if (i == 0)
		ft_print("total %s\n", tab.cblocks);
	if (tab.a == 1)
		if (list->link == NULL)
			ft_print("%s  %s %s  %s  %s %s %s\n", list->rights, list->nlink,
				list->usr->pw_name, list->group->gr_name,
				list->size, list->date, list->file->d_name);
		else
			ft_print("%s  %s %s  %s  %s %s %s -> %s\n", list->rights,
				list->nlink, list->usr->pw_name, list->group->gr_name,
				list->size, list->date, list->file->d_name, list->link);
	else if (tab.a != 1 && list->file->d_name[0] != '.')
	{
		if (list->link == NULL)
			ft_print("%s  %s %s  %s  %s %s %s\n", list->rights, list->nlink,
				list->usr->pw_name, list->group->gr_name,
				list->size, list->date, list->file->d_name);
		else
			ft_print("%s  %s %s  %s  %s %s %s -> %s\n", list->rights,
				list->nlink, list->usr->pw_name, list->group->gr_name,
				list->size, list->date, list->file->d_name, list->link);
	}
	return (42);
}

void		ls_print(s_ent *list, t_ls tab, int i)
{
	if (tab.r == 1)
	{
		while (list->next)
			list = list->next;
		while (list)
		{
			if (tab.l == 1)
				i = l_print(list, tab, i);
			else
				simple_print(list, tab);
			list = list->prev;
		}
	}
	else
	{
		while (list)
		{
			if (tab.l == 1)
				i = l_print(list, tab, i);
			else
				simple_print(list, tab);
			list = list->next;
		}
	}
}
