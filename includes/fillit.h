/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtavares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:52:49 by gtavares          #+#    #+#             */
/*   Updated: 2017/10/31 15:52:51 by gtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <fcntl.h>

typedef	struct		s_fill
{
	char			**tetri;
	char			alpha;
	struct s_fill	*next;
	struct s_fill	*prev;
	int				height;
	int				length;
}					t_fill;

typedef struct		s_map
{
	char			**megamap;
	int				size;
}					t_map;

void				ftfinale(t_map *map);
t_map				*resolution(t_fill *begin_fill);
void				putdots(t_fill *lst, t_map *map, int x, int y);
void				puttetri(t_fill *lst, t_map *map, int x, int y);
int					isitpossible(t_fill *lst, t_map *map, int x, int y);
int					recursivite(t_map *map, t_fill *begin_fill);
int					size_map(t_fill *lst);
char				**coupertetri(t_fill *lst);
char				**couperligne(char **tetri);
char				**coupercol(char **tetri, t_fill *lst);
int					get_bottom(t_fill *l_tetri);
int					get_right(t_fill *l_tetri);
void				hauteurlongueur(t_fill *tetri);
t_map				*finalmap(int size);
int					get_top(t_fill *l_tetri);
int					get_left(t_fill *l_tetri);
void				ft_found_error(char *str);
int					count_tetri(t_fill *begin_fill);
char				**map(char *str);
int					ft_verif(char *form);
int					is_tetri(char *str, int i, int x);
int					check_chars(char *str);
t_fill				*prem_map(char *str, int len);
t_fill				*add_map(char *str, t_fill *ifill, char c);
void				primary_function(char *buf, int ret);
void				ft_read(char *file);

#endif
