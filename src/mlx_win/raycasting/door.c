/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:04:47 by mvignes           #+#    #+#             */
/*   Updated: 2026/07/09 11:09:18 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/// @brief Check if there is a door on a given coord x, y
/// @param game 
/// @param x 
/// @param y 
/// @return  retour true s'il y a une porte
static bool	is_door_cell(t_game *game, int x, int y)
{
	if (y < 0 || y >= game->map.map_y)
		return (false);
	if (x < 0 || x >= (int)ft_strlen(game->map.grid[y]))
		return (false);
	if (game->map.grid[y][x] == '2' || game->map.grid[y][x] == '3')
		return (true);
	return (false);
}

/// @brief Look is there is a door in front of the player (distance is = a
/// @brief DOOR_RANGE)
/// @param game 
/// @param tx 
/// @param ty 
/// @return 
static bool	get_door_target(t_game *game, int *tx, int *ty)
{
	double	d;
	int		cx;
	int		cy;

	d = 0.2;
	while (d <= DOOR_RANGE)
	{
		cx = (int)(game->player.pos_x + game->ray.cos_p * d);
		cy = (int)(game->player.pos_y + game->ray.sin_p * d);
		if (is_door_cell(game, cx, cy))
		{
			*tx = cx;
			*ty = cy;
			return (true);
		}
		d += 0.1;
	}
	return (false);
}

static bool	is_bordplayer_touch_door(t_game *game, double x, double y)
{
	double	door_right;
	double	door_left;
	double	door_top;
	double	door_bottom;

	door_left = x;
	door_right = x + 1;
	door_top = y;
	door_bottom = y + 1;
	init_mini_player_square(game, game->player.pos_x, game->player.pos_y);
	if (game->mini_player.player_left < door_right
		&& game->mini_player.player_right > door_left
		&& game->mini_player.player_top < door_bottom
		&& game->mini_player.player_bottom > door_top)
		return (true);
	return (false);
}

/// @brief Find a foor in front of the player
/// @param game 
void	door_open(t_game *game)
{
	int	x;
	int	y;

	if (!get_door_target(game, &x, &y))
		return ;
	if (game->map.grid[y][x] == '2')
	{
		game->close_door = true;
		game->open_door = false;
		game->map.grid[y][x] = '3';
	}
	else if (game->map.grid[y][x] == '3')
	{
		game->open_door = true;
		game->close_door = false;
		if (is_bordplayer_touch_door(game, x, y) == false)
			game->map.grid[y][x] = '2';
	}
}
