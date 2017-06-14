/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:52:22 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/14 18:24:05 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			itoa_space(s_ent *list)
{
	s_ent			*tmp;
	long long		l;

	l = 0;
	tmp = list;
	while (tmp)
	{
		if (tmp->fstat.st_size > l)
			l = tmp->fstat.st_size;
		tmp = tmp->next;
	}
}
