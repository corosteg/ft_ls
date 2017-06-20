/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:54:04 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/19 14:24:02 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_ls.h"
#include <stdio.h>

int				main(int ac, char **av)
{
	int				i;
	DIR				*rep;
	struct dirent	*ent;
	char			*path;
	unsigned char	c;
	s_ent			*info;
	char			*tmp;

	path = ft_strdup(av[1]);
	rep = opendir(path);
	if (rep == NULL)
	{
		ft_print("ls: ");
		perror(&path[2]);
		return (0);
	}
	while ((ent = readdir(rep)))
	{
		printf("%s\n", ent->d_name);
	}
	return (ac);
}
