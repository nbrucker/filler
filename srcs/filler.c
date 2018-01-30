/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 22:08:59 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/30 22:09:00 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

int		ft_inplace(t_map *map, int x, t_map *piece, char c)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (piece->str[i])
	{
		if (!map->str[x + i])
			return (-42);
		if (map->str[x + i] != '.' && map->str[x + i] != c &&
			map->str[x + i] != ft_toupper(c) && piece->str[i] != '.')
			return (-42);
		if ((map->str[x + i] == c || map->str[x + i] == ft_toupper(c))
			&& piece->str[i] == '*')
			n++;
		i++;
	}
	return (n);
}

int		ft_place(t_map *map, int x, t_map *piece, char c)
{
	int p;
	int n;

	n = 0;
	while (piece && n <= 1)
	{
		p = ft_inplace(map, x, piece, c);
		if (p == -42)
			return (0);
		n += p;
		if (piece->next == NULL)
			break ;
		if (map->next == NULL)
			return (0);
		piece = piece->next;
		map = map->next;
	}
	if (n != 1)
		return (0);
	return (1);
}

void	ft_solve(t_map *map, t_map *piece, char c)
{
	int		x;
	int		y;
	t_pos	*pos;

	pos = NULL;
	y = 0;
	while (map)
	{
		x = 0;
		while (map->str[x])
		{
			if (ft_place(map, x, piece, c) == 1)
				ft_addpos(x, y, &pos);
			x++;
		}
		if (map->next == NULL)
			break ;
		y++;
		map = map->next;
	}
	ft_print_result(pos, map, c, piece);
	ft_freepos(pos);
}

void	ft_filler(t_fill *filler)
{
	if (filler->map == NULL || filler->piece == NULL)
		ft_error("Map error");
	while (filler->map->previous)
		filler->map = filler->map->previous;
	while (filler->piece->previous)
		filler->piece = filler->piece->previous;
	ft_solve(filler->map, filler->piece, filler->c);
	ft_free(filler->map, 1);
	ft_free(filler->piece, 0);
	ft_init(filler);
}
