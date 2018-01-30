/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 22:08:50 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/30 22:08:50 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include <stdlib.h>

typedef	struct	s_map
{
	char			*str;
	struct s_map	*next;
	struct s_map	*previous;
}				t_map;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*image;
	char	*str;
	int		width;
	int		height;
	double	pas_x;
	double	pas_y;
}				t_env;

typedef	struct	s_fill
{
	int				map_x;
	int				map_y;
	struct s_map	*map;
	int				look_map;
	int				got_map;
}				t_fill;

void			ft_free(t_map *map);
void			ft_init(t_fill *filler);
void			ft_freetab(char ***str);
void			ft_putbox(t_env *env, double i, double j, char c);
void			ft_setbotleft(t_env *env);
void			ft_visu(t_fill *filler, t_env *env);

#endif
