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

#include "../includes/cube.h"
#include "../includes/parsing.h"

int	draw_pixel(Game *game, int x, int y, unsigned int color)
{
	int		pos_pixel;
	char	*pixel;

	if (!game || !game->img.img_addr)
		return (ERROR);
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (ERROR);
	if (game->img.size_line <= 0 || game->img.bits_per_pixel <= 0)
		return (ERROR);
	pos_pixel = (y * game->img.size_line + x * (game->img.bits_per_pixel / 8));
	if (pos_pixel < 0)
		return (ERROR);
	pixel = game->img.img_addr + pos_pixel;
	if (pixel == NULL)
		return (ERROR);
	*(unsigned int *)pixel = color;
	return (OK);
}

int	create_img(Game *game)
{
	if (!game || !game->mlx || !game->win)
		return (ERROR);
	game->img.img_ptr = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img.img_ptr)
		return (ERROR);
	game->img.img_addr = mlx_get_data_addr(game->img.img_ptr,
			&game->img.bits_per_pixel, &game->img.size_line, &game->img.endian);
	if (!game->img.img_addr)
		return (ERROR);
	if (draw_tiny_map(game) == ERROR)
		return (ERROR);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	return (OK);
}
