/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_more_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:08:05 by corosteg          #+#    #+#             */
/*   Updated: 2017/09/29 17:19:12 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*rights_infos(t_ent *tmp, char *str)
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
	return (ft_strfreejoin(str, str2, 3));
}

char		*type_infos(t_ent *tmp)
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
	return (ft_strdup("-"));
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

void		check_gr_usr_name(t_ent *list, size_t usr, size_t gr)
{
	t_ent	*tmp;

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

t_ls		stock_more_info(t_ent *list, t_ent *list2, t_ls tab)
{
	while (list)
	{
		if (list->i != 0)
		{
			if ((list->usr = getpwuid(list->fstat.st_uid)) == NULL)
				list->usr_name = ft_itoa(list->fstat.st_uid);
			else
				list->usr_name = ft_strdup(list->usr->pw_name);
			if ((list->group = getgrgid(list->fstat.st_gid)) == NULL)
				list->gr_name = ft_itoa(list->fstat.st_uid);
			else
				list->gr_name = ft_strdup(list->group->gr_name);
			list->rights = type_infos(list);
			list->rights = rights_infos(list, list->rights);
			list->rights = more_rights(list, list->rights);
			tab = check_blocks(tab, list->fstat.st_blocks,
					list->file->d_name[0]);
		}
		list = list->next;
	}
	tab.cblocks = itoa_long(tab.blocks);
	itoa_space(list2, 0, 0, tab);
	date_conversion(list2);
	check_gr_usr_name(list2, 0, 0);
	return (tab);
}
