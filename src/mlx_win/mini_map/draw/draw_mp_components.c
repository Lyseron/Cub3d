/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mp_components.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 03:29:33 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/11 09:03:49 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	draw_mini_square(t_game *game, int map_x, int map_y, int color)
{
	int	y;
	int	x;

	if (!game)
		return (ERROR);
	init_mini_map_coord(&game->mini_map, map_x, map_y);
	y = game->mini_map.start_y;
	while (y < game->mini_map.end_y)
	{
		x = game->mini_map.start_x;
		while (x < game->mini_map.end_x)
		{
			put_pixel(game, x, y, color);
			x++;
		}
		y++;
	}
	return (OK);
}

int	draw_player(t_game *game)
{
	int	x;
	int	y;

	init_mini_player(game);
	y = game->mini_player.start_y;
	while (y < game->mini_player.end_y)
	{
		x = game->mini_player.start_x;
		while (x < game->mini_player.end_x)
		{
			put_pixel(game, x, y, COLOR_PLAYER);
			x++;
		}
		y++;
	}
	return (OK);
}

static int	draw_ray(t_game *game, double ray_dir_x, double ray_dir_y)
{
	int		x;
	int		y;
	double	ray_pos_y;
	double	ray_pos_x;

	init_ray(game);
	ray_pos_y = game->ray.ray_pos_y;
	ray_pos_x = game->ray.ray_pos_x;
	while (ray_pos_y >= 0 && ray_pos_y < game->map.map_y
		&& ray_pos_x >= 0 && ray_pos_x < game->map.map_x
		&& (game->map.grid[(int)ray_pos_y][(int)ray_pos_x] != '1'
		&& game->map.grid[(int)ray_pos_y][(int)ray_pos_x] != '2'
		&& game->map.grid[(int)ray_pos_y][(int)ray_pos_x] != ' '))
	{
		x = MARGE + ray_pos_x * SIZE_SQUARE;
		y = MARGE + ray_pos_y * SIZE_SQUARE;
		put_pixel(game, x, y, COLOR_RAY);
		ray_pos_x = ray_pos_x + ray_dir_x * RAY_STEP_SIZE;
		ray_pos_y = ray_pos_y + ray_dir_y * RAY_STEP_SIZE;
	}
	return (OK);
}

int	draw_all_ray(t_game *game)
{
	double	ray_dir_x;
	double	ray_dir_y;
	double	camera_x;
	int		i;

	i = 0;
	while (i < game->width)
	{
		camera_x = 2.0 * i / (double)game->width - 1;
		ray_dir_x = game->player.dir_x + game->ray.plane_x * camera_x;
		ray_dir_y = game->player.dir_y + game->ray.plane_y * camera_x;
		if (draw_ray(game, ray_dir_x, ray_dir_y) == ERROR)
			return (ERROR);
		i++;
	}
	return (OK);
}
