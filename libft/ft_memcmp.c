/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:19:22 by mmouhssi          #+#    #+#             */
/*   Updated: 2015/11/25 16:38:32 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*tab;
	unsigned char	*tab2;
	size_t			i;

	i = 0;
	tab = (unsigned char*)str1;
	tab2 = (unsigned char*)str2;
	while (i < n)
	{
		if (tab[i] != tab2[i])
		{
			return (tab[i] - tab2[i]);
		}
		i++;
	}
	return (0);
}
