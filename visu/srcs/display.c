/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 15:58:49 by nbrucker          #+#    #+#             */
/*   Updated: 2018/01/01 15:58:50 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "mlx.h"

void	ft_visu(t_fill *filler, t_env *env)
{
	int x;
	int y;

	while (filler->map->previous)
		filler->map = filler->map->previous;
	env->pas_x = (double)env->width / (double)filler->map_x;
	env->pas_y = (double)env->height / (double)filler->map_y;
	y = 0;
	while (filler->map)
	{
		x = 0;
		while (filler->map->str[x])
		{
			ft_putbox(env, (double)x * env->pas_x,
				(double)y * env->pas_y, filler->map->str[x]);
			x++;
		}
		if (filler->map->next == NULL)
			break ;
		y++;
		filler->map = filler->map->next;
	}
	ft_free(filler->map);
	ft_setbotleft(env);
	mlx_put_image_to_window(env->mlx, env->win, env->image, 0, 0);
}

void	ft_init(t_fill *filler)
{
	filler->map = NULL;
	filler->look_map = 0;
	filler->got_map = 0;
}

void	ft_fill_pixel(t_env *env, float x, float y, int color)
{
	int i;

	if (x < 0 || x >= env->width)
		return ;
	if (y < 0 || y >= env->height)
		return ;
	i = (((int)y * env->width) + (int)x) * 4;
	if (i < 0 || i >= env->width * env->height * 4)
		return ;
	env->str[i] = color & 0xFF;
	env->str[i + 1] = (color >> 8) & 0xFF;
	env->str[i + 2] = (color >> 16) & 0xFF;
}

void	ft_putbox(t_env *env, double i, double j, char c)
{
	double x;
	double y;

	y = 0;
	while (y < env->pas_y * 2)
	{
		x = 0;
		while (x < env->pas_x * 2)
		{
			if (y == 0 || x == 0)
				ft_fill_pixel(env, x + i, y + j, 0xFFFFFF);
			else if (c == 'O')
				ft_fill_pixel(env, x + i, y + j, 0x0000FF);
			else if (c == 'X')
				ft_fill_pixel(env, x + i, y + j, 0x00FF00);
			else if (c == 'o')
				ft_fill_pixel(env, x + i, y + j, 0xFF00FF);
			else if (c == 'x')
				ft_fill_pixel(env, x + i, y + j, 0xFFFF00);
			else
				ft_fill_pixel(env, x + i, y + j, 0);
			x++;
		}
		y++;
	}
}

void	ft_setbotleft(t_env *env)
{
	int x;
	int y;

	x = env->width - 1;
	y = 0;
	while (y < env->height)
	{
		ft_fill_pixel(env, x, y, 0xFFFFFF);
		y++;
	}
	x = 0;
	y = env->height - 1;
	while (x < env->width)
	{
		ft_fill_pixel(env, x, y, 0xFFFFFF);
		x++;
	}
}
