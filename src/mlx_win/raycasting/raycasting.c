/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:15:59 by mvignes           #+#    #+#             */
/*   Updated: 2026/07/07 11:40:53 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	calcul_angle_player(t_ray *ray, t_player *player)
{
	ray->cos_p = cos(player->angle);
	ray->sin_p = sin(player->angle);
}

static void	init_raycasting(t_game *game, double *fraction, double *start_x)
{
	*fraction = PI / 3 / game->width;
	*start_x = game->player.angle - PI / 6.0;
	calcul_angle_player(&game->ray, &game->player);
}
int	raycasting(t_game *game, t_player *player)
{
	double	fraction;
	double	start_x;
	int		i;

	init_raycasting(game, &fraction, &start_x);
	calcul_angle_player(&game->ray, player);
	// if (DEBUG)
	// {
	// 	draw_square_player(player->pos_x * SIZE_SQUARE,
	// 		player->pos_y * SIZE_SQUARE, 0x00FF00, game);
	// 	draw_map(game);
	// }
	i = 0;
	while (i < game->width)
	{
		if (DEBUG)
			draw_line_2d(&game->player, game, start_x, i);
		else
			draw_line(game, start_x, i);
		start_x += fraction;
		i++;
	}
	calcul_angle_player(&game->ray, player);
	return (OK);
}
