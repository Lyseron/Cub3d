/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vignesmattheu <vignesmattheu@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:55:55 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/03 08:16:29 by vignesmatth      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	exit_game(t_game *game)
{
	(void)game;
	free_all_img(game);
	if (game->win)
	mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		// mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_data_fd(&game->map);
	exit(OK);
}
