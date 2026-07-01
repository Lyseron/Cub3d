/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:16:59 by mvignes           #+#    #+#             */
/*   Updated: 2026/07/01 17:27:27 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	action_door(t_game *game)
{
	t_ray	*ray;

	ray = &game->ray;
	// if (game->map.grid[(int)game->player.pos_y][(int)game->player.pos_x] == '2')
	if (ray->touch == '2')
		printf("OUI OUI BAGUETTE\n");
}

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
	if (key == XK_e)
		game->bool_key.door = false;
	return (0);
}

int	keywee(int key, t_game *game)
{
	if (key == ESC)
		exit_game(game);
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
	if (key == XK_e)
		game->bool_key.door = true;
	return (0);
}
