/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 14:35:40 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/28 18:25:17 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			free_all(s_ent *link)
{
	free(link->path);
	free(link->rights);
	free(link->size);
	free(link->nlink);
	//free(link->link);
	free(link->date);
	free(link->file->d_name);
	free(link->file);
	//free(link->usr);
	//free(link->group);
	free(link->gr_name);
	free(link->usr_name);
}

void			nul_all(s_ent *link)
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

void			erase_all(s_ent *list)
{
	while (list)
	{
		free_all(list);
		nul_all(list);
		list = list->next;
	}
}
