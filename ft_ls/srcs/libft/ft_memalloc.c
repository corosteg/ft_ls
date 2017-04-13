/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:56:44 by corosteg          #+#    #+#             */
/*   Updated: 2016/11/18 16:27:20 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;

	mem = (unsigned char*)malloc(size * sizeof(size));
	if (mem == 0)
		return (0);
	ft_memset(mem, 0, size);
	return (mem);
}
