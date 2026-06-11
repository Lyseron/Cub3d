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

int	moove_player(t_game *game, double dir_x, double dir_y)
{
	char	tile_to_check;
	double	next_pos_player_x;
	double	next_pos_player_y;

	next_pos_player_x = game->player.pos_x + dir_x * 0.5;
	next_pos_player_y = game->player.pos_y + dir_y * 0.5;
	// printf("current: x=%f y=%f\n", game->player.pos_x, game->player.pos_y);
	// printf("next: x=%f, y=%f\n", next_pos_player_x, next_pos_player_y);
	if (next_pos_player_x < 0 || next_pos_player_y < 0)
		return (ERROR);
	if (next_pos_player_x >= game->map.map_x || next_pos_player_y >= game->map.map_y)
		return (ERROR);
	tile_to_check = game->map.grid[(int)next_pos_player_y][(int)next_pos_player_x];
	if (tile_to_check == '1')
		return (ERROR);
	game->player.pos_x = next_pos_player_x;
	game->player.pos_y = next_pos_player_y;
	// printf("suposidly moove to x=%f y=%f\n", game->player.pos_x, game->player.pos_y);
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
	if (error != OK)
		return (ERROR);
	else
		draw_tiny_map(game);
	return (OK);
}
