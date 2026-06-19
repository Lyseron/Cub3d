/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:27:14 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/19 13:31:41 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_square(int x, int y, int size, int color, t_game *game)
{

	// printf("DEBUG 1\n");
	for (int i = 0; i < size;i++)
		put_pixel(game, x + i, y, color);
	// printf("DEBUG 2\n");
	for (int i = 0; i < size;i++)
		put_pixel(game, x, y + i, color);
	// printf("DEBUG 3\n");
	for (int i = 0; i < size;i++)
		put_pixel(game, x + size, y + i, color);
	// printf("DEBUG 4\n");
	for (int i = 0; i < size;i++)
		put_pixel(game, x + i, y + size, color);
	// printf("DEBUG 5\n");
}

void	draw_map(t_game *game)
{
	char	**map = game->map.grid;
	int		color = 0x0000FF;
	for (int y = 0; map[y];y++)
		for (int x = 0;map[y][x];x++)
			if (map[y][x] == '1')
				draw_square(x * SIZE_SQUARE, y * SIZE_SQUARE, SIZE_SQUARE, color, game);
}
