/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 00:41:42 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/11 08:59:50 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	draw_left_img(t_game *game, t_img *img)
{
	int	x;
	int	y;
	int	pixel_y;
	int	pixel_x;
	int	color_pixel;

	pixel_x = 90;
	pixel_y = game->height - img->height;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			color_pixel = get_pixel_from_texture(img, x, y);
			if (color_pixel != 0xffffff)
				put_pixel(game, pixel_x + x, pixel_y + y, color_pixel);
			x++;
		}
		y++;
	}
	return (OK);
}

int	draw_right_img(t_game *game, t_img *img)
{
	int	x;
	int	y;
	int	pixel_y;
	int	pixel_x;
	int	color_pixel;

	pixel_x = game->width - img->width - 90;
	pixel_y = game->height - img->height;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			color_pixel = get_pixel_from_texture(img, x, y);
			if (color_pixel != 0xffffff)
				put_pixel(game, pixel_x + x, pixel_y + y, color_pixel);
			x++;
		}
		y++;
	}
	return (OK);
}

int	draw_middle_img(t_game *game, t_img *img)
{
	int	x;
	int	y;
	int	pixel_y;
	int	pixel_x;
	int	color_pixel;

	pixel_x = (game->width - img->width) / 2;
	pixel_y = game->height - img->height;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			color_pixel = get_pixel_from_texture(img, x, y);
			if (color_pixel != 0xffffff)
				put_pixel(game, pixel_x + x, pixel_y + y, color_pixel);
			x++;
		}
		y++;
	}
	return (OK);
}
