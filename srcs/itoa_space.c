/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:52:22 by corosteg          #+#    #+#             */
/*   Updated: 2017/09/29 17:08:05 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*itoa_long(long long nb)
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

int				large_check(int size)
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

int				check_ma(t_ent *list)
{
	int		result;

	result = 0;
	while (list)
	{
		if (check_maj(list->fstat.st_rdev) > result)
			result = check_maj(list->fstat.st_rdev);
		list = list->next;
	}
	return (result);
}

void			itoa_space(t_ent *list, int size, int nl, t_ls tab)
{
	t_ent			*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->i && (tmp->rights[0] == 'c' || tmp->rights[0] == 'b'))
			size = check_large_spec(list, size);
		if (tab.a == 1 && tmp->i != 0)
		{
			if (large_check(tmp->fstat.st_size) > size)
				size = large_check(tmp->fstat.st_size);
			if (large_check(tmp->fstat.st_nlink > nl))
				nl = large_check(tmp->fstat.st_nlink);
		}
		else if (tmp->i != 0)
		{
			if (large_check(tmp->fstat.st_size) >
					size && tmp->file->d_name[0] != '.')
				size = large_check(tmp->fstat.st_size);
			nl = check_nl((large_check(tmp->fstat.st_nlink)), nl,
							tmp->file->d_name[0] != '.');
		}
		tmp = tmp->next;
	}
	itoa_space2(list, size, nl);
}
