/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:52:22 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/15 19:09:35 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*conversion(long long size, int i)
{
	char	*str;
	int		s;

	s = 0;
	str = (char*)malloc(sizeof(str) * i);
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

void			itoa_space(s_ent *list, long long size, long long nl)
{
	s_ent			*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->fstat.st_size > size)
			size = tmp->fstat.st_size;
		if (tmp->fstat.st_nlink > nl)
			nl = tmp->fstat.st_nlink;
		tmp = tmp->next;
	}
	tmp = list;
	while (tmp)
	{
		tmp->size = conversion(tmp->fstat.st_size, large_check(size));
		tmp->nlink = conversion(tmp->fstat.st_nlink, large_check(nl));
		tmp = tmp->next;
	}
}
