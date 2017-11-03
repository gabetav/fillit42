/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtavares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:52:11 by gtavares          #+#    #+#             */
/*   Updated: 2017/10/31 15:52:12 by gtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"
#include <stdio.h>

char	**ft_map(char *str)
{
	int		i;
	int		lartmp;
	char	**tab;

	if (!(tab = malloc(sizeof(char *) * (4))))
		return (NULL);
	lartmp = 0;
	i = 0;
	while (lartmp < 4)
	{
		if (!(tab[lartmp] = malloc(sizeof(char) * 5)))
			return (NULL);
		ft_strncpy(tab[lartmp], str + i, 4);
		tab[lartmp][4] = '\0';
		i += 5;
		lartmp++;
	}
	return (tab);
}

t_fill	*add_map(char *str, t_fill *ifill, char c)
{
	if (!(ifill = (t_fill*)malloc(sizeof(*ifill))))
		return (NULL);
	ifill->tetri = ft_map(str);
	ifill->alpha = c;
	ifill->next = NULL;
	return (ifill);
}

t_fill	*prem_map(char *str, int len)
{
	t_fill	*nfill;
	t_fill	*ifill;
	int		i;
	char	c;

	i = 21;
	c = 'A';
	if (!(nfill = (t_fill*)malloc(sizeof(*nfill))))
		return (NULL);
	nfill->tetri = ft_map(str);
	nfill->alpha = c;
	nfill->next = NULL;
	nfill->prev = nfill;
	ifill = nfill;
	while (i < len)
	{
		c++;
		ifill->next = add_map(str + i, ifill, c);
		ifill->prev = ifill;
		ifill = ifill->next;
		i += 21;
	}
	ifill->next = NULL;
	nfill->prev = ifill;
	return (nfill);
}
