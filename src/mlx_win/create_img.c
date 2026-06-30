/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:11:19 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/30 16:30:13 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	laod_texture(t_game *game, t_img *tex, char *path)
{
	if (!path)
		return (ERROR);
	tex->img_ptr = mlx_xpm_file_to_image(game->mlx, path, &tex->width,
			&tex->height);
	if (!tex->img_ptr)
	{
		printf("Erreur : Impossible de charger la texture : %s\n", path);
		return (ERROR);
	}
	tex->img_addr = mlx_get_data_addr(tex->img_ptr, &tex->bits_per_pixel,
			&tex->size_line, &tex->endian);
	if (!tex->img_addr)
		return (ERROR);
	return (OK);
}

int	create_initial_img(t_game *game)
{
	t_texture	*tex;

	if (!game || !game->mlx || !game->win)
		return (ERROR);
	tex = &game->map.texture;
	game->img.img_ptr = mlx_new_image(game->mlx, game->width, game->height);
	if (!game->img.img_ptr)
		return (ERROR);
	game->img.img_addr = mlx_get_data_addr(game->img.img_ptr,
			&game->img.bits_per_pixel, &game->img.size_line, &game->img.endian);
	if (!game->img.img_addr)
		return (ERROR);
	if (laod_texture(game, &tex->img[IS_NORTH], tex->path[IS_NORTH]) == ERROR)
		return (ERROR);
	if (laod_texture(game, &tex->img[IS_SOUTH], tex->path[IS_SOUTH]) == ERROR)
		return (ERROR);
	if (laod_texture(game, &tex->img[IS_WEAST], tex->path[IS_WEAST]) == ERROR)
		return (ERROR);
	if (laod_texture(game, &tex->img[IS_EAST], tex->path[IS_EAST]) == ERROR)
		return (ERROR);
	if (laod_texture(game, &tex->img[IS_DOOR], tex->path[IS_DOOR]) == ERROR)
		return (ERROR);
	return (OK);
}
