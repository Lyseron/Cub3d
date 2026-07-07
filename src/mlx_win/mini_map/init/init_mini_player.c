/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mini_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 09:16:08 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/16 09:16:08 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_mini_player(t_game *game)
{
	game->mini_player.center_x = game->player.pos_x * SIZE_SQUARE + MARGE;
	game->mini_player.center_y = game->player.pos_y * SIZE_SQUARE + MARGE;
	game->mini_player.start_x = game->mini_player.center_x - (SIZE_PLAYER / 2);
	game->mini_player.start_y = game->mini_player.center_y - (SIZE_PLAYER / 2);
	game->mini_player.end_y = game->mini_player.start_y + SIZE_PLAYER;
	game->mini_player.end_x = game->mini_player.start_x + SIZE_PLAYER;
}

// For the collision
void	init_mini_player_square(t_game *game, double next_x, double next_y)
{
	game->mini_player.player_top = next_y - BORDER_PLAYER;
	game->mini_player.player_bottom = next_y + BORDER_PLAYER;
	game->mini_player.player_left = next_x - BORDER_PLAYER;
	game->mini_player.player_right = next_x + BORDER_PLAYER;
}
