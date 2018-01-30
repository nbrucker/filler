/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 18:43:46 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/31 18:43:47 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

int		ft_ready(t_fill *filler)
{
	if (filler->got_piece == 1 && filler->got_map == 1
		&& filler->got_player == 1 && filler->look_map == 0
		&& filler->look_piece == 0)
		return (1);
	return (0);
}

int		main(void)
{
	char	*str;
	t_fill	filler;

	filler.got_player = 0;
	ft_init(&filler);
	str = NULL;
	while (get_next_line(0, &str) > 0)
	{
		if (!ft_strncmp("$$$ exec p", str, 10))
			ft_addplayer(str, &filler);
		else if (!ft_strncmp("Plateau ", str, 8))
			ft_setmap(str, &filler);
		else if (!ft_strncmp("Piece ", str, 6))
			ft_setpiece(str, &filler);
		else if (filler.look_map > 0)
			ft_addmap(str, &filler);
		else if (filler.look_piece > 0)
			ft_addpiece(str, &filler);
		if (ft_ready(&filler))
			ft_filler(&filler);
		ft_strdel(&str);
	}
	ft_strdel(&str);
	return (0);
}
