/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:13:07 by corosteg          #+#    #+#             */
/*   Updated: 2017/09/29 21:44:36 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			simple_print(t_ent *list, t_ls tab)
{
	if (list->i == 0)
		return (0);
	if (tab.a == 0 && list->file->d_name[0] == '.')
		return (0);
	ft_print("%s\n", list->file->d_name);
	return (0);
}

t_ls		l_print(t_ent *list, t_ls tab)
{
	if (tab.a == 1)
	{
		if (tab.s != 42)
		{
			ft_print("total %s\n", tab.cblocks);
			tab.s = 42;
		}
		ft_print("%s %s %s  %s  %s %s %s\n", list->rights, list->nlink,
			list->usr_name, list->gr_name,
			list->size, list->date, list->file->d_name);
	}
	else if (tab.a != 1 && list->file->d_name[0] != '.')
	{
		if (tab.s != 42)
		{
			ft_print("total %s\n", tab.cblocks);
			tab.s = 42;
		}
		ft_print("%s %s %s  %s  %s %s %s\n", list->rights, list->nlink,
			list->usr_name, list->gr_name,
			list->size, list->date, list->file->d_name);
	}
	return (tab);
}

void		ls_print2(t_ent *list, t_ls tab)
{
	while (list)
	{
		if (tab.l == 1 && (list->i != 0))
			tab = l_print(list, tab);
		else if (list->i != 0)
			simple_print(list, tab);
		list = list->next;
	}
}

void		ls_print(t_ent *list, t_ls tab)
{
	if (tab.r == 1)
	{
		while (list->next)
			list = list->next;
		while (list)
		{
			if (tab.l == 1 && (list->i != 0))
				tab = l_print(list, tab);
			else if (list->i != 0)
				simple_print(list, tab);
			list = list->prev;
		}
	}
	else
		ls_print2(list, tab);
}
