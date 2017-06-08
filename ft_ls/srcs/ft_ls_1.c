/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 15:07:35 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/07 17:48:31 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*change_path(char *path, char *name)
{
	if (ft_strcmp(name, ".") == 0)
	{
		//free(path);
		return (name);
	}
	if (ft_strcmp(name, "..") == 0)
	{
		//free(path);
		return (name);
	}
	return (ft_freejoin(path, name, 0));
}
