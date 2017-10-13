/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:06:39 by corosteg          #+#    #+#             */
/*   Updated: 2016/11/28 16:57:14 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int b;

	i = 0;
	b = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			b = i;
		i++;
	}
	if (s[i] == (char)c)
		return (char*)(&s[i]);
	if (b > -1)
		return (char*)(&s[b]);
	return (0);
}