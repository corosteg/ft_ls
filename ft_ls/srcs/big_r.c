/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 18:23:57 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/27 18:40:45 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		big_r_simple(s_ent *list, t_ls tab)
{
	if ((ft_strcmp(list->file->d_name, ".") != 0) 
		&& (ft_strcmp(list->file->d_name, "..") != 0)
		&& (list->file->d_name[0] != '.'))
	{
		ft_print("\n%s:\n", list->path);
		tab.blocks = 0;
		ft_ls(list->path, tab);
	}
}

void		big_r_a(s_ent *list, t_ls tab)
{
	if ((ft_strcmp(list->file->d_name, ".") != 0)
		&& (ft_strcmp(list->file->d_name, "..") != 0))
	{
		ft_print("\n%s:\n", list->path);
		tab.blocks = 0;
		ft_ls(list->path, tab);
	}
}

void		big_r(s_ent *list, t_ls tab)
{
	if (tab.r == 1)
		while (list->next)
			list = list->next;
	while (list)
	{
		if (tab.a == 1 && S_ISDIR(list->fstat.st_mode))
			big_r_a(list, tab);
		else if (S_ISDIR(list->fstat.st_mode))
			big_r_simple(list, tab);
		if (tab.r == 1)
			list = list->prev;
		else
			list = list->next;
	}
}
