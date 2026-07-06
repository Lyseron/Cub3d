/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:15:59 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/30 15:43:01 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	calcul_angle_player(t_ray *ray, t_player *player)
{
	ray->cos_p = cos(player->plane);
	ray->sin_p = sin(player->plane);
}

void	init_raycasting(t_game *game, double *fraction, double *start_x)
{
	*fraction = PI / 3 / game->width;
	*start_x = game->player.plane - PI / 6.0;
	calcul_angle_player(&game->ray, &game->player);
}

void	raycasting(t_game *game, t_player *player)
{
	double	fraction;
	double	start_x;
	int		i;

	calcul_angle_player(&game->ray, &game->player);
	move_player(game);
	init_raycasting(game, &fraction, &start_x);
	calcul_angle_player(&game->ray, &game->player);
	if (DEBUG)
	{
		draw_square_player(player->pos_x * SIZE_SQUARE,
			player->pos_y * SIZE_SQUARE, 0x00FF00, game);
			draw_map(game);
		}
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
	calcul_angle_player(&game->ray, &game->player);
}

// void	raycasting(t_game *game, t_player *player)
// {
// 	double	fraction;
// 	double	start_x;
// 	int		i;
// 	// t_point	center_view;
// 	// t_point	left_view;
// 	// t_point	right_view;
// 	// t_point	view_fraction;

// 	// center_view.x = cos(game->player.plane);
// 	// center_view.y = sin(game->player.plane);

// 	// left_view.x = -center_view.y + center_view.x;
// 	// left_view.y = center_view.x + center_view.y;

// 	// right_view.x = center_view.y + center_view.x;
// 	// right_view.y = -center_view.x + center_view.y;

	

// 	// init_raycasting(game);
// 	game->ray.cos_p = cos(game->player.plane);
// 	game->ray.sin_p = sin(game->player.plane);
// 	move_player(game);
// 	fraction = PI / 3 / game->width;
// 	start_x = player->plane - PI / 6.0;
// 	game->ray.cos_p = cos(game->player.plane);
// 	game->ray.sin_p = sin(game->player.plane);
// 	if (DEBUG)
// 	{
// 		draw_square_player(player->pos_x * SIZE_SQUARE,
// 			player->pos_y * SIZE_SQUARE, 0x00FF00, game);
// 			draw_map(game);
// 		}
// 	i = 0;
// 	while (i < game->width)
// 	{
// 		if (DEBUG)
// 			draw_line_2d(&game->player, game, start_x, i);
// 		else
// 			draw_line(game, start_x, i);
// 		start_x += fraction;
// 		i++;
// 	}
// }
