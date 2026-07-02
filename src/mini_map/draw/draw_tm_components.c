/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tm_components.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 04:46:03 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/18 04:46:03 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	draw_tiny_square(t_game *game, int color)
{
	int	x;
	int	y;

	if (!game)
		return (ERROR);
	init_tiny_map_coord(&game->tiny_map);
	y = game->tiny_map.start_pixel_y;
	while (y < game->tiny_map.end_pixel_y)
	{
		x = game->tiny_map.start_pixel_x;
		while (x < game->tiny_map.end_pixel_x)
		{
			if (x >= game->tiny_map.min_x && x < game->tiny_map.max_x
				&& y >= game->tiny_map.min_y && y < game->tiny_map.max_y)
			{
				if (draw_pixel(game, x, y, color) == ERROR)
					return (ERROR);
			}
			x++;
		}
		y++;
	}
	return (OK);
}

int	draw_tiny_player(t_game *game)
{
	int	x;
	int	y;

	init_tiny_player(game);
	y = game->mini_player.start_y;
	while (y < game->mini_player.end_y)
	{
		x = game->mini_player.start_x;
		while (x < game->mini_player.end_x)
		{
			if (draw_pixel(game, x, y, COLOR_PLAYER) == ERROR)
				return (ERROR);
			x++;
		}
		y++;
	}
	return (OK);
}

static int	draw_tiny_ray(t_game *game, double dir_x, double dir_y)
{
	int		ray_pixel_x;
	int		ray_pixel_y;
	double	y;
	double	x;

	y = game->player.pos_y;
	x = game->player.pos_x;
	while (is_ray_stay_in_bound(game, x, y) == true)
	{
		ray_pixel_x = convert_x_to_pixel(game, x);
		ray_pixel_y = convert_y_to_pixel(game, y);
		if (is_ray_pixel_in_bound(game, ray_pixel_x, ray_pixel_y) == false)
			break ;
		if (draw_pixel(game, ray_pixel_x, ray_pixel_y, COLOR_RAY) == ERROR)
			return (ERROR);
		x = x + dir_x * SPEED;
		y = y + dir_y * SPEED;
	}
	return (OK);
}

int	draw_all_tiny_ray(t_game *game)
{
	double	ray_dir_x;
	double	ray_dir_y;
	double	camera_x;
	int		i;

	i = 0;
	while (i < WIDTH)
	{
		camera_x = 2.0 * i / (double)WIDTH - 1;
		ray_dir_x = game->player.dir_x + game->ray.plane_x * camera_x;
		ray_dir_y = game->player.dir_y + game->ray.plane_y * camera_x;
		if (draw_tiny_ray(game, ray_dir_x, ray_dir_y) == ERROR)
			return (ERROR);
		i++;
	}
	return (OK);
}

int	draw_background(t_game *game)
{
	int	y;
	int	x;

	y = game->tiny_map.min_y;
	while (y < game->tiny_map.max_y)
	{
		x = game->tiny_map.min_x;
		while (x < game->tiny_map.max_x)
		{
			if (draw_pixel(game, x, y, COLOR_BACKGROUND) == ERROR)
				return (ERROR);
			x++;
		}
		y++;
	}
	return (OK);
}
