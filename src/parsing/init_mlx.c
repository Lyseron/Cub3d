/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:54:57 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/11 14:34:32 by mvignes          ###   ########.fr       */
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

int	key(int key_choice, void *arg)
{
	const Game	*game = arg;
	
	if (key_choice == 53 || key_choice == 65307)
	{
		exit(OK);
		return (OK);
	}
	return (OK);
}
