/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:54:57 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/30 15:49:45 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ERROR);
	// game->width = 1080;
	// game->height = 1080;
	mlx_get_screen_size(game->mlx, &game->width, &game->height);
	game->win = mlx_new_window(game->mlx, game->width, game->height, "Cub3d");
	if (!game->win)
		return (ERROR);
	return (OK);
}
