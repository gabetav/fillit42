/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decouper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtavares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:52:00 by gtavares          #+#    #+#             */
/*   Updated: 2017/10/31 15:52:02 by gtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"
#include <stdio.h>

char		**coupertetri(t_fill *lst)
{
	char **tab;

	if (!(tab = (char**)malloc(sizeof(char*) * 4)))
		return (NULL);
	while (lst)
	{
		couperligne(lst->tetri);
		coupercol(lst->tetri, lst);
		lst = lst->next;
	}
	return (tab);
}

char		**couperligne(char **tetri)
{
	int y;
	int ybis;

	y = 3;
	while (!ft_strchr(tetri[0], '#'))
	{
		ybis = 0;
		while (ybis < 3)
		{
			tetri[ybis] = tetri[ybis + 1];
			ybis++;
		}
		tetri[3] = "....";
	}
	while (y >= 0)
	{
		if (!ft_strchr(tetri[y], '#'))
			tetri[y] = "....";
		y--;
	}
	return (tetri);
}

char		**coupercol(char **tetri, t_fill *lst)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (tetri[0][0] == '.' && tetri[1][0] == '.' && tetri[2][0] == '.'
			&& tetri[3][0] == '.' && x < 4)
	{
		y = 0;
		if (tetri[1][x] == '.' && tetri[2][x] == '.' && tetri[3][x] == '.'
				&& tetri[0][x] == '.' && x <= 3)
		{
			while (y < lst->height)
			{
				tetri[y][0] = tetri[y][1];
				tetri[y][1] = tetri[y][2];
				tetri[y][2] = tetri[y][3];
				tetri[y][3] = '.';
				y++;
			}
		}
		x++;
	}
	return (tetri);
}
