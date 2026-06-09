/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:48:23 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/08 17:18:40 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"
#include "../includes/parsing.h"
#include "../includes/clean_exit.h"

void	draw_pixel(Game *game, int x, int y, unsigned int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	int pos_pixel = (y * game->img.size_line + x * (game->img.bits_per_pixel / 8));
	char *pixel = game->img.img_addr + pos_pixel;
	*(unsigned int *)pixel = color;
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
	int y = 0;
	int x;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel(game, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	return (OK);
}

int main(int ac, char **av)
{
	(void)av;
	(void)ac;
	Game	game;
	char *map_tab[] = {
		"    111111",
		"    100101",
		"111111N101",
		"1000001001",
		"1111111111",
		NULL
	};
	// if (ac != 2)
	// 	return (ft_putstr_fd("Error: Wrong number of args\n", 2), ERROR);
	game.map.map = map_tab;
	if (check_map(&game.map) == ERROR)
		return (ft_putstr_fd("Error: Wrong map\n", 2), ERROR);
	if (fill_struct_player(&game.player, game.map.map) == ERROR)
		return (ERROR);
	if (init_mlx(&game) == ERROR)
		return (ERROR);
	create_img(&game);
	mlx_hook(game.win, 2, 1L << 0, key, &game);
	mlx_hook(game.win, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
	return (OK);
}
