/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 14:35:40 by corosteg          #+#    #+#             */
/*   Updated: 2017/09/29 17:20:52 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			free_all(t_ent *link)
{
	if (link->path)
		free(link->path);
	if (link->rights)
		free(link->rights);
	if (link->size)
		free(link->size);
	if (link->nlink)
		free(link->nlink);
	if (link->link)
		free(link->link);
	if (link->date)
		free(link->date);
	if (link->file->d_name)
		free(link->file->d_name);
	if (link->file)
		free(link->file);
	if (link->gr_name)
		free(link->gr_name);
	if (link->usr_name)
		free(link->usr_name);
}

void			nul_all(t_ent *link)
{
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
	link->usr = NULL;
	link->group = NULL;
	link->prev = NULL;
}

void			erase_all(t_ent *list)
{
	while (list)
	{
		free_all(list);
		nul_all(list);
		if (list->next == NULL)
		{
			free(list);
			list = NULL;
		}
		else
			list = list->next;
		if (list)
		{
			free(list->prev);
			list->prev = NULL;
		}
	}
}
