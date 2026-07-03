/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:22:38 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/10 18:22:38 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	mini_map_conditions(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == '1')
	{
		if (draw_mini_square(game, x, y, COLOR_WALL) == ERROR)
			return (ERROR);
	}
	else if (game->map.grid[y][x] == '0')
	{
		if (draw_mini_square(game, x, y, COLOR_FLOOR) == ERROR)
			return (ERROR);
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
			if (mini_map_conditions(game, x, y) == ERROR)
				return (ERROR);
			x++;
		}
		y++;
	}
	if (draw_player(game) == ERROR)
		return (ERROR);
	if (draw_all_ray(game) == ERROR)
		return (ERROR);
	return (OK);
}
