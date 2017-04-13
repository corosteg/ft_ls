/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 18:54:45 by corosteg          #+#    #+#             */
/*   Updated: 2017/04/13 19:16:04 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		initialize_tab(t_ls *tab)
{
	tab->br = 0;
	tab->a = 0;
	tab->l = 0;
	tab->r = 0;
	tab->t = 0;
}

int			main(int arc, char **arv)
{
	int		a;
	char	*path;
	t_ls	tab;

	a = 1;
	initialize_tab(&tab);
	while (a < arc && arv[a][0] == '-' && arv[a][1] != '\0')
	{
		if (check_flags(arv[a], &tab) == 0)
			return (0);
		a++;
	}
	if (a == arc)
		path = ft_strdup("./");
}
