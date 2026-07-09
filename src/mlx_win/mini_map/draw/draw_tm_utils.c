/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tm_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 19:30:00 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/09 11:02:59 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// convert the coordonate of x into windows coordonne in pixel
// from the center of the player
int	convert_x_to_pixel(t_game *game, double x)
{
	return (game->tiny_map.player_center_x
		+ (x - game->player.pos_x) * SIZE_SQUARE);
}

int	convert_y_to_pixel(t_game *game, double y)
{
	return (game->tiny_map.player_center_y
		+ (y - game->player.pos_y) * SIZE_SQUARE);
}

bool	is_ray_stay_in_bound(t_game *game, double ray_pos_x, double ray_pos_y)
{
	if (ray_pos_y < 0 || ray_pos_y >= game->map.map_y)
		return (false);
	if (ray_pos_x < 0)
		return (false);
	if (!game->map.grid[(int)ray_pos_y])
		return (false);
	if (ray_pos_x >= ft_strlen(game->map.grid[(int)ray_pos_y]))
		return (false);
	if (game->map.grid[(int)ray_pos_y][(int)ray_pos_x] == '1')
		return (false);
	if (game->map.grid[(int)ray_pos_y][(int)ray_pos_x] == '2')
		return (false);
	if (game->map.grid[(int)ray_pos_y][(int)ray_pos_x] == ' ')
		return (false);
	return (true);
}

bool	is_ray_pixel_in_bound(t_game *game, int ray_pixel_x, int ray_pixel_y)
{
	if (ray_pixel_x < game->tiny_map.min_x)
		return (false);
	if (ray_pixel_x >= game->tiny_map.max_x)
		return (false);
	if (ray_pixel_y < game->tiny_map.min_y)
		return (false);
	if (ray_pixel_y >= game->tiny_map.max_y)
		return (false);
	return (true);
}

int	draw_frame(t_game *game)
{
	int	x;
	int	y;

	y = game->tiny_map.min_y - FRAME_SIZE;
	while (y < game->tiny_map.max_y + FRAME_SIZE)
	{
		x = game->tiny_map.min_x - FRAME_SIZE;
		while (x < game->tiny_map.max_x + FRAME_SIZE)
		{
			if (draw_pixel(game, x, y, COLOR_FRAME) == ERROR)
				return (ERROR);
			x++;
		}
		y++;
	}
	return (OK);
}
