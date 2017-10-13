/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_mor_rights.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 16:11:46 by corosteg          #+#    #+#             */
/*   Updated: 2017/09/29 17:22:00 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*more_rights(t_ent *list, char *str)
{
	if ((list->fstat.st_mode & S_ISUID) && str[3] == 'x')
		str[3] = 's';
	if ((list->fstat.st_mode & S_ISUID) && str[3] == '-')
		str[3] = 'S';
	if ((list->fstat.st_mode & S_ISGID) && str[6] == 'x')
		str[6] = 's';
	if ((list->fstat.st_mode & S_ISGID) && str[6] == '-')
		str[6] = 'S';
	if ((list->fstat.st_mode & S_ISVTX) && str[9] == 'x')
		str[9] = 't';
	if ((list->fstat.st_mode & S_ISVTX) && str[9] == '-')
		str[9] = 'T';
	return (str);
}

int			check_min(dev_t result)
{
	int i;

	i = result;
	while ((i / 256) > 0)
		i = i / 256;
	return (i);
}

int			check_maj(dev_t result)
{
	int a;

	a = result % 256;
	return (a);
}

int			check_large_spec(t_ent *tmp, int size)
{
	int		mi;
	int		ma;

	mi = 0;
	ma = 0;
	while (tmp)
	{
		if (large_check(check_min(tmp->fstat.st_rdev)) > mi)
			mi = large_check(check_min(tmp->fstat.st_rdev));
		if (large_check(check_maj(tmp->fstat.st_rdev)) > ma)
			ma = large_check(check_maj(tmp->fstat.st_rdev));
		tmp = tmp->next;
	}
	size = mi + ma + 4;
	return (size);
}

char		*conversion2(int mineur, char *size, int ma)
{
	int		i;

	i = ft_strlen(size);
	i = i - (ma + 4);
	size[i + 1] = ',';
	if (mineur == 0)
		size[i] = '0';
	else
		while (mineur > 0)
		{
			size[i] = (mineur % 10) + '0';
			mineur = mineur / 10;
			i--;
		}
	return (size);
}
