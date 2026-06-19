/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:35:41 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/19 14:48:10 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pixel = game->img.img_addr + (y * game->img.size_line + x
			* (game->img.bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

// void	put_pixel(t_game *game, int x, int y, int color)
// {
// 	// char	*pixel;

// 	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
// 		return ;

// 	int index = y * game->img.size_line + x * game->img.bits_per_pixel / 8;
// 	game->img.img_addr[index] = color & 0xFF;
// 	game->img.img_addr[index + 1] = (color >> 8) & 0xFF;
// 	game->img.img_addr[index + 2] = (color >> 16) & 0xFF;
// 	// pixel = game->img.img_addr + (y * game->img.size_line + x
// 	// 		* (game->img.bits_per_pixel / 8));
// 	// *(unsigned int *)pixel = color;
// }

bool	touch(double px, double py, t_game *game)
{
	int	x = px / SIZE_SQUARE;
	int	y = py / SIZE_SQUARE;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (true);
	if (game->map.grid[y][x] == '1')
		return (true);
	return (false);
}

float	distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

float	fixed_distance(float x1, float y1, float x2, float y2, t_game *game)
{
	float	delta_x = x2 - x1;
	float	delta_y = y2 - y1;
	float	angle = atan2(delta_y, delta_x) - game->player.plane;
	float	fix_dist = distance(delta_x, delta_y) * cos(angle);
	return (fix_dist);
}

void	draw_line(t_player *player, t_game *game, float start_x, int i)
{
	(void)player;
	(void)i;
	(void)start_x;
	float	cos_a = cos(start_x);
	float	sin_a = sin(start_x);
	float	ray_x = player->pos_x * SIZE_SQUARE;
	float	ray_y = player->pos_y * SIZE_SQUARE;
	while (!touch(ray_x, ray_y, game))
	{
		// printf("BONJOUR\n");
		if (DEBUG)
		{
			put_pixel(game, ray_x, ray_y, 0xFF0000);
		}
		// ray_x++;
		ray_x += (cos_a);
		ray_y += (sin_a);
	}
	
	
	// float	dist = distance(ray_x - player->x, ray_y - player->y);
	if (!DEBUG)
	{
		float	dist = fixed_distance(player->pos_x, player->pos_y, ray_x, ray_y, game);
		float	height = height = (SIZE_SQUARE / dist) * (WIDTH / 2);
		int		start_y = (HEIGHT - height) / 2;
		int		end = start_y + height;
		while (start_y < end)
		{
			put_pixel(game, i, start_y, 255);
			start_y++;
		}
	}
}

void	draw_all_3d(t_game *game)
{
	(void)game;
	printf("CC TU ES LA \n");
}
