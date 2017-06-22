/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:26:17 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/22 17:37:14 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*change_date_year(char *str)
{
	char		*final;

	final = (char*)malloc(sizeof(char) * 12);
	final[12] = '\0';
	final[0] = str[8];
	final[1] = str[9];
	final[2] = ' ';
	final[3] = str[4];
	final[4] = str[5];
	final[5] = str[6];
	final[6] = ' ';
	final[7] = ' ';
	final[8] = str[20];
	final[9] = str[21];
	final[10] = str[22];
	final[11] = str[23];
	return (final);
}

char			*change_date(char *str)
{
	char		*final;

	final = (char*)malloc(sizeof(char) * 12);
	final[12] = '\0';
	final[0] = str[8];
	final[1] = str[9];
	final[2] = ' ';
	final[3] = str[4];
	final[4] = str[5];
	final[5] = str[6];
	final[6] = ' ';
	final[7] = str[11];
	final[8] = str[12];
	final[9] = str[13];
	final[10] = str[14];
	final[11] = str[15];
	return (final);
}

void			date_conversion(s_ent *list)
{
	s_ent		*tmp;
	char		*str;
	char		*str2;
	time_t		now;

	tmp = list;
	while (tmp)
	{
		if (tmp->i != 0)
		{
			str = ft_strdup(ctime(&tmp->fstat.st_mtime));
			now = time(NULL);
			str2 = ft_strdup(ctime(&now));
			if (ft_strcmp(&str[20], &str2[20]) != 0)
				tmp->date = change_date_year(str);
			else
				tmp->date = change_date(str);
			free(str);
			free(str2);
		}
		tmp = tmp->next;
	}
}
