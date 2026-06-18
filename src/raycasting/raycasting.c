/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:15:59 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/18 17:58:24 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


// void	init_info_calcul_position(double *player_pos, double *delta_dist, int *map_pos, int *step)
// {}

// void	calcul_position_wall(t_game *game, double *side, double *ray_dir, bool is_x)
// {
// 	double	*player_pos;
// 	double	*delta_dist;
// 	int		*map_pos;
// 	int		*step;
// 	if (is_x)
// 		init_info_calcul_position(&game->player.pos_x, &game->ray.delta_dist_x,
// 			&game->ray.map_x, &game->ray.step_x);
// 	else
// 		init_info_calcul_position(&game->player.pos_y, &game->ray.delta_dist_y,
// 			&game->ray.map_y, &game->ray.step_y);
// 	if (*ray_dir < 0)
// 	{
// 		*step = -1;
// 		*side = (*player_pos - *map_pos) * *delta_dist;
// 	}
// 	else
// 	{
// 		game->ray.step_x = 1;
// 		*side = (*player_pos + 1.0 - *map_pos) * *delta_dist;
// 	}
// }

// void	calcul_horizontal_intersection(t_game *game)
// {
// 	game->ray.map_x = (int)game->player.pos_x;
// 	game->ray.map_y = (int)game->player.pos_y;
// 	game->ray.delta_dist_x = fabs(1 / game->ray.ray_dir_x);
// 	game->ray.delta_dist_y = fabs(1 / game->ray.ray_dir_y);
// 	// calcul_position_wall(game, );
// 	// calcul_position_wall();
	
// }


void	raycasting(t_game *game)
{
	double	cos_p = cos(game->player.plane);
	double	sin_p = sin(game->player.plane);
	// (void)cos_p;
	// (void)sin_p;
	
	if (game->bool_key.w || game->bool_key.a || game->bool_key.s || game->bool_key.d
	|| game->bool_key.left || game->bool_key.right)
		moov_player(game, cos_p, sin_p);
	// while ()
	// {
		
	// 	calcul_horizontal_intersection(game);
	// }
	
}
