/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:04:32 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/01/10 02:10:41 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"

int			get_next_line(int const fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*str;
	int			i;

	if (!str)
	{
		str = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
		ft_bzero(str, BUFF_SIZE + 1);
	}
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	ft_bzero(buff, BUFF_SIZE + 1);
	if (str[i] != '\n')
	{
		while (read(fd, buff, BUFF_SIZE) != 0)
		{
			i = 0;
			str = ft_strjoin(str, buff);
			while (str[i] != '\n' && str[i] != '\0')
				i++;
			if (str[i] == '\n')
				break ;
			ft_bzero(buff, BUFF_SIZE);
		}
	}
	*line = (char *)malloc(i + 1);
	ft_bzero(*line, i + 1);
	ft_strncat(*line, str, i);
	if (str[0] != '\0')
		str = ft_strsub(str, i + 1, ft_strlen(str) - i);
	return (0);
}
/*
int			main()
{
	int f;
	char **tab;
	//char buf[BUFF_SIZE];
	int i;
	
	i = 0;
	tab =(char **)malloc(sizeof(char *) * 147);
	f = open("get_next_line_V2.c", O_RDONLY);
	while (i < 147)
	{
		tab[i] = (char *)malloc(100);
		ft_bzero(tab[i], 100);
		get_next_line(f, &tab[i]);
		i++;
	}
	tab[147] = NULL;
	//ft_bzero(buf, BUFF_SIZE);
	//read(f, buf, BUFF_SIZE - 1);
	//get_next_line(f, tab);
	//get_next_line(f, &(tab[1]));
	//ft_putendl_tab(tab);
	//ft_putstr(tab[0]);
	//ft_putchar('\n');
	//ft_putstr(tab[1]);
	ft_putendl_tab(tab);
}*/
