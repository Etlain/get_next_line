/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:04:32 by mmouhssi          #+#    #+#             */
/*   Updated: 2015/12/15 13:19:52 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"

/*
char	*ft_buf(char **line, char *buf)
{
	while (line[i] != '\0' && line[i] != buf[0])
	{
		if (line[i] == buf[0])
			ft_buf(line, buf);
		i++;
	}
}
*/
int	get_next_line(int const fd, char **line)
{
	char buf[BUFF_SIZE + 1];
	int	i;
	int j;

	j = 0;
	while (read(fd, buf, BUFF_SIZE) != 0)
	{
		i = 0;
		while (buf[i] != '\n' && buf[i] != EOF && i < BUFF_SIZE)
		{
			i++;
		}
		ft_strncat(*line, buf, i);
		if (buf[i] == '\n' || buf[i] == EOF)
		{
			return (1);
		}
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	return (0);
}

int	main()
{
	int f;
	char **tab;
	char buf[BUFF_SIZE];
	char *t;
	int i;
	
	i = 0;
	tab =(char **)malloc(sizeof(char *) * 5);
	while (i < 5)
	{
		tab[i] = (char *)malloc(100);
		ft_bzero(tab[i], 100);
		i++;
	}
	tab[5] = NULL;
	ft_bzero(buf, BUFF_SIZE);
	f = open("test", O_RDONLY);
	/*read(f, buf, BUFF_SIZE - 1);
	ft_putstr(buf);*/
	get_next_line(f, tab);
	//ft_putendl_tab(tab);
	get_next_line(f, &(tab[1]));
	ft_putendl_tab(tab);
	free(t);
	t = NULL;
}
