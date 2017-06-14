/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:13:07 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/14 17:34:47 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		simple_print(s_ent *list, t_ls tab)
{
	
}

void		l_print(s_ent *list, t_ls tab)
{
	if (tab.a == 1)
	{
		ft_print("%s  %d %s  %s  %d   %s\n", list->rights, list->fstat.st_nlink,
			list->usr->pw_name, list->group->gr_name,
			list->fstat.st_size, list->file->d_name);
	}
	else if (tab.a != 1 && list->file->d_name[0] != '.')
		ft_print("%s  %d %s  %s  %d   %s\n", list->rights, list->fstat.st_nlink,
			list->usr->pw_name, list->group->gr_name,
			list->fstat.st_size, list->file->d_name);

}

void		ls_print(s_ent *list, t_ls tab)
{
	if (tab.r == 1)
	{
		while (list->next)
			list = list->next;
		while (list)
		{
			if (tab.l == 1)
				l_print(list, tab);
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
				l_print(list, tab);
			else
				simple_print(list, tab);
			list = list->next;
		}
	}
}
