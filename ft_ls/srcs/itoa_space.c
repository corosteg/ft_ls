/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:52:22 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/27 16:03:36 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
	if (!(str = (char*)malloc(sizeof(str) * (i + 1))))
		return (0);
	str[i + 1] = '\0';
	nb = tm;
	while (i >= 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	return (str);
}

char			*conversion(long long size, int i)
{
	char	*str;
	int		s;

	s = 0;
	i++;
	str = (char*)malloc(sizeof(char) * (i + 2));
	if (str == NULL)
		return (0);
	str[i + 1] = '\0';
	while (i >= 0)
	{
	
		str[i] = (size % 10) + '0';
		size = size / 10;
		i--;
	}
	while (str[s] == '0' && str[s + 1] != '\0')
	{
		str[s] = ' ';
		s++;
	}
	return (str);
}

int				large_check(long long size)
{
	int		i;

	i = 0;
	while (size >= 10)
	{
		size = size / 10;
		i++;
	}
	return (i);
}

void			itoa_space(s_ent *list, long long size, long long nl, t_ls tab)
{
	s_ent			*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->i != 0)
		{
			if (tab.a == 1)
			{
				if (tmp->fstat.st_size > size)
					size = tmp->fstat.st_size;
				if (tmp->fstat.st_nlink > nl)
					nl = tmp->fstat.st_nlink;
			}
			else
			{
				if (tmp->fstat.st_size > size && tmp->file->d_name[0] != '.')
					size = tmp->fstat.st_size;
				if (tmp->fstat.st_nlink > nl && tmp->file->d_name[0] != '.')
					nl = tmp->fstat.st_nlink;
			}
		}
		tmp = tmp->next;
	}
	tmp = list;
	while (tmp)
	{
		if (tmp->i != 0)
		{
			tmp->size = conversion(tmp->fstat.st_size, (large_check(size)) - 1);
			tmp->nlink = conversion(tmp->fstat.st_nlink, large_check(nl));
		}
		tmp = tmp->next;
	}
}
