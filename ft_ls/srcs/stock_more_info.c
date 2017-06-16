/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_more_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:08:05 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/16 16:01:41 by corosteg         ###   ########.fr       */
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

char		*itoa_long(long long nb)
{
	int			i;
	char		*str;
	long long	tm;

	i = 0;
	tm = nb;
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	if (!(str = (char*)malloc(sizeof(str) * (i))))
		return (0);
	str[i] = '\0';
	nb = tm;
	while (i >= 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	return (str);
}

t_ls		stock_more_info(s_ent *list, t_ls tab)
{
	s_ent	*tmp;

	tmp = list;
	while(tmp)
	{
		tmp->usr = getpwuid(tmp->fstat.st_uid);
		tmp->group = getgrgid(tmp->fstat.st_gid);
		tmp->rights = type_infos(tmp);
		tmp->rights = rights_infos(tmp, tmp->rights);
		if (tab.a == 1)
			tab.blocks = tab.blocks + tmp->fstat.st_blocks;
		else if (tmp->file->d_name[0] != '.')
			tab.blocks = tab.blocks + tmp->fstat.st_blocks;
		tmp = tmp->next;
	}
	tab.cblocks = itoa_long(tab.blocks);
	itoa_space(list, 0, 0);
	date_conversion(list);
	return (tab);
}
