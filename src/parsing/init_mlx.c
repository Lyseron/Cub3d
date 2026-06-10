/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:54:57 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/09 16:54:57 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	init_mlx(Game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ERROR);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3d");
	if (!game->win)
		return (ERROR);
	return (OK);
}

int	key(int key_choice, Game *game)
{
	(void)game;
	if (key_choice == 53 || key_choice == 65307)
	{
		exit(OK);
		return (OK);
	}
	return (OK);
}
