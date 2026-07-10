/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:02:20 by mvignes           #+#    #+#             */
/*   Updated: 2026/07/10 14:47:06 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	get_pixel_from_texture(t_img *tex, int tex_x, int tex_y)
{
	int	*pixels;

	if (!tex || !tex->img_addr)
		return (0x000000);
	if (tex_x < 0 || tex_x >= tex->width || tex_y < 0 || tex_y >= tex->height)
		return (0x000000);
	pixels = (int *)tex->img_addr;
	return (pixels[tex_y * (tex->size_line / 4) + tex_x]);
}

void	direction_wall_for_add_texture(t_game *game, t_ray *ray,
	double *dist_raw, double *wall_x)
{
	if (ray->wall_touch == 3 || ray->wall_touch == 4)
	{
		*dist_raw = (ray->map_x - game->player.pos_x
				+ (1.0 - ray->step_x) / 2.0) / ray->cos_p;
		*wall_x = game->player.pos_y + *dist_raw * ray->sin_p;
	}
	else
	{
		*dist_raw = (ray->map_y - game->player.pos_y
				+ (1.0 - ray->step_y) / 2.0) / ray->sin_p;
		*wall_x = game->player.pos_x + *dist_raw * ray->cos_p;
	}
}

/// @brief calculating the pixel in relation to the size of the wall
/// @param game 
/// @param ray 
/// @param tex_width 
/// @return return the pos of the pixel
int	calcul_pos_texture(t_game *game, t_ray *ray, int tex_width)
{
	double	wall_x;
	double	dist_raw;
	int		tex_x;

	wall_x = 0;
	dist_raw = 0;
	tex_x = 0;
	direction_wall_for_add_texture(game, ray, &dist_raw, &wall_x);
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex_width);
	if ((ray->wall_touch == 3 || ray->wall_touch == 4) && ray->cos_p < 0)
		tex_x = tex_width - tex_x - 1;
	if ((ray->wall_touch == 1 || ray->wall_touch == 2) && ray->sin_p > 0)
		tex_x = tex_width - tex_x - 1;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex_width)
		tex_x = tex_width - 1;
	return (tex_x);
}
