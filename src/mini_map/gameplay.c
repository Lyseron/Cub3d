/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:34:39 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/11 17:34:39 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	moove_player(t_game *game, double dir_x, double dir_y)
{
	double	next_pos_player_x;
	double	next_pos_player_y;

	next_pos_player_x = game->player.pos_x + dir_x * SPEED;
	next_pos_player_y = game->player.pos_y + dir_y * SPEED;
	// printf("current: x=%f y=%f\n", game->player.pos_x,
		// game->player.pos_y);
	// printf("next: x=%f, y=%f\n", next_pos_player_x,
		// next_pos_player_y);
	if (next_pos_player_x - BORDER_PLAYER < 0
		|| next_pos_player_y - BORDER_PLAYER < 0)
		return (/*printf("ERROR: Negative Value\n"), */ERROR);
	if (next_pos_player_x + BORDER_PLAYER >= game->map.map_x
		|| next_pos_player_y + BORDER_PLAYER >= game->map.map_y)
		return (/*printf("ERROR: out of map\n"), */ERROR);
	if (is_bordplayer_touch_wall(game, next_pos_player_x,
			next_pos_player_y) == true)
		return (/*printf("ERROR: Touching wall\n"), */ERROR);
	game->player.pos_x = next_pos_player_x;
	game->player.pos_y = next_pos_player_y;
	// printf("suposidly moove to x=%f y=%f\n",
		// game->player.pos_x, game->player.pos_y);
	return (OK);
}

static int	is_moove_ok(t_game *game, int key_choice)
{
	if (key_choice == UP)
	{
		update_dir(game, 'N');
		return (moove_player(game, game->player.dir_x, game->player.dir_y));
	}
	else if (key_choice == LEFT)
	{
		update_dir(game, 'W');
		return (moove_player(game, game->player.dir_x, game->player.dir_y));
	}
	else if (key_choice == RIGHT)
	{
		update_dir(game, 'E');
		return (moove_player(game, game->player.dir_x, game->player.dir_y));
	}
	else if (key_choice == DOWN)
	{
		update_dir(game, 'S');
		return (moove_player(game, game->player.dir_x, game->player.dir_y));
	}
	else
		return (ERROR);
}

int	key(int key_choice, t_game *game)
{
	if (key_choice == ESC)
		return (exit_game(game), OK);
	if (is_moove_ok(game, key_choice) == OK)
		draw_mini_map(game);
	return (OK);
}
