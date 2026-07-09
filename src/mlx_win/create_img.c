/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:11:19 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/09 11:38:47 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
	if (is_valid_color(game->map.floor[0]) == false
		|| is_valid_color(game->map.floor[1]) == false
		|| is_valid_color(game->map.floor[2]) == false)
		return (ERROR);
	game->textures.convert_color_f = convert_rgb_to_int(0,
			game->map.floor[0], game->map.floor[1], game->map.floor[2]);
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
	if (game->map.door)
		if (laod_texture(game, &tex->img[IS_DOOR], DOOR_PATH) == ERROR)
			return (ERROR);
	if (!ft_strncmp(tex->path[IS_NORTH], GOOD_NORTH, 46)
		&& !ft_strncmp(tex->path[IS_SOUTH], GOOD_SOUTH, 50))
		game->good_texture = true;
	return (OK);
}

static int	init_anim(t_game *game)
{
	if (init_img_right_hand(game) == ERROR)
		return (ERROR);
	if (init_img_left_hand(game) == ERROR)
		return (ERROR);
	if (init_img_phone(game) == ERROR)
		return (ERROR);
	if (init_mona(game) == ERROR)
		return (ERROR);
	if (init_munch(game) == ERROR)
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
	if (init_anim(game) == ERROR)
		return (ERROR);
	return (OK);
}
