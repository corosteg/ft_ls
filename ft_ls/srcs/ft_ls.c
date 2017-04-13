/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 18:54:45 by corosteg          #+#    #+#             */
/*   Updated: 2017/04/13 17:37:48 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		initialize_tab(s_ls *tab)
{
	tab->R = 0;
	tab->a = 0;
	tab->l = 0;
	tab->r = 0;
	tab->t = 0;
}

int			main(int arc, char **arv)
{
	int		a;
	char	*path;
	s_ls	tab;

	a = 1;
	initialize_tab(&tab);
	if (arc == 1)
		path = ft_strdup("./");
	while (a < arc && arv[a][0] == '-' && arv[a][1] != '\0')
	{
		if (check_flags(arv[a], &tab) == 0)
			return (0);
		a++;
	}
}
