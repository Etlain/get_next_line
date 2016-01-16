/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:29:34 by mmouhssi          #+#    #+#             */
/*   Updated: 2015/11/24 18:44:11 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*tab;
	size_t			i;

	i = 0;
	tab = (unsigned char*)str;
	while (i < n)
	{
		if (tab[i] == (unsigned char)c)
		{
			return (&tab[i]);
		}
		i++;
	}
	return (NULL);
}
