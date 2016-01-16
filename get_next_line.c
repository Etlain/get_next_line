/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:04:32 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/01/16 15:49:35 by mmouhssi         ###   ########.fr       */
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
		printf("%x\n", (unsigned int)&list);
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

char		*ft_content(int fd, char *str, char *str2, int *i)
{
	char buff[BUFF_SIZE + 1];
	int r;

	*i = 0;
	while (str[*i] != '\n' && str[*i] != '\0')
		(*i)++;
	ft_bzero(buff, BUFF_SIZE + 1);
	if (str[*i] != '\n')
	{
		while ((r = read(fd, buff, BUFF_SIZE)) > 0)
		{
			str2 = str;
			str = ft_strjoin(str2, buff);
			free(str2);
			*i = 0;
			while (str[*i] != '\n' && str[*i] != '\0')
				(*i)++;
			if (str[*i] == '\n')
				break ;
			ft_bzero(buff, BUFF_SIZE);
		}
		if (r < 0)
			*i = -1;
	}
	return (str);
}

int	rest_in_lst(t_list *list, char **str, int i)
{
	char *str2;

	str2 = *str;
	if (*str[0] == '\n')
	{
		*str = ft_strsub(str2, i + 1, ft_strlen(*str) - i);
		free(str2);
		list->content = (void *)*str;
		return (1);
	}
	else if (*str[0] != '\0')
	{
		*str = ft_strsub(str2, i + 1, ft_strlen(*str) - i);
		free(str2);
	}
	list->content = (void *)*str;
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	char			*str;
	int			i;
	char			*str2;
	static t_list		*lst;
	t_list			*list;

	str2 = NULL;
	if (!line)
		return (-1);
	ft_list(&lst, &list, fd);
	str = ft_content(fd, (char *)list->content, str2, &i);
	if (i == -1)
		return (-1);
	*line = (char *)malloc(i + 1);
	ft_bzero(*line, i + 1);
	ft_strncat(*line, str, i);
	if (rest_in_lst(list, &str, i) == 1)
		return (1);
	if (i > 0)
		return (1);
	return (0);
}

int			main()
{
	int f;
	//int f2;
	char **tab;
	//char **tab2;
	int i;
	
	i = 0;
	tab =(char **)malloc(sizeof(char *) * 5);
	f = open("get_next_line_V2.c", O_RDONLY);
	while (i < 5)
	{
		get_next_line(f, &tab[i]);
		i++;
	}
	i = 0;
	tab[5] = NULL;
	/*tab2 =(char **)malloc(sizeof(char *) * 30);
	f2 = open("get_next_line.c", O_RDONLY);
	while (i < 30)
	{
		tab2[i] = (char *)malloc(100);
		ft_bzero(tab2[i], 100);
		get_next_line(f2, &tab2[i]);
		i++;
	}
	tab2[30] = NULL;*/
	ft_putendl_tab(tab);
	//ft_putendl("fichier 2");
	//ft_putendl_tab(tab2);
	i = 0;
	while (i < 5)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	while (1)
	{
	}
}
