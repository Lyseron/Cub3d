/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:22:38 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/11 16:42:26 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	draw_player(t_game *game)
{
	init_mini_player(game);
	while (game->mini_player.player_pixel_y < game->mini_player.end_y)
	{
		game->mini_player.player_pixel_x = game->mini_player.start_x;
		while (game->mini_player.player_pixel_x < game->mini_player.end_x)
		{
			if (draw_pixel(game, game->mini_player.player_pixel_x,
					game->mini_player.player_pixel_y,
					0x0000FF) == ERROR)
				return (ERROR);
			game->mini_player.player_pixel_x++;
		}
		game->mini_player.player_pixel_y++;
	}
	return (OK);
}

static int	draw_ray(t_game *game, double ray_dir_x, double ray_dir_y)
{
	int	ray_pixel_x;
	int	ray_pixel_y;

	init_ray(game);
	while (game->ray.ray_pos_y >= 0 && game->ray.ray_pos_y < game->map.map_y
		&& game->ray.ray_pos_x >= 0 && game->ray.ray_pos_x < game->map.map_x
		&& game->map.grid[(int)game->ray.ray_pos_y][(int)game->ray.ray_pos_x] != '1')
	{
		ray_pixel_x = 15 + game->ray.ray_pos_x * SIZE_SQUARE;
		ray_pixel_y = 15 + game->ray.ray_pos_y * SIZE_SQUARE;
		if (draw_pixel(game, ray_pixel_x, ray_pixel_y, 0x0000FF) == ERROR)
			return (ERROR);
		game->ray.ray_pos_x = game->ray.ray_pos_x + ray_dir_x * SPEED;
		game->ray.ray_pos_y = game->ray.ray_pos_y + ray_dir_y * SPEED;
	}
	return (OK);
}

static int	draw_all_ray(t_game *game)
{
	double	ray_dir_x;
	double	ray_dir_y;
	double	camera_x;
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		camera_x = 2.0 * x / (double)WIDTH - 1;
		ray_dir_x = game->player.dir_x + game->ray.plane_x * camera_x;
		ray_dir_y = game->player.dir_y + game->ray.plane_y * camera_x;
		if (draw_ray(game, ray_dir_x, ray_dir_y) == ERROR)
			return (ERROR);
		x++;
	}
	return (OK);
}

int	draw_mini_map(t_game *game)
{
	int	x;
	int	y;

	if (!game || !game->map.grid)
		return (ERROR);
	y = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			if (tiny_map_conditions(game, x, y) == ERROR)
				return (ERROR);
			x++;
		}
		y++;
	}
	if (draw_player(game) == ERROR)
		return (ERROR);
	if (draw_all_ray(game) == ERROR)
		return (ERROR);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	return (OK);
}
