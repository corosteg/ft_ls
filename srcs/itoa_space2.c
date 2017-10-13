/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_space2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:12:58 by corosteg          #+#    #+#             */
/*   Updated: 2017/09/29 17:08:25 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			itoa_space2(t_ent *list, int size, int nl)
{
	int		ma;
	t_ent	*tmp;

	tmp = list;
	ma = check_ma(list);
	while (tmp)
	{
		if (tmp->i != 0 && tmp->rights[0] != 'c' && tmp->rights[0] != 'b')
		{
			tmp->size = conversion(tmp->fstat.st_size, (size - 1));
			tmp->nlink = conversion(tmp->fstat.st_nlink, nl);
		}
		if (tmp->i != 0 && (tmp->rights[0] == 'c' || tmp->rights[0] == 'b'))
		{
			tmp->nlink = conversion(tmp->fstat.st_nlink, nl);
			tmp->size = conversion(check_maj(tmp->fstat.st_rdev), (size - 1));
			tmp->size = conversion2(check_min(tmp->fstat.st_rdev), tmp->size,
						large_check(ma));
		}
		tmp = tmp->next;
	}
}

int				check_nl(int nl, int nl2, char c)
{
	if (nl < nl2 && c == '.')
		return (nl2);
	else
		return (nl);
}

t_ls			check_blocks(t_ls tab, long long blocks, char c)
{
	if (tab.a == 1)
		tab.blocks = tab.blocks + blocks;
	else if (c != '.')
		tab.blocks = tab.blocks + blocks;
	return (tab);
}
