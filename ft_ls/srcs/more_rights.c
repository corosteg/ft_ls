/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_mor_rights.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 16:11:46 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/29 16:56:01 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*more_rights(s_ent *list, char *str)
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
