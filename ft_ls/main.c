/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:15:23 by corosteg          #+#    #+#             */
/*   Updated: 2017/04/11 17:59:42 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int arc, char **arv)
{
	DIR				*rep;
	struct dirent	*ent;
	struct stat		buf;
	char			*str;

	rep = NULL;
	str = NULL;
	if (arc == 1)
		return (0);
	rep = opendir(arv[1]);
	if (rep == NULL)
		perror("opendir");
	ent = readdir(rep);
	ft_putstr(arv[1]);
	stat("./toto", &buf);
	ft_putstr("\n");
	ft_putstr(ctime(&buf.st_ctime));
	return (0);
}
