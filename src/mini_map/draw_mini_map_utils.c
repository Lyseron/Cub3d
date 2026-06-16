/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 09:25:19 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/16 09:25:19 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	draw_pixel(t_game *game, int x, int y, unsigned int color)
{
	int		pos_pixel;
	char	*pixel;

	if (!game || !game->img.img_addr)
		return (ERROR);
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (ERROR);
	if (game->img.size_line <= 0 || game->img.bits_per_pixel <= 0)
		return (ERROR);
	pos_pixel = (y * game->img.size_line + x * (game->img.bits_per_pixel / 8));
	if (pos_pixel < 0)
		return (ERROR);
	pixel = game->img.img_addr + pos_pixel;
	if (pixel == NULL)
		return (ERROR);
	*(unsigned int *)pixel = color;
	return (OK);
}

int	draw_tiny_square(t_game *game, int map_x, int map_y, int color)
{
	if (!game)
		return (ERROR);
	init_mini_map_coord(&game->mini_map, map_x, map_y);
	while (game->mini_map.win_y < game->mini_map.end_y)
	{
		game->mini_map.win_x = game->mini_map.start_x;
		while (game->mini_map.win_x < game->mini_map.end_x)
		{
			if (draw_pixel(game, game->mini_map.win_x,
					game->mini_map.win_y, color) == ERROR)
				return (ERROR);
			game->mini_map.win_x++;
		}
		game->mini_map.win_y++;
	}
	return (OK);
}

int	tiny_map_conditions(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == '1')
	{
		if (draw_tiny_square(game, x, y, 0x800080) == ERROR)
			return (ERROR);
	}
	else if (game->map.grid[y][x] == '0')
	{
		if (draw_tiny_square(game, x, y, 0x008000) == ERROR)
			return (ERROR);
	}
	return (OK);
}
