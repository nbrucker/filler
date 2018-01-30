/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 18:25:42 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/31 18:25:42 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_init(t_fill *filler)
{
	filler->map = NULL;
	filler->piece = NULL;
	filler->look_map = 0;
	filler->look_piece = 0;
	filler->got_map = 0;
	filler->got_piece = 0;
}

int		ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

t_map	*ft_rewind(t_map *map)
{
	while (map && map->previous)
		map = map->previous;
	return (map);
}

int		ft_islowest(t_pos *pos)
{
	t_pos *el;

	el = pos;
	while (pos->previous)
		pos = pos->previous;
	while (pos)
	{
		if (pos->n < el->n)
			return (0);
		pos = pos->next;
	}
	return (1);
}
