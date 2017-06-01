/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:11:15 by corosteg          #+#    #+#             */
/*   Updated: 2017/05/30 17:15:12 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*apply_s(wchar_t *str)
{
	char	*final;

	if (str == NULL)
		return (NULL);
	final = ft_strdup((char*)str);
	return (final);
}
