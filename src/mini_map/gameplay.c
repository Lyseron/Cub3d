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

static bool	bordplayer_cond(t_game *game)
{
	if (game->mini_player.player_left < game->mini_map.map_case_right
		&& game->mini_player.player_right > game->mini_map.map_case_left
		&& game->mini_player.player_top < game->mini_map.map_case_bottom
		&& game->mini_player.player_bottom > game->mini_map.map_case_top)
		return (true);
	return (false);
}

static bool	is_bordplayer_touch_wall(t_game *game, double next_x, double next_y)
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

int	key(int key_choice, t_game *game)
{
	int	error;

	// printf("key: %d\n", key_choice);
	error = 0;
	(void)game;
	if (key_choice == ESC)
		return (exit_game(game), OK);
	if (key_choice == UP)
		error = moove_player(game, get_dir_x('N'), get_dir_y('N'));
	else if (key_choice == LEFT)
		error = moove_player(game, get_dir_x('W'), get_dir_y('W'));
	else if (key_choice == RIGHT)
		error = moove_player(game, get_dir_x('E'), get_dir_y('E'));
	else if (key_choice == DOWN)
		error = moove_player(game, get_dir_x('S'), get_dir_y('S'));
	if (error == OK)
		draw_tiny_map(game);
	return (OK);
}
