/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:15:59 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/19 14:23:01 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// int		exec_dda(t_game *game, double *side_x, double *side_y)
// {
// 	int	hit;

// 	hit = 0;
// 	while (!hit)
// 	{
// 		if (*side_x < *side_y)
// 		{
// 			*side_x += game->ray.delta_dist_x;
// 			game->ray.map_x += game->ray.step_x;
// 			game->ray.side = 0;
// 		}
// 		else
// 		{
// 			*side_y += game->ray.delta_dist_y;
// 			game->ray.map_y += game->ray.step_y;
// 			game->ray.side = 1;
// 		}
// 		if (game->map.grid[game->ray.map_y / SIZE][game->ray.map_x / SIZE] == '1')
// 			hit = 1;
// 	}
// 	return (game->ray.side);
// }

// void	init_dda(t_game *game, double *side_x, double *side_y)
// {
// 	game->ray.map_x = (int)game->player.pos_x;
// 	game->ray.map_y = (int)game->player.pos_y;
// 	game->ray.delta_dist_x = fabs(1 / game->ray.ray_dir_x);
// 	game->ray.delta_dist_y = fabs(1 / game->ray.ray_dir_y);
// 	if (game->ray.ray_dir_x < 0)
// 	{
// 		game->ray.step_x = -1;
// 		*side_x = (game->player.pos_x - game->ray.map_x) * game->ray.delta_dist_x;
// 	}
// 	else
// 	{
// 		game->ray.step_x = 1;
// 		*side_x = (game->player.pos_x + 1.0 - game->ray.map_x) * game->ray.delta_dist_x;
// 	}
// 	if (game->ray.ray_dir_y < 0)
// 	{
// 		game->ray.step_y = -1;
// 		*side_y = (game->player.pos_y - game->ray.map_y) * game->ray.delta_dist_y;
// 	}
// 	else
// 	{
// 		game->ray.step_y = 1;
// 		*side_y = (game->player.pos_y + 1.0 - game->ray.map_y) * game->ray.delta_dist_y;
// 	}
// }

// void	init_info_calcul_position(double *player_pos, double *delta_dist, int *map_pos, int *step)
// {}

// void	calcul_position_wall(t_game *game, double *side, double *ray_dir, bool is_x)
// {
// 	double	*player_pos;
// 	double	*delta_dist;
// 	int		*map_pos;
// 	int		*step;
// 	if (is_x)
// 		init_info_calcul_position(&game->player.pos_x, &game->ray.delta_dist_x,
// 			&game->ray.map_x, &game->ray.step_x);
// 	else
// 		init_info_calcul_position(&game->player.pos_y, &game->ray.delta_dist_y,
// 			&game->ray.map_y, &game->ray.step_y);
// 	if (*ray_dir < 0)
// 	{
// 		*step = -1;
// 		*side = (*player_pos - *map_pos) * *delta_dist;
// 	}
// 	else
// 	{
// 		*step = 1;
// 		*side = (*player_pos + 1.0 - *map_pos) * *delta_dist;
// 	}
// }

// void	calcul_horizontal_intersection(t_game *game)
// {
// 	game->ray.map_x = (int)game->player.pos_x;
// 	game->ray.map_y = (int)game->player.pos_y;
// 	game->ray.delta_dist_x = fabs(1 / game->ray.ray_dir_x);
// 	game->ray.delta_dist_y = fabs(1 / game->ray.ray_dir_y);
// 	// calcul_position_wall(game, &side_x, game->->ray.);
// 	// calcul_position_wall();
	
// }

// void	calcul_dist_wall(t_game *game, double *dist)
// {
// 	if (game->ray.side == 0)
// 		*dist = (game->ray.map_x - game->player.pos_x + (1 - game->ray.step_x) / 2) / game->ray.ray_dir_x / SIZE;
// 	else
// 		*dist = (game->ray.map_y - game->player.pos_y + (1 - game->ray.step_y) / 2) / game->ray.ray_dir_y / SIZE;
// 	game->ray.line_height = (int)(HEIGHT / *dist);
// 	if (game->ray.side)
// 		game->ray.wall_x = game->player.pos_y / SIZE + *dist * game->ray.ray_dir_y;
// 	else
// 		game->ray.wall_x = game->player.pos_x / SIZE + *dist * game->ray.ray_dir_x;
// 	game->ray.wall_x -= floor(game->ray.wall_x);
// }

// bool	touch(double px, double py, t_game *game)
// {
// 	int	x = px / SIZE_SQUARE;
// 	int	y = py / SIZE_SQUARE;
// 	if (game->map.grid[y][x] == '1')
// 		return (true);
// 	return (false);
// }

// void	draw_line(t_player *player, t_game *game, double start_x, int i)
// {
// 	(void)player;
// 	(void)i;
// 	(void)start_x;
// 	double	cos_a = cos(game->player.plane);
// 	double	sin_a = sin(game->player.plane);
// 	double	ray_x = game->player.pos_x;
// 	double	ray_y = game->player.pos_y;
// 	while (!touch(ray_x, ray_y, game))
// 	{
// 		put_pixel(game, ray_x, ray_y, 0xFF0000);
// 		ray_x += cos_a;
// 		ray_y += sin_a;
// 	}
// }

void	raycasting(t_game *game, t_player *player)
{
	double	fraction;
	double	start_x;
	int		i;

	fraction = PI / 3 / WIDTH;
	start_x = game->player.plane - PI / 6;
	i = 0;
	game->ray.cos_p = cos(game->player.plane);
	game->ray.sin_p = sin(game->player.plane);

	// printf("pos du player en x = %f, pos du player en y = %f\n\n", game->player.pos_x, game->player.pos_y);
	move_player(game);
	if (DEBUG)
	{
		draw_square(player->pos_x * SIZE_SQUARE, player->pos_y * SIZE_SQUARE, 5, 0x00FF00, game);
		draw_map(game);
	}
	while (i < WIDTH)
	{
		draw_line(&game->player, game, start_x, i);
		start_x += fraction;
		i++;
	}
}

// static int	rascasting(t_game *game)
// {
// 	// double	ray_dir_x;
// 	// double	ray_dir_y;
// 	double	side_x;
// 	double	side_y;
// 	double	camera_x;
// 	double	dist;
// 	int		x;

// 	x = 0;
// 	init_ray(game);
// 	while (x < WIDTH)
// 	{
// 		camera_x = 2.0 * x / (double)WIDTH - 1;
// 		game->ray.ray_dir_x = game->player.dir_x + game->ray.plane_x * camera_x;
// 		game->ray.ray_dir_y = game->player.dir_y + game->ray.plane_y * camera_x;
// 		// init algo dda
// 		init_dda(game, &side_x, &side_y);
// 		exec_dda(game, &side_x, &side_y);
// 		calcul_dist_wall(game, &dist);
// 		// if (draw_ray(game, &game->ray.ray_dir_x, &game->ray.ray_dir_y) == ERROR)
// 		// 	return (ERROR);
// 		x++;
// 		draw_all_3d(game);
// 	}
// 	return (OK);
// }
