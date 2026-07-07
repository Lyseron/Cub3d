/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 22:52:14 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/07 22:52:14 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	player_movement(t_game *game)
{
	if (game->bool_key.w && is_moove_ok(game, UP) == OK)
		game->moved = true;
	if (game->bool_key.a && is_moove_ok(game, LEFT) == OK)
		game->moved = true;
	if (game->bool_key.s && is_moove_ok(game, DOWN) == OK)
		game->moved = true;
	if (game->bool_key.d && is_moove_ok(game, RIGHT) == OK)
		game->moved = true;
}

void	key_moove(t_game *game)
{
	player_movement(game);
	if (game->moved == true)
	{
		moove_anim(&game->right_hand);
		moove_anim(&game->left_hand);
	}
	if (game->bool_key.left)
	{
		game->player.angle += TURN_LEFT * SPEED_CAM;
		update_dir(game);
		game->moved = true;
	}
	if (game->bool_key.right)
	{
		game->player.angle += TURN_RIGTH * SPEED_CAM;
		update_dir(game);
		game->moved = true;
	}
	if (game->bool_key.door == true)
		game->moved = true;
}
