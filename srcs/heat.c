/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 18:16:58 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/31 18:16:59 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

int		ft_setpoids(t_map *map, int x, int y, char c)
{
	int n;
	int i;
	int j;

	n = 2147483647;
	map = ft_rewind(map);
	j = 0;
	while (map)
	{
		i = 0;
		while (map->str[i])
		{
			if (map->str[i] == c || map->str[i] == ft_toupper(c))
			{
				if (ft_abs(i - x) < n && ft_abs(i - x) >= ft_abs(j - y))
					n = ft_abs(i - x);
				if (ft_abs(j - y) < n && ft_abs(i - x) <= ft_abs(j - y))
					n = ft_abs(j - y);
			}
			i++;
		}
		map = map->next;
		j++;
	}
	return (n);
}

void	ft_set_result(t_pos *pos, t_map *map, char c, t_map *piece)
{
	while (pos->previous)
		pos = pos->previous;
	ft_settab(map, c == 'o' ? 'x' : 'o');
	while (pos)
	{
		pos->n = 0;
		ft_setn(pos, map, piece);
		if (pos->next == NULL)
			break ;
		pos = pos->next;
	}
}

void	ft_print_result(t_pos *pos, t_map *map, char c, t_map *piece)
{
	if (pos == NULL)
	{
		ft_putendl("0 0");
		exit(0);
	}
	ft_set_result(pos, map, c, piece);
	while (pos->previous)
		pos = pos->previous;
	while (pos)
	{
		if (ft_islowest(pos))
		{
			ft_putnbr(pos->y);
			ft_putchar(' ');
			ft_putnbr(pos->x);
			ft_putchar('\n');
			return ;
		}
		if (pos->next == NULL)
			break ;
		pos = pos->next;
	}
}
