/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 18:55:48 by corosteg          #+#    #+#             */
/*   Updated: 2017/04/13 19:14:14 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <dirent.h>

typedef struct	s_ls
{
	int			br;
	int			a;
	int			l;
	int			r;
	int			t;
}				t_ls;

int				main(int arc, char **arv);
int				check_flags(char *str, s_ls *tabi);

#endif
