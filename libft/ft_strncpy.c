/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:28:14 by mmouhssi          #+#    #+#             */
/*   Updated: 2015/12/08 16:32:47 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, char *src, size_t n)
{
	size_t i;

	i = 0;
	ft_bzero(dst, n);
	while (i < n)
	{
		if (src[i] != '\0')
			dst[i] = src[i];
		else
			break ;
		i++;
	}
	return (dst);
}
