/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:54:04 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/01 19:43:03 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_ls.h"
#include <stdio.h>

int				main()
{
	int				i;
	DIR				*rep;
	struct dirent	*ent;
	char			*path;
	unsigned char	c;
	s_ent			*info;
	char			*tmp;

	path = ft_strdup("libft");
	rep = opendir(path);
	if (rep == NULL)
	{
		ft_print("ls: ");
		perror(&path[2]);
		return (0);
	}
	while ((ent = readdir(rep)))
	{
		//c = ent->d_type;
		//i = c;
		tmp = ft_strdup(path);
		if (ent->d_name[0] == '.' && ent->d_name[1] == '\0')
			stat("./", info->stat);
		else if (ent->d_name[0] == '.' && ent->d_name[1] == '.')
			stat("../", info->stat);
		else if (ent->d_type == 4)
			stat((ft_strjoin(tmp, "/") && ft_strjoin(tmp, ent->d_name)), info->stat);
		else
			stat(ft_strjoin(tmp, ent->d_name), info->stat);
		printf("%s : ", ent->d_name);
		printf("%lli\n", info->stat->st_size);
	}
	return (0);
}
