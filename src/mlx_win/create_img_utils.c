/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 16:40:25 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/05 16:40:25 by lyaberge         ###   ########.fr       */
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

int	convert_rgb_to_int(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

bool	is_valid_color(int color)
{
	if (color < 0 || color > 255)
		return (false);
	return (true);
}
