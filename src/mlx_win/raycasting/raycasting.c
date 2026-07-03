/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vignesmattheu <vignesmattheu@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:15:59 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/23 15:56:52 by vignesmatth      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	raycasting(t_game *game, t_player *player)
{
	double	fraction;
	double	start_x;
	int		i;

	fraction = (PI / 3.0) / game->width;
	start_x = player->angle - (PI / 6.0);
	i = 0;
	game->ray.cos_p = cos(game->player.angle);
	game->ray.sin_p = sin(game->player.angle);
	// if (DEBUG)
	// {
	// 	draw_square_player(player->pos_x * SIZE_SQUARE,
	// 		player->pos_y * SIZE_SQUARE, 0x00FF00, game);
	// 	draw_map(game);
	// }
	while (i < game->width)
	{
		if (DEBUG)
			draw_line_2d(&game->player, game, start_x, i);
		else
			draw_line(game, start_x, i);
		start_x += fraction;
		i++;
	}
	return (OK);
}
