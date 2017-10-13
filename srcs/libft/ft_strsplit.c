/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:28:08 by paoroste          #+#    #+#             */
/*   Updated: 2016/11/29 17:39:03 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(char const *s, char c)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			if (s[i] == '\0')
				i--;
			a++;
		}
		i++;
	}
	return (a);
}

static int		ft_del(int i, int c, const char *s)
{
	while (s[i] == c)
		i++;
	return (i);
}

static char		**ft_split(char **tab, int a, int c, const char *s)
{
	int		i;
	int		b;
	int		count;

	i = 0;
	b = 0;
	count = 0;
	while (count < a)
	{
		tab[count] = ft_strdup(s);
		i = ft_del(i, c, s);
		while (s[i] != c && s[i] != '\0')
		{
			tab[count][b] = s[i];
			i++;
			b++;
		}
		tab[count][b] = '\0';
		tab[count] = ft_strdup(tab[count]);
		b = 0;
		count++;
		i++;
	}
	tab[count] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	int		a;
	int		b;
	char	**tab;

	if (s == 0)
		return (0);
	b = 0;
	a = ft_len(s, c);
	tab = (char**)malloc(sizeof(char*) * (a + 1));
	if (tab == 0)
		return (0);
	tab = ft_split(tab, a, c, s);
	return (tab);
}
