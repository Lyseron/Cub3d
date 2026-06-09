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

int	found_pos_player(char **map, int *x, int *y)
{
	*y = 0;
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x])
		{
			if (is_player(map[*y][*x]) == true)
				return (OK);
			(*x)++;
		}
		(*y)++;
	}
	return (ERROR);
}

int	fill_struct_player(Player *player, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (found_pos_player(map, &x, &y) == ERROR)
		return (ERROR);
	player->pos_x = (double)x;
	player->pos_y = (double)y;
	// if (found_dir_player(map, &x, &y) == ERROR)
	// 	return (ERROR);
	// player->dir_x = x;
	// player->dir_y = y;
	return (OK);
}

int	init_mlx(Game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ERROR);
	game->win = mlx_new_window(game->mlx, 20, 20, "Cub3d");
	if (!game->win)
		return (ERROR);
	return (OK);
}

int main(int ac, char **av)
{
	(void)av;
	(void)ac;
	// Map	maps;
	// Player player;
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
	// printf("%f\n", player.pos_x);
	// printf("%f\n", player.pos_y);
}
