/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:27:14 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/22 15:34:59 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_square_player(int x, int y, int color, t_game *game)
{
	int	i;

	i = -1;
	while (++i < 5)
		put_pixel(game, x + i, y, color);
	i = -1;
	while (++i < 5)
		put_pixel(game, x, y + i, color);
	i = -1;
	while (++i < 5)
		put_pixel(game, x + 5, y + i, color);
	i = -1;
	while (++i < 5)
		put_pixel(game, x + i, y + 5, color);
}

void	draw_square(int x, int y, int color, t_game *game)
{
	int	i;

	i = -1;
	while (++i < SIZE_SQUARE)
		put_pixel(game, x + i, y, color);
	i = -1;
	while (++i < SIZE_SQUARE)
		put_pixel(game, x, y + i, color);
	i = -1;
	while (++i < SIZE_SQUARE)
		put_pixel(game, x + SIZE_SQUARE, y + i, color);
	i = -1;
	while (++i < SIZE_SQUARE)
		put_pixel(game, x + i, y + SIZE_SQUARE, color);
}

void	draw_map(t_game *game)
{
	char	**map;
	int		color;

	map = game->map.grid;
	color = 0x0000FF;
	game->ray.map_y = 0;
	while (map[game->ray.map_y])
	{
		game->ray.map_x = 0;
		while (map[game->ray.map_y][game->ray.map_x])
		{
			if (map[game->ray.map_y][game->ray.map_x] == '1')
				draw_square(game->ray.map_x * SIZE_SQUARE,
					game->ray.map_y * SIZE_SQUARE, color, game);
			game->ray.map_x++;
		}
		game->ray.map_y++;
	}
}

static bool	touch(double px, double py, t_game *game)
{
	int	x;
	int	y;

	x = px / SIZE_SQUARE;
	y = py / SIZE_SQUARE;
	if (x < 0 || x >= game->width || y < 0 || y >= game->height)
		return (true);
	if (game->map.grid[y][x] == '1')
		return (true);
	return (false);
}

void	draw_line_2d(t_player *player, t_game *game, double start_x, int i)
{
	double	cos_a;
	double	sin_a;
	double	ray_x;
	double	ray_y;

	(void)i;
	cos_a = cos(start_x);
	sin_a = sin(start_x);
	ray_x = player->pos_x * SIZE_SQUARE;
	ray_y = player->pos_y * SIZE_SQUARE;
	while (!touch(ray_x, ray_y, game))
	{
		put_pixel(game, ray_x, ray_y, 0xFF0000);
		ray_x += (cos_a);
		ray_y += (sin_a);
	}
}
