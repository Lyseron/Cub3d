/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:34:39 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/16 18:07:02 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// static bool	bordplayer_cond(t_game *game)
// {
// 	if (game->mini_player.player_left < game->mini_map.map_case_right
// 		&& game->mini_player.player_right > game->mini_map.map_case_left
// 		&& game->mini_player.player_top < game->mini_map.map_case_bottom
// 		&& game->mini_player.player_bottom > game->mini_map.map_case_top)
// 		return (true);
// 	return (false);
// }

// static bool	is_bordplayer_touch_wall(t_game *game, double next_x, double next_y)
// {
// 	int	y;
// 	int	x;

// 	init_mini_player_square(game, next_x, next_y);
// 	y = 0;
// 	while (y < game->map.map_y)
// 	{
// 		x = 0;
// 		while (x < game->map.map_x)
// 		{
// 			init_mini_map_square(game, x, y);
// 			if (game->map.grid[y][x] == '1')
// 			{
// 				if (bordplayer_cond(game) == true)
// 					return (true);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (false);
// }

// static int	moove_player(t_game *game, double dir_x, double dir_y)
// {
// 	double	next_pos_player_x;
// 	double	next_pos_player_y;

// 	next_pos_player_x = game->player.pos_x + dir_x * SPEED;
// 	next_pos_player_y = game->player.pos_y + dir_y * SPEED;
// 	// printf("current: x=%f y=%f\n", game->player.pos_x,
// 		// game->player.pos_y);
// 	// printf("next: x=%f, y=%f\n", next_pos_player_x,
// 		// next_pos_player_y);
// 	if (next_pos_player_x - BORDER_PLAYER < 0
// 		|| next_pos_player_y - BORDER_PLAYER < 0)
// 		return (/*printf("ERROR: Negative Value\n"), */ERROR);
// 	if (next_pos_player_x + BORDER_PLAYER >= game->map.map_x
// 		|| next_pos_player_y + BORDER_PLAYER >= game->map.map_y)
// 		return (/*printf("ERROR: out of map\n"), */ERROR);
// 	if (is_bordplayer_touch_wall(game, next_pos_player_x,
// 			next_pos_player_y) == true)
// 		return (/*printf("ERROR: Touching wall\n"), */ERROR);
// 	game->player.pos_x = next_pos_player_x;
// 	game->player.pos_y = next_pos_player_y;
// 	// printf("suposidly moove to x=%f y=%f\n",
// 		// game->player.pos_x, game->player.pos_y);
// 	return (OK);
// }

// static void	update_dir(t_game *game, char look)
// {
// 	game->player.dir_x = get_dir_x(look);
// 	game->player.dir_y = get_dir_y(look);
// 	// game->ray.plane_x = -game->player.dir_y * 0.66;
// 	// game->ray.plane_y = game->player.dir_x * 0.66;
// }

// // static void	update_plane(t_game *game, int key)
// // {
// // 	if (key == XK_Left)
// // 	{
// // 		game->ray.plane_x = -game->player.plane_y * 0.66;
// // 		game->ray.plane_y = game->player.plane_x * 0.66;
// // 	}
// // 	else
// // 	{
// // 		game->ray.plane_x = -game->player.dir_y * 0.66;
// // 		game->ray.plane_y = game->player.dir_x * 0.66;
// // 	}
// // }

// static int	is_moove_ok(t_game *game, int key_choice)
// {
// 	if (key_choice == UP)
// 	{
// 		update_dir(game, 'N');
// 		return (moove_player(game, game->player.dir_x, game->player.dir_y));
// 	}
// 	else if (key_choice == LEFT)
// 	{
// 		update_dir(game, 'W');
// 		return (moove_player(game, game->player.dir_x, game->player.dir_y));
// 	}
// 	else if (key_choice == RIGHT)
// 	{
// 		update_dir(game, 'E');
// 		return (moove_player(game, game->player.dir_x, game->player.dir_y));
// 	}
// 	else if (key_choice == DOWN)
// 	{
// 		update_dir(game, 'S');
// 		return (moove_player(game, game->player.dir_x, game->player.dir_y));
// 	}
// 	// else if (key_choice == XK_Left || key_choice == XK_Right)
// 	// 	return (update_plane(game, key_choice), 0);
// 	else
// 		return (ERROR);
// }

int	key(int key_choice, t_game *game)
{
	if (key_choice == ESC)
		return (exit_game(game), OK);
	// is_moove_ok(game, key_choice);
		// draw_mini_map(game);
	return (OK);
}
