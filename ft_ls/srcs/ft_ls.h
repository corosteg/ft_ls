/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 18:55:48 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/08 19:41:32 by corosteg         ###   ########.fr       */
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

typedef struct		t_ls
{
	int				br;
	int				a;
	int				l;
	int				r;
	int				t;
	int				zero;
}					t_ls;

typedef	struct		s_ent
{
	struct dirent	*file;
	struct stat		fstat;
	struct s_ent	*next;
}					s_ent;

int				main(int arc, char **arv);
t_ls			check_flags(char *str, t_ls tab);
s_ent			*sort_list(s_ent *list, t_ls tab);
char			*change_path(char *path, char *name);

#endif
