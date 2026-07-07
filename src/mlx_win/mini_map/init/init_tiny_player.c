/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tiny_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 05:06:27 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/18 05:06:27 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_tiny_player(t_game *game)
{
	game->mini_player.start_x = MARGE + CASE_FROM_PLAYER * SIZE_SQUARE
		+ ((SIZE_SQUARE - SIZE_PLAYER) / 2);
	game->mini_player.start_y = MARGE + CASE_FROM_PLAYER * SIZE_SQUARE
		+ ((SIZE_SQUARE - SIZE_PLAYER) / 2);
	game->mini_player.end_y = game->mini_player.start_y + SIZE_PLAYER;
	game->mini_player.end_x = game->mini_player.start_x + SIZE_PLAYER;
}
