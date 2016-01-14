/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:04:32 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/01/14 14:59:47 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"

void	ft_list(t_list **lst, t_list **list, int fd)
{
	if (!*lst)
	{
		*list = ft_lstnew(NULL, 0);
		(*list)->content_size = (size_t) fd;
		*lst = *list;
	}
	else
	{
		*list = *lst;
		while (*list != NULL && (*list)->content_size != (size_t)fd)
			*list = (*list)->next;
		if (*list == NULL)
		{
			*list = ft_lstnew(NULL, 0);
			ft_lstadd(&(*lst), *list);
			(*list)->content_size = (size_t) fd;
		}
	}
	if ((*list)->content == NULL)
	{
		(*list)->content = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
		ft_bzero((*list)->content, BUFF_SIZE + 1);
	}
}

char		*ft_content(int fd, char *str, int *r, int *i)
{
	char buff[BUFF_SIZE + 1];

	*i = 0;
	*r = 0;
	while (str[*i] != '\n' && str[*i] != '\0')
		(*i)++;
	ft_bzero(buff, BUFF_SIZE + 1);
	if (str[*i] != '\n')
	{
		*r = read(fd, buff, BUFF_SIZE);
		while (*r > 0)
		{
			str = ft_strjoin(str, buff);
			*i = 0;
			while (str[*i] != '\n' && str[*i] != '\0')
				(*i)++;
			if (str[*i] == '\n')
				break ;
			ft_bzero(buff, BUFF_SIZE);
			*r = read(fd, buff, BUFF_SIZE);
		}
		if (*r < 0)
			*r = -1;
	}
	return (str);
}

int			get_next_line(int const fd, char **line)
{
	char			*str;
	int			i;
	int			r;
	static t_list		*lst;
	t_list			*list;

	if (!line)
		return (-1);
	ft_list(&lst, &list, fd);
	str = (char *)list->content;
	str = ft_content(fd, str, &r, &i);
	*line = (char *)malloc(i + 1);
	ft_bzero(*line, i + 1);
	ft_strncat(*line, str, i);
	if (str[0] != '\0')
		str = ft_strsub(str, i + 1, ft_strlen(str) - i);
	list->content = (void *)str;
	if (r == -1)
		return (-1);
	if (i > 0 || str[i] == '\n')
		return (1);
	return (0);
}

/*int			main()
{
	int f;
	int f2;
	char **tab;
	char **tab2;
	int i;
	
	i = 0;
	tab =(char **)malloc(sizeof(char *) * 30);
	f = open("get_next_line/get_next_line_V2.c", O_RDONLY);
	while (i < 30)
	{
		tab[i] = (char *)malloc(100);
		ft_bzero(tab[i], 100);
		get_next_line(f, &tab[i]);
		i++;
	}
	i = 0;
	tab[30] = NULL;
	tab2 =(char **)malloc(sizeof(char *) * 30);
	f2 = open("get_next_line/get_next_line.c", O_RDONLY);
	while (i < 30)
	{
		tab2[i] = (char *)malloc(100);
		ft_bzero(tab2[i], 100);
		get_next_line(f2, &tab2[i]);
		i++;
	}
	tab2[30] = NULL;
	ft_putendl_tab(tab);
	ft_putendl("fichier 2");
	ft_putendl_tab(tab2);
}*/
