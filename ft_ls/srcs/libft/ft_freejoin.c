/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freejoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:19:55 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/07 17:28:45 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_freejoin(char const *s1, char const *s2, int f)
{
	int		a;
	char	*str;

	if (s1 == 0 || s2 == 0)
		return (0);
	a = (ft_strlen(s1) + ft_strlen(s2));
	if (!(str = ((char*)malloc(sizeof(char) * (a +1)))))
		return (0);
	ft_strcpy(str, s1);
	ft_strcpy(str, s2);
	if (f == 1)
		free((void*)s1);
	if (f == 2)
		free((void*)s2);
	if (f == 3)
	{
		free((void*)s1);
		free((void*)s2);
	}
	return (str);
}
