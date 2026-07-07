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

void	init_mini_map_coord(t_mini_map *mini_map, int map_x, int map_y)
{
	if (!mini_map)
		return ;
	mini_map->start_y = convert_map_y_to_win_y(map_y);
	mini_map->start_x = convert_map_x_to_win_x(map_x);
	mini_map->end_y = mini_map->start_y + SIZE_SQUARE;
	mini_map->end_x = mini_map->start_x + SIZE_SQUARE;
}

// For the collision
void	init_mini_map_square(t_game *game, int x, int y)
{
	game->mini_map.map_case_left = x;
	game->mini_map.map_case_right = x + 1;
	game->mini_map.map_case_top = y;
	game->mini_map.map_case_bottom = y + 1;
}
