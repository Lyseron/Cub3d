/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:55:55 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/09 11:45:03 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/// @brief properly exits the program
/// @param game 
/// @return returns nothing, he use exit fonction
int	exit_game(t_game *game)
{
	free_all_img(game);
	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		// #ifdef LINUX
		if (game->mlx)
			mlx_destroy_display(game->mlx);
		free(game->mlx);
		// #endif
	}
	free_data_fd(&game->map);
	exit(OK);
}

/// @brief Free all mlx image
/// @param game 
void	free_all_img(t_game *game)
{
	t_texture	*texture;

	texture = &game->map.texture;
	if (game->img.img_ptr && game->mlx)
		mlx_destroy_image(game->mlx, game->img.img_ptr);
	if (texture->img[IS_NORTH].img_ptr && game->mlx)
		mlx_destroy_image(game->mlx, texture->img[IS_NORTH].img_ptr);
	if (texture->img[IS_SOUTH].img_ptr && game->mlx)
		mlx_destroy_image(game->mlx, texture->img[IS_SOUTH].img_ptr);
	if (texture->img[IS_WEAST].img_ptr && game->mlx)
		mlx_destroy_image(game->mlx, texture->img[IS_WEAST].img_ptr);
	if (texture->img[IS_EAST].img_ptr && game->mlx)
		mlx_destroy_image(game->mlx, texture->img[IS_EAST].img_ptr);
	if (texture->img[IS_DOOR].img_ptr && game->mlx)
		mlx_destroy_image(game->mlx, texture->img[IS_DOOR].img_ptr);
	free_anim(&game->left_hand, game);
	free_anim(&game->right_hand, game);
	free_anim(&game->phone, game);
	free_anim(&game->munch, game);
	free_anim(&game->mona, game);
}
