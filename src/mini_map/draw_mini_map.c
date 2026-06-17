/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:22:38 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/17 15:40:45 by mvignes          ###   ########.fr       */
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

static int	draw_ray(t_game *game, double *ray_dir_x, double *ray_dir_y)
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
		game->ray.ray_pos_x = game->ray.ray_pos_x + *ray_dir_x * SPEED;
		game->ray.ray_pos_y = game->ray.ray_pos_y + *ray_dir_y * SPEED;
	}
	return (OK);
}


int		exec_dda(t_game *game, double *side_x, double *side_y)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (*side_x < *side_y)
		{
			*side_x += game->ray.delta_dist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			*side_y += game->ray.delta_dist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->map.grid[game->ray.map_y / SIZE][game->ray.map_x / SIZE] == '1')
			hit = 1;
	}
	return (game->ray.side);
}

void	init_dda(t_game *game, double *side_x, double *side_y)
{
	game->ray.map_x = game->player.pos_x;
	game->ray.map_y = game->player.pos_y;
	game->ray.delta_dist_x = fabs(1 / game->ray.ray_dir_x);
	game->ray.delta_dist_y = fabs(1 / game->ray.ray_dir_y);
	if (game->ray.ray_dir_x < 0)
	{
		game->ray.step_x = -1;
		*side_x = (game->player.pos_x - game->ray.map_x) * game->ray.delta_dist_x;
	}
	else
	{
		game->ray.step_x = 1;
		*side_x = (game->player.pos_x + 1.0 - game->ray.map_x) * game->ray.delta_dist_x;
	}
	if (game->ray.ray_dir_y < 0)
	{
		game->ray.step_y = -1;
		*side_y = (game->player.pos_y - game->ray.map_y) * game->ray.delta_dist_y;
	}
	else
	{
		game->ray.step_y = 1;
		*side_y = (game->player.pos_y + 1.0 - game->ray.map_y) * game->ray.delta_dist_y;
	}
}

void	calcul_dist_wall(t_game *game, double *dist)
{
	if (game->ray.side == 0)
		*dist = (game->ray.map_x - game->player.pos_x + (1 - game->ray.step_x) / 2) / game->ray.ray_dir_x / SIZE;
	else
		*dist = (game->ray.map_y - game->player.pos_y + (1 - game->ray.step_y) / 2) / game->ray.ray_dir_y / SIZE;
	game->ray.line_height = (int)(HEIGHT / *dist);
	if (game->ray.side)
		game->ray.wall_x = game->player.pos_y / SIZE + *dist * game->ray.ray_dir_y;
	else
		game->ray.wall_x = game->player.pos_x / SIZE + *dist * game->ray.ray_dir_x;
	game->ray.wall_x -= floor(game->ray.wall_x);
}

static int	draw_all_ray(t_game *game)
{
	// double	ray_dir_x;
	// double	ray_dir_y;
	double	side_x;
	double	side_y;
	double	camera_x;
	double	dist;
	int		x;

	x = 0;
	// init_ray(game);
	while (x < WIDTH)
	{
		camera_x = 2.0 * x / (double)WIDTH - 1;
		game->ray.ray_dir_x = game->player.dir_x + game->ray.plane_x * camera_x;
		game->ray.ray_dir_y = game->player.dir_y + game->ray.plane_y * camera_x;
		// init algo dda
		init_dda(game, &side_x, &side_y);
		exec_dda(game, &side_x, &side_y);
		calcul_dist_wall(game, &dist);
		if (draw_ray(game, &game->ray.ray_dir_x, &game->ray.ray_dir_y) == ERROR)
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
