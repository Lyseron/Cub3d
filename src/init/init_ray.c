/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 09:14:55 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/17 18:27:32 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_ray(t_game *game)
{
	game->ray.ray_pos_x = game->player.pos_x;
	game->ray.ray_pos_y = game->player.pos_y;
	game->ray.plane_x = -game->player.dir_y * cos(game->ray.plane_x);
	game->ray.plane_y = game->player.dir_x * cos(game->ray.plane_y);
}
