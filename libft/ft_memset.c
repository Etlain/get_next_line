/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:09:04 by mmouhssi          #+#    #+#             */
/*   Updated: 2015/11/25 17:59:05 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int n, size_t len)
{
	size_t			i;
	unsigned char	*tab;

	i = 0;
	tab = b;
	while (i < len)
	{
		tab[i] = (unsigned char)n;
		i++;
	}
	return (b);
}
