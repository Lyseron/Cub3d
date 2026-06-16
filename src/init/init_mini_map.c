/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 07:08:20 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/16 07:08:20 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_mini_player(t_game *game)
{
	game->mini_player.center_x = game->player.pos_x * SIZE_SQUARE + 15;
	game->mini_player.center_y = game->player.pos_y * SIZE_SQUARE + 15;
	game->mini_player.start_x = game->mini_player.center_x - (SIZE_PLAYER / 2);
	game->mini_player.start_y = game->mini_player.center_y - (SIZE_PLAYER / 2);
	game->mini_player.end_y = game->mini_player.start_y + SIZE_PLAYER;
	game->mini_player.end_x = game->mini_player.start_x + SIZE_PLAYER;
	game->mini_player.player_pixel_y = game->mini_player.start_y;
}

void	init_mini_map_coord(t_mini_map *mini_map, int map_x, int map_y)
{
	if (!mini_map)
		return ;
	mini_map->start_y = map_y * SIZE_SQUARE + 15;
	mini_map->start_x = map_x * SIZE_SQUARE + 15;
	mini_map->end_y = mini_map->start_y + SIZE_SQUARE;
	mini_map->end_x = mini_map->start_x + SIZE_SQUARE;
	mini_map->win_y = mini_map->start_y;
}

// For the collision
void	init_mini_player_square(t_game *game, double next_x, double next_y)
{
	game->mini_player.player_top = next_y - BORDER_PLAYER;
	game->mini_player.player_bottom = next_y + BORDER_PLAYER;
	game->mini_player.player_left = next_x - BORDER_PLAYER;
	game->mini_player.player_right = next_x + BORDER_PLAYER;
}

// For the collision
void	init_mini_map_square(t_game *game, int x, int y)
{
	game->mini_map.map_case_left = x;
	game->mini_map.map_case_right = x + 1;
	game->mini_map.map_case_top = y;
	game->mini_map.map_case_bottom = y + 1;
}
