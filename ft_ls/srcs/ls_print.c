/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:13:07 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/27 19:12:11 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			simple_print(s_ent *list, t_ls tab)
{
	if (list->i == 0)
		return (0);
	ft_print("%s, ", list->file->d_name);
	return (0);
}

int			l_print(s_ent *list, t_ls tab, int i)
{
	if (list->i == 0)
		return (0);
	if (tab.a == 1)
		if (list->link == NULL)
		{
			if (i == 0)
				ft_print("total %s\n", tab.cblocks);
			ft_print("%s %s %s  %s  %s %s %s\n", list->rights, list->nlink,
				list->usr_name, list->gr_name,
				list->size, list->date, list->file->d_name);
		}
		else
		{
			if (i == 0)
				ft_print("total %s\n", tab.cblocks);
			ft_print("%s %s %s  %s  %s %s %s -> %s\n", list->rights,
				list->nlink, list->usr_name, list->gr_name,
				list->size, list->date, list->file->d_name, list->link);
		}
	else if (tab.a != 1 && list->file->d_name[0] != '.')
	{
		if (list->link == NULL)
		{
			if (i == 0)
				ft_print("total %s\n", tab.cblocks);
			ft_print("%s %s %s  %s  %s %s %s\n", list->rights, list->nlink,
				list->usr_name, list->gr_name,
				list->size, list->date, list->file->d_name);
		}
		else
		{
			if (i == 0)
				ft_print("total %s\n", tab.cblocks);
			ft_print("%s %s %s  %s  %s %s %s -> %s\n", list->rights,
				list->nlink, list->usr_name, list->gr_name,
				list->size, list->date, list->file->d_name, list->link);
		}
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
	if (tab.l == 0)
		ft_print("\n");
}
