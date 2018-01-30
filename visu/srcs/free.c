/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 15:56:26 by nbrucker          #+#    #+#             */
/*   Updated: 2018/01/01 15:56:26 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	ft_free(t_map *map)
{
	t_map *next;

	while (map && map->previous)
		map = map->previous;
	while (map)
	{
		next = map->next;
		free(map->str);
		free(map);
		map = next;
	}
}

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
