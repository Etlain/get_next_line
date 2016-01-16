/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:04:32 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/01/16 16:50:36 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"

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
	tab2 =(char **)malloc(sizeof(char *) * 30);
	f2 = open("get_next_line.c", O_RDONLY);
	while (i < 30)
	{
		tab2[i] = (char *)malloc(100);
		ft_bzero(tab2[i], 100);
		get_next_line(f2, &tab2[i]);
		i++;
	}
	tab2[30] = NULL;
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
