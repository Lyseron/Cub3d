/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:54:57 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/28 15:59:03 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ERROR);
	// game->width = 1200;
	// game->height = 900;
	mlx_get_screen_size(game->mlx, &game->width, &game->height);
	game->win = mlx_new_window(game->mlx, game->width, game->height, "Cub3d");
	if (!game->win)
		return (ERROR);
	return (OK);
}
