/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:30:22 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/01 13:30:20 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		valid_flag(char c, t_ls *tab)
{
	if (c == 'R')
		tab->br = 1;
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

int			check_flags(char *str, t_ls *tab)
{
	int		a;

	a = 0;
	if (str[2] == '-')
		return (illegal_option(str[2]));
	while (str[a])
	{
		if ((str[a] != 'a' && str[a] != 'l' && str[a] != 'r' && str[a] != 'R'
				&& str[a] != 't' && str[a] != '-') || (str[a] == '-' &&
					str[a + 1] == '-' && (str[a + 2] != ' ' &&
						str[a + 2] != '\0')))
			return (illegal_option(str[a]));
		valid_flag(str[a], tab);
		a++;
	}
	return (1);
}
