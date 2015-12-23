/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:04:32 by mmouhssi          #+#    #+#             */
/*   Updated: 2015/12/21 11:10:59 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"

int		ft_strlen_gnl(char *tab)
{
	int i;

	i = 0;
	while (tab[i] != '\0' && tab[i] != '\n')
		i++;
	return (i);
}

void	ft_add_lst(int const fd, t_gnl *lst, char *buf)
{
	int i;

	i = 0;
	lst->fd = fd;
	lst->s = (char *)malloc(ft_strlen(buf + 1));
	lst->next = NULL;
	while (buf[i] != '\0')
	{
		lst->s[i] = buf[i];
		i++;
	}
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char *str;
	int	i;
	int	j;
	
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && s2[j] != '\n')
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
void	ft_del_gnl()
{
}
*/
int	get_next_line(int const fd, char **line)
{
	char *buff;
	static t_gnl *lst;
	char	*str;
	int i;
	static int j;
	
	if (j != 1)
		lst = (t_gnl *)malloc(sizeof(t_gnl));
	j = 1;
	buff = (char *)malloc(BUFF_SIZE + 1);
	str = (char *)malloc(BUFF_SIZE + 1);
	ft_bzero(buff, BUFF_SIZE + 1);
	ft_bzero(str, BUFF_SIZE + 1);
	if (fd == lst->fd)
	{
		str = ft_strcat(str, lst->s);
		ft_del_gnl(lst->s);
	}
	else
	{
	while(read(fd, buff, BUFF_SIZE) != 0)
	{
		i = 0;
		str = ft_strjoin_gnl(str, buff);
		while (buff[i] != '\0')
		{
			if (buff[i] == EOF || buff[i] == '\n')
				break ;
			i++;
		}
		if (buff[i] == EOF || buff[i] == '\n')
				break ;
		ft_bzero(buff, BUFF_SIZE);
	}
	}
	*line = (char *)malloc(ft_strlen(str) + 1);
	ft_bzero(*line, ft_strlen(str) + 1);
	ft_strcat(*line, str);
	if (buff[i] == '\n')
		i++;
	if (buff[i] != EOF && buff[i] != '\0')
		ft_add_lst(fd, lst, &buff[i]);
	free(buff);
	free(str);
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
}
