/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 06:46:14 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/17 06:46:14 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	update_dir(t_game *game, char look)
{
	game->player.dir_x = get_dir_x(look);
	game->player.dir_y = get_dir_y(look);
	game->ray.plane_x = -game->player.dir_y * 0.66;
	game->ray.plane_y = game->player.dir_x * 0.66;
}

static bool	bordplayer_cond(t_game *game)
{
	if (game->mini_player.player_left < game->mini_map.map_case_right
		&& game->mini_player.player_right > game->mini_map.map_case_left
		&& game->mini_player.player_top < game->mini_map.map_case_bottom
		&& game->mini_player.player_bottom > game->mini_map.map_case_top)
		return (true);
	return (false);
}

bool	is_bordplayer_touch_wall(t_game *game, double next_x, double next_y)
{
	int	y;
	int	x;

	init_mini_player_square(game, next_x, next_y);
	y = 0;
	while (y < game->map.map_y)
	{
		x = 0;
		while (x < game->map.map_x)
		{
			init_mini_map_square(game, x, y);
			if (game->map.grid[y][x] == '1')
			{
				if (bordplayer_cond(game) == true)
					return (true);
			}
			x++;
		}
		y++;
	}
	return (false);
}
