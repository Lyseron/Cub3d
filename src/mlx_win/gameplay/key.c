/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:16:59 by mvignes           #+#    #+#             */
/*   Updated: 2026/07/07 11:44:37 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

void	toggle(t_game *game, int which_change)
{
	if (which_change == 1)
	{
		if (game->bool_key.change_map == true)
			game->bool_key.change_map = false;
		else if (game->bool_key.change_map == false)
			game->bool_key.change_map = true;
	}
	else
	{
		if (game->bool_key.change_hand == true)
			game->bool_key.change_hand = false;
		else if (game->bool_key.change_hand == false)
			game->bool_key.change_hand = true;
	}
}

int	display_keywee(int key, t_game *game)
{
	if (key == MAP_CHANGE)
	{
		toggle(game, 1);
		if (display_check(game) == ERROR)
			return (ERROR);
	}
	if (key == HAND_CHANGE)
	{
		toggle(game, 0);
		if (display_check(game) == ERROR)
			return (ERROR);
	}
	return (OK);
}

int	keywee(int key, t_game *game)
{
	// printf("key = [%d]\n", key);
	if (key == ESC)
		return (exit_game(game), OK);
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
	if (key == MOUSE)
	{
		if (game->bool_key.mouse)
			game->bool_key.mouse = false;
		else
			game->bool_key.mouse = true;
	}
	if (key == DOOR && !game->bool_key.door)
	{
		game->bool_key.door = true;
		door_open(game);
	}
	if (display_keywee(key, game) == ERROR)
		return (ERROR);
	return (OK);
}
