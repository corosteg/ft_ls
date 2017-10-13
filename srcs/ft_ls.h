/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 18:55:48 by corosteg          #+#    #+#             */
/*   Updated: 2017/09/30 14:51:52 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "./libft/libft.h"
# include <uuid/uuid.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <dirent.h>
# include <grp.h>
# include <pwd.h>

typedef struct		s_ls
{
	int				ma;
	int				fbr;
	int				br;
	int				a;
	int				l;
	int				r;
	int				t;
	int				prpath;
	int				zero;
	int				aff_bl;
	int				s;
	long long		blocks;
	char			*cblocks;
	char			*path;
}					t_ls;

typedef struct		s_file
{
	char			*d_name;
}					t_file;

typedef	struct		s_ent
{
	char			*path;
	char			*rights;
	char			*size;
	char			*nlink;
	char			*link;
	char			*date;
	char			*gr_name;
	char			*usr_name;
	int				i;
	int				ma;
	struct s_file	*file;
	struct stat		fstat;
	struct s_ent	*next;
	struct passwd	*usr;
	struct group	*group;
	struct s_ent	*prev;
}					t_ent;

t_ls				check_flags(char *str, t_ls tab);
t_ent				*sort_list(t_ent *list, t_ls tab);
t_ent				*stock_files_info(t_ent *list, struct dirent *ent,
						char *pah, t_ls tab);
int					error_print(char *path, t_ls tab);
t_ls				stock_more_info(t_ent *list, t_ent *list2, t_ls tab);
int					check_uni(char *str);
void				ls_print(t_ent *list, t_ls tab);
void				itoa_space(t_ent *list, int size, int nl, t_ls tab);
char				*itoa_long(long long nb);
void				date_conversion(t_ent *list);
int					ft_ls(char *path, t_ls tab);
void				erase_all(t_ent *list);
void				big_r(t_ent *list, t_ls tab);
char				*more_rights(t_ent *list, char *str);
int					check_min(dev_t result);
int					check_maj(dev_t result);
int					check_large_spec_a(t_ent *tmp, int size);
void				itoa_space2(t_ent *list, int size, int nl);
int					check_large_spec(t_ent *tmp, int size);
int					large_check(int size);
char				*conversion2(int mineur, char *size, int ma);
char				*conversion(long long size, int i);
int					check_ma(t_ent *list);
int					check_nl(int nl, int nl2, char c);
t_ls				check_blocks(t_ls tab, long long blocks, char c);
int					main4(int ac, int a, char **av, t_ls tab);

#endif
