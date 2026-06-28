/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vignesmattheu <vignesmattheu@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:54:57 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/23 15:55:21 by vignesmatth      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ERROR);
	game->width = 1200;
	game->height = 900;
	//if (mlx_get_screen_size(game->mlx, &game->width, &game->height))
	//	return (ERROR);
	game->win = mlx_new_window(game->mlx, game->width, game->height, "Cub3d");
	if (!game->win)
		return (ERROR);
	return (OK);
}
