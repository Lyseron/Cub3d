/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:15:59 by mvignes           #+#    #+#             */
/*   Updated: 2026/07/09 12:01:01 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/// @brief Calcul the vector player for localisation
/// @param ray 
/// @param player 
static void	calcul_angle_player(t_ray *ray, t_player *player)
{
	ray->cos_p = cos(player->angle);
	ray->sin_p = sin(player->angle);
}

/// @brief Initializes data for while raycasting
/// @param game 
/// @param fraction 
/// @param start_x 
static void	init_raycasting(t_game *game, double *fraction, double *start_x)
{
	*fraction = PI / 3 / game->width;
	*start_x = game->player.angle - PI / 6.0;
	calcul_angle_player(&game->ray, &game->player);
}

/// @brief while raycasting, the radius scanning
/// @param game 
/// @param player 
/// @return define OK
int	raycasting(t_game *game, t_player *player)
{
	double	fraction;
	double	start_x;
	int		i;

	init_raycasting(game, &fraction, &start_x);
	calcul_angle_player(&game->ray, player);
	i = 0;
	while (i < game->width)
	{
		draw_line(game, start_x, i);
		start_x += fraction;
		i++;
	}
	calcul_angle_player(&game->ray, player);
	return (OK);
}
