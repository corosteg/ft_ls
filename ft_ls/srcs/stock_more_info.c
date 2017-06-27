/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_more_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:08:05 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/27 16:14:24 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*rights_infos(s_ent *tmp, char *str)
{
	char	*str2;

	str2 = ft_strdup("---------");
	if (tmp->fstat.st_mode & S_IRUSR)
		str2[0] = 'r';
	if (tmp->fstat.st_mode & S_IWUSR)
		str2[1] = 'w';
	if (tmp->fstat.st_mode & S_IXUSR)
		str2[2] = 'x';
	if (tmp->fstat.st_mode & S_IRGRP)
		str2[3] = 'r';
	if (tmp->fstat.st_mode & S_IWGRP)
		str2[4] = 'w';
	if (tmp->fstat.st_mode & S_IXGRP)
		str2[5] = 'x';
	if (tmp->fstat.st_mode & S_IROTH)
		str2[6] = 'r';
	if (tmp->fstat.st_mode & S_IWOTH)
		str2[7] = 'w';
	if (tmp->fstat.st_mode & S_IXOTH)
		str2[8] = 'x';
	return (ft_strjoin(str, str2));
}

char		*type_infos(s_ent *tmp)
{
	if (S_ISREG(tmp->fstat.st_mode))
		return (ft_strdup("-"));
	if (S_ISDIR(tmp->fstat.st_mode))
		return (ft_strdup("d"));
	if (S_ISLNK(tmp->fstat.st_mode))
		return (ft_strdup("l"));
	if (S_ISCHR(tmp->fstat.st_mode))
		return (ft_strdup("c"));
	if (S_ISBLK(tmp->fstat.st_mode))
		return (ft_strdup("b"));
	if (S_ISFIFO(tmp->fstat.st_mode))
		return (ft_strdup("p"));
	if (S_ISSOCK(tmp->fstat.st_mode))
		return (ft_strdup("s"));
	return ft_strdup("-");
}

char		*allocate_with_space(char *name, int i)
{
	int			max;
	char		*final;

	final = (char*)malloc(sizeof(char) * (i + 1));
	final[i] = '\0';
	max = i;
	i = 0;
	while (name[i])
	{
		final[i] = name[i];
		i++;
	}
	while (i < max)
	{
		final[i] = ' ';
		i++;
	}
	free(name);
	return (final);
}

void		check_gr_usr_name(s_ent *list)
{
	int		gr;
	int		usr;
	s_ent	*tmp;

	gr = 0;
	usr = 0;
	tmp = list;
	while (tmp)
	{
		if (tmp->i != 0)
		{
			if (gr < ft_strlen(tmp->gr_name))
				gr = ft_strlen(tmp->gr_name);
			if (usr < ft_strlen(tmp->usr_name))
				usr = ft_strlen(tmp->usr_name);
		}
		tmp = tmp->next;
	}
	while (list)
	{
		if (list->i != 0)
		{
			list->gr_name = allocate_with_space(list->gr_name, gr);
			list->usr_name = allocate_with_space(list->usr_name, usr);
		}
		list = list->next;
	}
}

t_ls		stock_more_info(s_ent *list, t_ls tab)
{
	s_ent	*tmp;

	tmp = list;
	while(tmp)
	{
		if (tmp->i != 0)
		{
			tmp->usr = getpwuid(tmp->fstat.st_uid);
			tmp->usr_name = ft_strdup(tmp->usr->pw_name);
			tmp->group = getgrgid(tmp->fstat.st_gid);
			tmp->gr_name = ft_strdup(tmp->group->gr_name);
			tmp->rights = type_infos(tmp);
			tmp->rights = rights_infos(tmp, tmp->rights);
			if (tab.a == 1)
				tab.blocks = tab.blocks + tmp->fstat.st_blocks;
			else if (tmp->file->d_name[0] != '.')
				tab.blocks = tab.blocks + tmp->fstat.st_blocks;
		}
		tmp = tmp->next;
	}
	tab.cblocks = itoa_long(tab.blocks);
	itoa_space(list, 0, 0, tab);
	date_conversion(list);
	check_gr_usr_name(list);
	return (tab);
}
