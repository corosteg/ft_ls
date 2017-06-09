/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_more_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:08:05 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/09 16:09:28 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

s_ent		*stock_more_info(s_ent *list)
{
	s_ent	*tmp;

	tmp = list;
	while(tmp)
	{
		tmp = tmp->next;
	}
	return (list);
}
