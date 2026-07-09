/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:35:41 by mvignes           #+#    #+#             */
/*   Updated: 2026/07/09 11:39:19 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_draw_3d(t_game *game, t_ray *ray)
{
	ray->line_height = game->height / ray->dist_perp;
	ray->start_y = (game->height / 2) - (ray->line_height / 2);
	ray->end = (game->height / 2) + (ray->line_height / 2);
	if (ray->start_y < 0)
		ray->start_y = 0;
	if (ray->end >= game->height)
		ray->end = game->height - 1;
	ray->pos_tex_x = calcul_pos_texture(game, ray, ray->tex_projet->width);
	ray->step = 1.0 * ray->tex_projet->height / ray->line_height;
	ray->pos_tex = (ray->start_y - game->height
			/ 2.0 + ray->line_height / 2.0) * ray->step;
}

void	draw_3d(t_game *game, t_ray *ray, int y, int i)
{
	int		couleur;
	t_img	*img;

	img = ray->tex_projet;
	if (y < ray->start_y)
		put_pixel(game, i, y, game->textures.convert_color_c);
	else if (y >= ray->start_y && y <= ray->end)
	{
		if (ray->pos_tex < 0)
			ray->pos_tex = 0;
		ray->pos_tex_y = (int)ray->pos_tex & (img->height - 1);
		ray->pos_tex += ray->step;
		couleur = get_pixel_from_texture(img, ray->pos_tex_x, ray->pos_tex_y);
		put_pixel(game, i, y, couleur);
	}
	else
		put_pixel(game, i, y, game->textures.convert_color_f);
}

void	select_texture(t_game *game, t_ray *ray)
{
	if (ray->touch == 2)
		ray->tex_projet = &game->map.texture.img[IS_DOOR];
	else if (ray->wall_touch == 1)
	{
		if (game->start_anim_wall == true)
			ray->tex_projet = &game->munch.anim_img[game->munch.frame_id];
		else
			ray->tex_projet = &game->map.texture.img[IS_NORTH];
	}
	else if (ray->wall_touch == 2)
	{
		if (game->start_anim_wall == true)
			ray->tex_projet = &game->mona.anim_img[game->mona.frame_id];
		else
			ray->tex_projet = &game->map.texture.img[IS_SOUTH];
	}
	else if (ray->wall_touch == 3)
		ray->tex_projet = &game->map.texture.img[IS_WEAST];
	else if (ray->wall_touch == 4)
		ray->tex_projet = &game->map.texture.img[IS_EAST];
}

void	draw_line(t_game *game, double angle_rayon, int i)
{
	int		y;
	t_ray	*ray;

	y = 0;
	ray = &game->ray;
	init_dda(game, ray, angle_rayon);
	calcul_direct_wall(&game->player, ray);
	calcul_horizontal_intersection(game, ray);
	calcul_dist(game, &game->ray, angle_rayon);
	search_cote_wall(game, ray);
	select_texture(game, &game->ray);
	init_draw_3d(game, &game->ray);
	while (y < game->height)
	{
		draw_3d(game, ray, y, i);
		y++;
	}
}
