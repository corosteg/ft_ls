/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:30:22 by corosteg          #+#    #+#             */
/*   Updated: 2017/09/27 18:00:21 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			check_uni(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 127)
			return (0);
		if (str[i] < 0)
			return (0);
		i++;
	}
	return (1);
}

t_ls		valid_flag(char c, t_ls tab)
{
	if (c == 'R')
		tab.br = 1;
	if (c == 'a')
		tab.a = 1;
	if (c == 'l')
		tab.l = 1;
	if (c == 'r')
		tab.r = 1;
	if (c == 't')
		tab.t = 1;
	return (tab);
}

t_ls		illegal_option(char c, t_ls tab)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ls [-Ratlr] [file ...]", 2);
	tab.zero = 1;
	return (tab);
}

t_ls		check_flags(char *str, t_ls tab)
{
	int		a;

	a = 0;
	if (str[2] == '-')
		return (illegal_option(str[2], tab));
	while (str[a])
	{
		if ((str[a] != 'a' && str[a] != 'l' && str[a] != 'r' && str[a] != 'R'
				&& str[a] != 't' && str[a] != '-') || (str[a] == '-' &&
					str[a + 1] == '-' && (str[a + 2] != ' ' &&
						str[a + 2] != '\0')))
			return (illegal_option(str[a], tab));
		tab = valid_flag(str[a], tab);
		a++;
	}
	return (tab);
}
