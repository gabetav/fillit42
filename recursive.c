/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtavares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:52:20 by gtavares          #+#    #+#             */
/*   Updated: 2017/10/31 15:52:21 by gtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"
#include <stdio.h>

void	ftfinale(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putendl(map->megamap[i]);
		i++;
	}
}

int		recursivite(t_map *map, t_fill *begin_fill)
{
	int		x;
	int		y;
	t_fill	*lst;

	lst = begin_fill;
	if (begin_fill == NULL)
		return (1);
	y = 0;
	while (y <= map->size - begin_fill->height)
	{
		x = 0;
		while (x <= map->size - begin_fill->length)
		{
			if (isitpossible(lst, map, x, y))
			{
				if (recursivite(map, begin_fill->next))
					return (1);
				else
					putdots(lst, map, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		isitpossible(t_fill *lst, t_map *map, int x, int y)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (j < lst->height)
	{
		i = 0;
		while (i < lst->length)
		{
			if (lst->tetri[j][i] == '#' && map->megamap[y + j][x + i] != '.')
				return (0);
			i++;
		}
		j++;
	}
	puttetri(lst, map, x, y);
	return (1);
}

void	puttetri(t_fill *lst, t_map *map, int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j < lst->height)
	{
		i = 0;
		while (i < lst->length)
		{
			if (lst->tetri[j][i] == '#')
				map->megamap[y + j][x + i] = lst->alpha;
			i++;
		}
		j++;
	}
}

void	putdots(t_fill *lst, t_map *map, int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j < lst->height)
	{
		i = 0;
		while (i < lst->length)
		{
			if (lst->tetri[j][i] == '#')
				map->megamap[y + j][x + i] = '.';
			i++;
		}
		j++;
	}
}
