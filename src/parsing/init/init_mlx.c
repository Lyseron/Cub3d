/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:54:57 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/11 08:49:44 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ERROR);
	game->width = 1400;
	game->height = 800;
	game->win = mlx_new_window(game->mlx, game->width, game->height, "Cub3d");
	if (!game->win)
		return (ERROR);
	return (OK);
}

void	init_key(t_game *game)
{
	game->bool_key.a = false;
	game->bool_key.w = false;
	game->bool_key.s = false;
	game->bool_key.d = false;
	game->bool_key.left = false;
	game->bool_key.right = false;
	game->bool_key.change_map = false;
	game->bool_key.change_hand = false;
}
