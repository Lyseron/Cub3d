/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:22:38 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/11 16:42:26 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"
#include "../includes/parsing.h"

static void	init_mini_map_coord(t_game *game, int map_x, int map_y)
{
	if (!game)
		return ;
	game->mini_map.start_y = map_y * SIZE_SQUARE + 15;
	game->mini_map.start_x = map_x * SIZE_SQUARE + 15;
	game->mini_map.end_y = game->mini_map.start_y + SIZE_SQUARE;
	game->mini_map.end_x = game->mini_map.start_x + SIZE_SQUARE;
	game->mini_map.win_y = game->mini_map.start_y;
}

static int	draw_tiny_square(t_game *game, int map_x, int map_y, int color)
{
	if (!game)
		return (ERROR);
	init_mini_map_coord(game, map_x, map_y);
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

static int	draw_player_in_tiny_map(t_game *game)
{
	if (draw_tiny_square(game, game->player.pos_x,
			game->player.pos_y, 0x0000FF) == ERROR)
		return (ERROR);
	return (OK);
}

static int	tiny_map_conditions(t_game *game, int x, int y)
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

int	draw_tiny_map(t_game *game)
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
	if (draw_player_in_tiny_map(game) == ERROR)
		return (ERROR);
	return (OK);
}
