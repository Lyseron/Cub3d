/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tiny_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 05:03:12 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/18 05:03:12 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_tiny_map_coord(t_tiny_map *tiny_map)
{
	if (!tiny_map)
		return ;
	tiny_map->start_pixel_y = tiny_map->pixel_y;
	tiny_map->end_pixel_y = tiny_map->start_pixel_y + SIZE_SQUARE;
	tiny_map->start_pixel_x = tiny_map->pixel_x;
	tiny_map->end_pixel_x = tiny_map->start_pixel_x + SIZE_SQUARE;
}

void	init_tiny_map_bound(t_game *game)
{
	game->tiny_map.start_y = (int)game->player.pos_y - CASE_FROM_PLAYER;
	game->tiny_map.end_y = (int)game->player.pos_y + CASE_FROM_PLAYER;
	game->tiny_map.start_x = (int)game->player.pos_x - CASE_FROM_PLAYER;
	game->tiny_map.end_x = (int)game->player.pos_x + CASE_FROM_PLAYER;
	game->tiny_map.min_x = MARGE;
	game->tiny_map.min_y = MARGE;
	game->tiny_map.max_x = MARGE + ((CASE_FROM_PLAYER * 2 + 1) * SIZE_SQUARE);
	game->tiny_map.max_y = MARGE + ((CASE_FROM_PLAYER * 2 + 1) * SIZE_SQUARE);
	game->tiny_map.player_center_x = (game->tiny_map.min_x
			+ game->tiny_map.max_x) / 2;
	game->tiny_map.player_center_y = (game->tiny_map.min_y
			+ game->tiny_map.max_y) / 2;
}
