/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_date.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:08:29 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/15 15:25:28 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.c"

void			ft_check_date(s_ent *list)
{
	s_ent		*tmp;

	tmp = list;
	while (tmp)
	{
		tmp->date = ctime(&tmp->fstat.st_mtime);
		tmp = tmp->next;
	}
}
