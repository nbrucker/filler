/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 14:38:19 by nbrucker          #+#    #+#             */
/*   Updated: 2018/01/01 14:38:20 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "libft.h"
#include "mlx.h"

void	ft_setmap(char *str, t_fill *filler)
{
	char	**tab;
	char	*tmp;

	tab = ft_strsplit(str, ' ');
	filler->map_y = ft_atoi(tab[1]);
	filler->map_x = ft_atoi(tab[2]);
	filler->look_map = ft_atoi(tab[1]);
	ft_freetab(&tab);
	filler->got_map = 1;
	get_next_line(0, &tmp);
	free(tmp);
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
	new->str = ft_strdup(str + ft_char_index(str, ' ') + 1);
}

void	ft_initenv(t_env *env)
{
	int		bpp;
	int		s_l;
	int		endian;

	env->width = 500;
	env->height = 900;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->width, env->height, "fractol");
	env->image = mlx_new_image(env->mlx, env->width, env->height);
	env->str = mlx_get_data_addr(env->image, &bpp, &s_l, &endian);
}

int		ft_input(int key, t_env *env)
{
	char	*str;
	t_fill	filler;

	if (key == 53)
		exit(0);
	ft_init(&filler);
	str = NULL;
	while (get_next_line(0, &str) > 0)
	{
		if (!ft_strncmp("Plateau ", str, 8))
			ft_setmap(str, &filler);
		else if (filler.look_map > 0)
			ft_addmap(str, &filler);
		if (filler.got_map == 1 && filler.look_map == 0)
		{
			ft_visu(&filler, env);
			break ;
		}
		ft_strdel(&str);
	}
	ft_strdel(&str);
	return (1);
}

int		main(void)
{
	t_env	env;

	ft_initenv(&env);
	mlx_hook(env.win, 2, 3, ft_input, &env);
	mlx_loop(env.mlx);
	return (0);
}
