/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 22:08:50 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/30 22:08:50 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>

typedef	struct	s_pos
{
	int				x;
	int				y;
	int				n;
	struct s_pos	*next;
	struct s_pos	*previous;
}				t_pos;

typedef	struct	s_map
{
	char			*str;
	int				*tab;
	struct s_map	*next;
	struct s_map	*previous;
}				t_map;

typedef	struct	s_fill
{
	char			c;
	int				player;
	int				map_x;
	int				map_y;
	int				piece_x;
	int				piece_y;
	struct s_map	*map;
	struct s_map	*piece;
	int				look_map;
	int				look_piece;
	int				got_player;
	int				got_map;
	int				got_piece;
}				t_fill;

void			ft_freetab(char ***str);
void			ft_free(t_map *map, int i);
void			ft_freepos(t_pos *pos);
t_map			*ft_rewind(t_map *map);
int				ft_abs(int x);
int				ft_setpoids(t_map *map, int x, int y, char c);
void			ft_setpiece(char *str, t_fill *filler);
void			ft_setmap(char *str, t_fill *filler);
void			ft_settab(t_map *map, char c);
void			ft_setn(t_pos *pos, t_map *map, t_map *piece);
void			ft_addpiece(char *str, t_fill *filler);
void			ft_addmap(char *str, t_fill *filler);
void			ft_addpos(int x, int y, t_pos **pos);
void			ft_init(t_fill *filler);
int				ft_islowest(t_pos *pos);
void			ft_addplayer(char *str, t_fill *filler);
void			ft_set_result(t_pos *pos, t_map *map, char c, t_map *piece);
void			ft_print_result(t_pos *pos, t_map *map, char c, t_map *piece);
void			ft_filler(t_fill *filler);

#endif
