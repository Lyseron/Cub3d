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

static int	draw_pixel(Game *game, int x, int y, unsigned int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (ERROR);
	if (game->img.size_line < 0 || game->img.bits_per_pixel < 0)
			return (ERROR);
	int pos_pixel = (y * game->img.size_line + x * (game->img.bits_per_pixel / 8));
	if (pos_pixel < 0)
		return (ERROR);
	char *pixel = game->img.img_addr + pos_pixel;
	if (pixel == NULL)
		return (ERROR);
	*(unsigned int *)pixel = color;
	return (OK);
}

int	write_lily(Game *game)
{
	int x = 34;
	int y = 25;
	while (y < 100)
	{
		if (draw_pixel(game, x, y, 0xFF0000) == ERROR)
			return (ERROR);
		y++;
	}
	while (x < 70)
	{
		if (draw_pixel(game, x, y, 0xFF0000) == ERROR)
			return (ERROR);
		x++;
	}
	x = 100;
	y = 60;
	while (y < 100)
	{
		if (draw_pixel(game, x, y, 0xFF0000) == ERROR)
			return (ERROR);
		y++;
	}
	x = 130;
	y = 25;
	while (y < 100)
	{
		if (draw_pixel(game, x, y, 0xFF0000) == ERROR)
			return (ERROR);
		y++;
	}
	x = 160;
	y = 60;
	while (y < 100)
	{
		if (draw_pixel(game, x, y, 0xFF0000) == ERROR)
			return (ERROR);
		y++;
	}
	while (x < 200)
	{
		if (draw_pixel(game, x, y, 0xFF0000) == ERROR)
			return (ERROR);
		x++;
	}
	y = 60;
	while (y < 200)
	{
		if (draw_pixel(game, x, y, 0xFF0000) == ERROR)
			return (ERROR);
		y++;
	}
	x = 200;
	while (x > 100)
	{
		if (draw_pixel(game, x, y, 0xFF0000) == ERROR)
			return (ERROR);
		x--;
	}
	return (OK);
}

int	create_img(Game *game)
{
	game->img.img_ptr = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img.img_ptr)
		return (ERROR);
	game->img.img_addr= mlx_get_data_addr(game->img.img_ptr,
		&game->img.bits_per_pixel, &game->img.size_line, &game->img.endian);
	if (!game->img.img_addr)
		return (ERROR);
	if (write_lily(game) == ERROR)
		return (ERROR);
	
	// int y = 0;
	// int x;
	// while (y < HEIGHT)
	// {
	// 	x = 0;
	// 	while (x < WIDTH)
	// 	{
	// 		if (draw_pixel(game, x, y, 0xFF0000) == ERROR)
	// 			return (ERROR);
	// 		x++;
	// 	}
	// 	y++;
	// }
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	return (OK);
}
