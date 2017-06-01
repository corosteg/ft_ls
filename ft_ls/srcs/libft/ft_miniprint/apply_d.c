/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:11:04 by corosteg          #+#    #+#             */
/*   Updated: 2017/05/31 16:30:16 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*resolve(long long nb, char *str)
{
	int		i;

	i = ft_strlen(str);
	while (nb > 9)
	{
		str[i] = ((nb % 10) + '0');
		nb = nb / 10;
		i--;
	}
	str[i] = ((nb % 10) + '0');
	return (str);
}

char		*apply_d(long long nb)
{
	int		i;
	int		a;
	char	*str;

	a = nb;
	i = 0;
	str = NULL;
	while (a > 9)
	{
		a = a / 10;
		i++;
	}
	//printf("\n i == %d nb == %lld\n", i, nb );
	str = (char*)ft_memalloc(i + 2);
	str[i + 1] = '\0';
	str = (char*)ft_memset(str, 'A', i + 1);
	return (resolve(nb, str));
}
