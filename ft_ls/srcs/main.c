/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:54:04 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/07 18:22:42 by corosteg         ###   ########.fr       */
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
		//c = ent->d_type;
		//i = c;
		tmp = ft_strdup(path);
		if (ent->d_name[0] == '.' && ent->d_name[1] == '\0')
			stat(".", info->fstat);
		else if (ent->d_name[0] == '.' && ent->d_name[1] == '.')
			stat("..", info->fstat);
		else if (ent->d_type == 4)
		{
			ft_strjoin(tmp, "/");
			stat(ft_strjoin(path, ent->d_name), info->fstat);
		}
		else
			stat(ft_strjoin(tmp, ent->d_name), info->fstat);
		printf("%s : ", ent->d_name);
		printf("%lli       type : %d       inode : %lli\n",
				info->fstat->st_size, ent->d_type, ent->d_ino);
		/* lien symbolique d_type(lli)8, lien physique d_type(lli)10*/
	}
	return (ac);
}
