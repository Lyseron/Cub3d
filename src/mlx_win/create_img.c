/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:11:19 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/09 17:11:19 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	laod_texture(t_game *game, t_img *tex, char *path)
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

static int	convert_rgb_to_int(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static bool	is_valid_color(int color)
{
	if (color < 0 || color > 255)
		return (false);
	return (true);
}

int	init_color_c_and_f(t_game *game)
{
	if (!game->map.ceiling || !game->map.floor)
		return (ERROR);
	if (is_valid_color(game->map.ceiling[0]) == false
		|| is_valid_color(game->map.ceiling[1]) == false
		|| is_valid_color(game->map.ceiling[2]) == false)
		return (ERROR);
	game->textures.convert_color_c = convert_rgb_to_int(0,
			game->map.ceiling[0], game->map.ceiling[1], game->map.ceiling[2]);
	if (!game->textures.convert_color_c)
		return (ERROR);
	if (is_valid_color(game->map.floor[0]) == false
		|| is_valid_color(game->map.floor[1]) == false
		|| is_valid_color(game->map.floor[2]) == false)
		return (ERROR);
	game->textures.convert_color_f = convert_rgb_to_int(0,
			game->map.floor[0], game->map.floor[1], game->map.floor[2]);
	if (!game->textures.convert_color_f)
		return (ERROR);
	return (OK);
}

int	init_img_wall(t_game *game, t_texture *tex)
{
	if (laod_texture(game, &tex->img[IS_NORTH], tex->path[IS_NORTH]) == ERROR)
		return (ERROR);
	if (laod_texture(game, &tex->img[IS_SOUTH], tex->path[IS_SOUTH]) == ERROR)
		return (ERROR);
	if (laod_texture(game, &tex->img[IS_WEAST], tex->path[IS_WEAST]) == ERROR)
		return (ERROR);
	if (laod_texture(game, &tex->img[IS_EAST], tex->path[IS_EAST]) == ERROR)
		return (ERROR);
	return (OK);
}

int	init_img(t_game *game)
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
	if (init_img_wall(game, tex) == ERROR)
		return (ERROR);
	if (init_color_c_and_f(game) == ERROR)
		return (ERROR);
	if (init_img_hand(game) == ERROR)
		return (ERROR);
	if (init_img_hand2(game) == ERROR)
		return (ERROR);
	// if (init_img_door(game) == ERROR)
	// 	return (ERROR);
	return (OK);
}
