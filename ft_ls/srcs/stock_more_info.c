/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_more_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:08:05 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/14 17:52:13 by corosteg         ###   ########.fr       */
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
		return ft_strdup("-");
	if (S_ISDIR(tmp->fstat.st_mode))
		return ft_strdup("d");
	if (S_ISLNK(tmp->fstat.st_mode))
		return ft_strdup("l");
	return ft_strdup("-");
}

s_ent		*more_infos(s_ent *tmp)
{
	tmp->rights = type_infos(tmp);
	tmp->rights = rights_infos(tmp, tmp->rights);
	return (tmp);
}

s_ent		*stock_more_info(s_ent *list)
{
	s_ent	*tmp;

	tmp = list;
	while(tmp)
	{
		tmp->usr = getpwuid(tmp->fstat.st_uid);
		tmp->group = getgrgid(tmp->fstat.st_gid);
		more_infos(tmp);
		tmp = tmp->next;
	}
	itoa_space(list);
	return (list);
}
