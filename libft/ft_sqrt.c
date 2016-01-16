/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 18:09:23 by mmouhssi          #+#    #+#             */
/*   Updated: 2015/08/11 14:28:13 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int i;
	int result;

	i = 0;
	result = 1;
	if (nb == 1)
		return (1);
	while (i <= nb)
	{
		if (result == nb)
		{
			return (i);
		}
		i++;
		if (nb != result)
		{
			result = i * i;
		}
		else
		{
			return (0);
		}
	}
	return (0);
}
