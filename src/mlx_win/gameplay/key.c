/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vignesmattheu <vignesmattheu@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:16:59 by mvignes           #+#    #+#             */
/*   Updated: 2026/07/10 22:31:39 by vignesmatth      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/// @brief It’s a relasse key function, in the release key by the user,
/// @brief the bool becomes NULL.
/// @param key 
/// @param game 
/// @return Null value for while mlx in main
int	keyno(int key, t_game *game)
{
	if (key == UP)
		game->bool_key.w = false;
	if (key == LEFT)
		game->bool_key.a = false;
	if (key == DOWN)
		game->bool_key.s = false;
	if (key == RIGHT)
		game->bool_key.d = false;
	if (key == ARROW_LEFT)
		game->bool_key.left = false;
	if (key == ARROW_RIGHT)
		game->bool_key.right = false;
	if (key == SHIFT)
		game->bool_key.shift = false;
	if (key == DOOR)
		game->bool_key.door = false;
		
	return (OK);
}

/// @brief Change the bool if true for false and change if false for true
/// @param which_change 
static void	toggle(bool *which_change)
{
	if (*which_change == true)
		*which_change = false;
	else if (*which_change == false)
		*which_change = true;
}

static void	wall_anim(int key, t_game *game)
{
	if (game->good_texture)
	{
		if (key == START_ANIM_WALL && game->start_anim_wall == false)
		{
			game->start_anim_wall = true;
			game->mona.frame_id = 0;
			game->mona.nb_of_loop = 0;
			game->munch.frame_id = 0;
			game->munch.nb_of_loop = 0;
		}
	}
}

int	display_keywee(int key, t_game *game)
{
	if (key == MAP_CHANGE)
	{
		toggle(&game->bool_key.change_map);
		if (display_check(game) == ERROR)
			return (ERROR);
	}
	if (key == HAND_CHANGE && game->close_door == true
		&& game->bool_key.change_hand == false && game->anim_is_finish)
	{
		(toggle(&game->bool_key.change_hand), game->anim_is_finish = false);
		game->phone.frame_id = 0;
		game->phone.nb_of_loop = 0;
		if (display_check(game) == ERROR)
			return (ERROR);
	}
	if (key == MOUSE)
	{
		toggle(&game->bool_key.mouse);
		if (display_check(game) == ERROR)
			return (ERROR);
	}
	if (key == VIEW_KEY_PRESS)
		toggle(&game->bool_key.view_key_press);
	wall_anim(key, game);
	return (OK);
}

/// @brief It’s a relasse key function, in the press key by the user,
/// @brief the bool becomes true.
/// @param key 
/// @param game 
/// @return Null value for while mlx in main
int	keywee(int key, t_game *game)
{
	if (key == ESC)
		return (exit_game(game, OK));
	if (key == UP)
		game->bool_key.w = true;
	if (key == LEFT)
		game->bool_key.a = true;
	if (key == DOWN)
		game->bool_key.s = true;
	if (key == RIGHT)
		game->bool_key.d = true;
	if (key == ARROW_LEFT)
		game->bool_key.left = true;
	if (key == ARROW_RIGHT)
		game->bool_key.right = true;
	if (key == SHIFT)
		game->bool_key.shift = true;
	if (key == DOOR && !game->bool_key.door)
	{
		game->bool_key.door = true;
		game->anim_is_finish = false;
		game->bool_key.change_hand = true;
	}
	if (display_keywee(key, game) == ERROR)
		return (ERROR);
	return (OK);
}
