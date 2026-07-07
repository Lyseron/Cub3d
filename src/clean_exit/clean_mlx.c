/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:55:55 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/09 16:55:55 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	exit_game(t_game *game)
{
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

void	free_all_img(t_game *game)
{
	t_texture	*texture;

	texture = &game->map.texture;
	if (game->img.img_ptr)
		mlx_destroy_image(game->mlx, game->img.img_ptr);
	if (texture->img[IS_NORTH].img_ptr)
		mlx_destroy_image(game->mlx, texture->img[IS_NORTH].img_ptr);
	if (texture->img[IS_SOUTH].img_ptr)
		mlx_destroy_image(game->mlx, texture->img[IS_SOUTH].img_ptr);
	if (texture->img[IS_WEAST].img_ptr)
		mlx_destroy_image(game->mlx, texture->img[IS_WEAST].img_ptr);
	if (texture->img[IS_EAST].img_ptr)
		mlx_destroy_image(game->mlx, texture->img[IS_EAST].img_ptr);
	if (game->hand.img_ptr)
		mlx_destroy_image(game->mlx, game->hand.img_ptr);
	if (game->brush.img_ptr)
		mlx_destroy_image(game->mlx, game->brush.img_ptr);
	free_anim(&game->hand_2, game);
}
