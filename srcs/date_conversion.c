/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:26:17 by corosteg          #+#    #+#             */
/*   Updated: 2017/09/29 17:07:32 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*change_date_year(char *str)
{
	char		*final;

	final = (char*)malloc(sizeof(char) * 13);
	final[12] = '\0';
	final[0] = str[8];
	final[1] = str[9];
	final[2] = ' ';
	final[3] = str[4] + 32;
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

	final = (char*)malloc(sizeof(char) * 13);
	final[12] = '\0';
	final[0] = str[8];
	final[1] = str[9];
	final[2] = ' ';
	final[3] = str[4] + 32;
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

int				check_date(time_t now, time_t mtime)
{
	if ((now - mtime) > 15724800)
		return (1);
	if (mtime > now)
		return (1);
	return (0);
}

void			date_conversion(t_ent *list)
{
	t_ent		*tmp;
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
			if (check_date(now, tmp->fstat.st_mtime))
				tmp->date = change_date_year(str);
			else
				tmp->date = change_date(str);
			free(str);
			free(str2);
		}
		tmp = tmp->next;
	}
}
