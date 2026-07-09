/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tiny_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 02:52:18 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/09 11:02:51 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	get_pos_pixel_to_draw(t_game *game, int x, int y)
{
	game->tiny_map.pixel_x = convert_x_to_pixel(game, x);
	game->tiny_map.pixel_y = convert_y_to_pixel(game, y);
}

static int	tiny_map_conditions2(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == '1')
	{
		if (draw_tiny_square(game, COLOR_WALL) == ERROR)
			return (ERROR);
	}
	else if (game->map.grid[y][x] == '0')
	{
		if (draw_tiny_square(game, COLOR_FLOOR) == ERROR)
			return (ERROR);
	}
	else if (game->map.grid[y][x] == ' ')
	{
		if (draw_tiny_square(game, COLOR_BACKGROUND) == ERROR)
			return (ERROR);
	}
	else if (game->map.grid[y][x] == '2' || game->map.grid[y][x] == '3')
	{
		if (draw_tiny_square(game, COLOR_DOOR) == ERROR)
			return (ERROR);
	}
	return (OK);
}

static int	tiny_map_conditions(t_game *game, int x, int y)
{
	if (y >= 0 && y < game->map.map_y && game->map.grid[y]
		&& x >= 0 && x < ft_strlen(game->map.grid[y]))
	{
		get_pos_pixel_to_draw(game, x, y);
		if (tiny_map_conditions2(game, x, y) == ERROR)
			return (ERROR);
	}
	return (OK);
}

static int	draw_tiny_case_win(t_game *game)
{
	int	y;
	int	x;

	y = game->tiny_map.start_y;
	while (y <= game->tiny_map.end_y)
	{
		x = game->tiny_map.start_x;
		while (x <= game->tiny_map.end_x)
		{
			if (tiny_map_conditions(game, x, y) == ERROR)
				return (ERROR);
			x++;
		}
		y++;
	}
	return (OK);
}

int	draw_tiny_map(t_game *game)
{
	if (!game || !game->map.grid)
		return (ERROR);
	init_tiny_map_bound(game);
	if (draw_frame(game) == ERROR)
		return (ERROR);
	if (draw_background(game) == ERROR)
		return (ERROR);
	if (draw_tiny_case_win(game) == ERROR)
		return (ERROR);
	if (draw_tiny_player(game) == ERROR)
		return (ERROR);
	if (draw_all_tiny_ray(game) == ERROR)
		return (ERROR);
	return (OK);
}
