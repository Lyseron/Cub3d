/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:11:19 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/22 18:05:06 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static bool	create_all_image(t_game *game, t_texture *texture)
{
	int	i;
	int	j;

	game->img.img_ptr = mlx_new_image(game->mlx, game->width, game->height);
	if (!game->img.img_ptr)
		return (ERROR);
	texture->img[IS_NORTH].img_ptr = mlx_xpm_file_to_image(game->mlx,
		texture->path[IS_NORTH], &i, &j);
	if (!texture->img[IS_NORTH].img_ptr)
		return (ERROR);
	texture->img[IS_SOUTH].img_ptr = mlx_xpm_file_to_image(game->mlx,
		texture->path[IS_SOUTH], &i, &j);
	if (!texture->img[IS_SOUTH].img_ptr)
		return (ERROR);
	texture->img[IS_WEAST].img_ptr = mlx_xpm_file_to_image(game->mlx,
		texture->path[IS_WEAST], &i, &j);
	if (!texture->img[IS_WEAST].img_ptr)
		return (ERROR);
	texture->img[IS_EAST].img_ptr = mlx_xpm_file_to_image(game->mlx,
		texture->path[IS_EAST], &i, &j);
	if (!texture->img[IS_EAST].img_ptr)
		return (ERROR);
	return (OK);
}

int	create_initial_img(t_game *game)
{
	if (!game || !game->mlx || !game->win)
		return (ERROR);
	if (create_all_image(game, &game->map.texture))
		return (ERROR);
	game->img.img_addr = mlx_get_data_addr(game->img.img_ptr,
			&game->img.bits_per_pixel, &game->img.size_line, &game->img.endian);
	if (!game->img.img_addr)
		return (ERROR);
	return (OK);
}
