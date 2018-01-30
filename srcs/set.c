/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 18:22:59 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/31 18:22:59 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

void	ft_setpiece(char *str, t_fill *filler)
{
	char	**tab;

	if (filler->got_piece == 1 || filler->look_map != 0
		|| filler->got_map == 0 || filler->got_player == 0)
		ft_error("Map error");
	tab = ft_strsplit(str, ' ');
	filler->piece_y = ft_atoi(tab[1]);
	filler->piece_x = ft_atoi(tab[2]);
	filler->look_piece = ft_atoi(tab[1]);
	ft_freetab(&tab);
	filler->got_piece = 1;
}

void	ft_setmap(char *str, t_fill *filler)
{
	char	**tab;
	char	*tmp;

	if (filler->got_map == 1 || filler->got_player == 0)
		ft_error("Map error");
	tab = ft_strsplit(str, ' ');
	filler->map_y = ft_atoi(tab[1]);
	filler->map_x = ft_atoi(tab[2]);
	filler->look_map = ft_atoi(tab[1]);
	ft_freetab(&tab);
	filler->got_map = 1;
	get_next_line(0, &tmp);
	free(tmp);
}

void	ft_settab(t_map *map, char c)
{
	int i;
	int y;

	map = ft_rewind(map);
	y = 0;
	while (map)
	{
		i = 0;
		if ((map->tab = (int*)malloc(sizeof(int) *
			ft_strlen(map->str))) == NULL)
			ft_error("Malloc error");
		while (map->str[i])
		{
			map->tab[i] = ft_setpoids(map, i, y, c);
			i++;
		}
		if (map->next == NULL)
			break ;
		y++;
		map = map->next;
	}
}

void	ft_setn(t_pos *pos, t_map *map, t_map *piece)
{
	int x;
	int y;

	map = ft_rewind(map);
	y = 0;
	while (pos->y != y)
	{
		y++;
		map = map->next;
	}
	while (piece)
	{
		x = 0;
		while (piece->str[x])
		{
			if (piece->str[x] == '*')
				pos->n += map->tab[x + pos->x];
			x++;
		}
		piece = piece->next;
		map = map->next;
	}
}
