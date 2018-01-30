/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 18:24:21 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/31 18:24:21 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

void	ft_addplayer(char *str, t_fill *filler)
{
	if (ft_strstr_index(str, "nbrucker") == -1)
		return ;
	if (filler->got_player == 1 ||
		filler->got_map == 1 || filler->got_piece == 1)
		ft_error("Map error");
	filler->player = str[10] - 48;
	if (filler->player == 1)
		filler->c = 'o';
	else
		filler->c = 'x';
	filler->got_player = 1;
}

void	ft_addpiece(char *str, t_fill *filler)
{
	t_map	*new;

	if ((new = (t_map*)malloc(sizeof(t_map))) == NULL)
		ft_error("Malloc error");
	new->previous = filler->piece;
	if (filler->piece)
		filler->piece->next = new;
	new->next = NULL;
	filler->piece = new;
	filler->look_piece--;
	new->str = ft_strdup(str);
	if ((int)ft_strlen(new->str) != filler->piece_x)
		ft_error("Map error");
}

void	ft_addmap(char *str, t_fill *filler)
{
	t_map	*new;

	if ((new = (t_map*)malloc(sizeof(t_map))) == NULL)
		ft_error("Malloc error");
	new->previous = filler->map;
	if (filler->map)
		filler->map->next = new;
	new->next = NULL;
	filler->map = new;
	filler->look_map--;
	if (ft_char_index(str, ' ') < 0)
		ft_error("Map error");
	new->str = ft_strdup(str + ft_char_index(str, ' ') + 1);
	if ((int)ft_strlen(new->str) != filler->map_x)
		ft_error("Map error");
}

void	ft_addpos(int x, int y, t_pos **pos)
{
	t_pos	*new;

	if ((new = (t_pos*)malloc(sizeof(t_pos))) == NULL)
		ft_error("Malloc error");
	new->x = x;
	new->y = y;
	new->previous = *pos;
	new->next = NULL;
	if (*pos)
		(*pos)->next = new;
	*pos = new;
}
