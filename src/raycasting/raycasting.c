/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:15:59 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/21 17:14:10 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	raycasting(t_game *game, t_player *player)
{
	double	fraction;
	double	start_x;
	int		i;

	fraction = (PI / 3.0) / WIDTH;
	start_x = player->plane - (PI / 6.0);
	i = 0;
	game->ray.cos_p = cos(game->player.plane);
	game->ray.sin_p = sin(game->player.plane);
	move_player(game);
	if (DEBUG)
	{
		draw_square_player(player->pos_x * SIZE_SQUARE,
			player->pos_y * SIZE_SQUARE, 0x00FF00, game);
		draw_map(game);
	}
	while (i < WIDTH)
	{
		if (DEBUG)
			draw_line_2d(&game->player, game, start_x, i);
		else
			draw_line(game, start_x, i);
		start_x += fraction;
		i++;
	}
}
