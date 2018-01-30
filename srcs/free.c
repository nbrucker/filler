/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 18:16:51 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/31 18:16:51 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_freetab(char ***str)
{
	int i;

	i = 0;
	while (str[0][i])
	{
		free(str[0][i]);
		i++;
	}
	free(str[0][i]);
	free(str[0]);
}

void	ft_free(t_map *map, int i)
{
	t_map *next;

	while (map && map->previous)
		map = map->previous;
	while (map)
	{
		next = map->next;
		if (i == 1)
			free(map->tab);
		free(map->str);
		free(map);
		map = next;
	}
}

void	ft_freepos(t_pos *pos)
{
	t_pos *next;

	while (pos && pos->previous)
		pos = pos->previous;
	while (pos)
	{
		next = pos->next;
		free(pos);
		pos = next;
	}
}
