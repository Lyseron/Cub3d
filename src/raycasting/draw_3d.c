/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:35:41 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/22 20:34:56 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// double	distance(double x, double y)
// {
// 	return (sqrt(x * x + y * y));
// }

// double	fixed_distance(double x1, double y1, double x2, double y2,
// 	t_game *game)
// {
// 	double	delta_x = x2 - x1;
// 	double	delta_y = y2 - y1;
// 	double	angle = atan2(delta_y, delta_x) - game->player.plane;
// 	double	fix_dist = distance(delta_x, delta_y) * cos(angle);
// 	return (fix_dist);
// }

// void	draw_line(t_player *player, t_game *game, double start_x, int i)
// {
// 	(void)player;
// 	(void)i;
// 	(void)start_x;
// 	double	cos_a = cos(start_x);
// 	double	sin_a = sin(start_x);
// 	double	ray_x = player->pos_x * SIZE_SQUARE;
// 	double	ray_y = player->pos_y * SIZE_SQUARE;
// 	while (!touch(ray_x, ray_y, game))
// 	{
// 		if (DEBUG)
// 			put_pixel(game, ray_x, ray_y, 0xFF0000);
// 		ray_x += (cos_a);
// 		ray_y += (sin_a);
// 	}
// }

void	init_draw_3d(t_game *game, t_ray *ray)
{
	ray->line_height = game->height / ray->dist_perp;
	ray->start_y = (game->height / 2) - (ray->line_height / 2);
	ray->end = (game->height / 2) + (ray->line_height / 2);
	if (ray->start_y < 0)
		ray->start_y = 0;
	if (ray->end >= game->height)
		ray->end = game->height - 1;
}

void	draw_3d(t_game *game, t_ray *ray, int y, int i)
{
	// double	angle_correctif;

	// angle_correctif = y - game->height / 2;
	if (y < ray->start_y)
	{
		put_pixel(game, i, y, 0xF33333);
	}
	else if (y >= ray->start_y && y <= ray->end)
	{
		if (ray->wall_touch == 1)
			put_pixel(game, i, y, 0xF000FF);
		else if (ray->wall_touch == 2)
			put_pixel(game, i, y, 0x0000BB);
		else if (ray->wall_touch == 3)
			put_pixel(game, i, y, 0x000088);
		else
			put_pixel(game, i, y, 0xF00055);
	}
	else
	{
		put_pixel(game, i, y, 0x666666);
	}
}

void	draw_line(t_game *game, double angle_rayon, int i)
{
	int		y;
	t_ray	*ray;

	y = 0;
	ray = &game->ray;
	init_dda(game, ray, angle_rayon);
	calcul_direct_wall(&game->player, ray);
	calcul_horizontal_intersection(game, ray);
	calcul_dist(game, &game->ray, angle_rayon);
	search_cote_wall(game, ray);
	init_draw_3d(game, &game->ray);
	while (y < game->height)
	{
		draw_3d(game, ray, y, i);
		y++;
	}
}
