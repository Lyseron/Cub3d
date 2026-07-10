/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vignesmattheu <vignesmattheu@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 06:46:14 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/10 22:27:11 by vignesmatth      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
			if ((x < ft_strlen(game->map.grid[y])
					&& game->map.grid[y][x] == '1')
					|| (x < ft_strlen(game->map.grid[y])
					&& game->map.grid[y][x] == '2'))
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

// adding the distance from the middle of the screen
//void	mouse_moove(t_game *game)
//{
//	int	x;
//	int	y;
//	int	dist_from_middle_screen;
//
//	if (game->bool_key.mouse)
//	{
//		mlx_mouse_get_pos(game->mlx, game->win, &x, &y);
//		dist_from_middle_screen = x - (game->width / 2);
//		if (dist_from_middle_screen == 0)
//			return ;
//		game->player.angle += dist_from_middle_screen * SENSITIVITY_MOUSE;
//		update_dir(game);
//		game->moved = true;
//		mlx_mouse_move(game->mlx, game->win, game->width / 2, game->height / 2);
//		mlx_mouse_hide(game->mlx, game->win);
//	}
//	else
//		mlx_mouse_show(game->mlx, game->win);
//}
//