/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 18:54:45 by corosteg          #+#    #+#             */
/*   Updated: 2017/04/13 17:27:50 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		valid_flag(char c, s_ls *tab)
{
	if (c == 'R')
		tab->R = 1;
	if (c == 'a')
		tab->a = 1;
	if (c == 'l')
		tab->l = 1;
	if (c == 'r')
		tab->r = 1;
	if (c == 't')
		tab->t = 1;
}

int			illegal_option(char c)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\nusage: ls [-Ralrt] [file ...]\n");
	return (0);
}

int			check_flags(char *str, s_ls *tab)
{
	int		a;

	a = 0;
	if (str[2] == '-')
		return (illegal_option(str[2]));
	while (str[a])
	{
		if (str[a] != 'a' && str[a] != 'l' && str[a] != 'r' && str[a] != 'R'
				&& str[a] != 't' && str[a] != '-')
			return (illegal_option(str[a]));
		valid_flag(str[a], tab);
		a++;
	}
	return (1);
}

void		initialize_tab(s_ls *tab)
{
	tab->R = 0;
	tab->a = 0;
	tab->l = 0;
	tab->r = 0;
	tab->t = 0;
}

#include <stdio.h>

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
		printf("R = %d, a = %d, l = %d, r = %d, t = %d\n", tab.R, tab.a,
				tab.l, tab.r, tab.t);
	}
}
