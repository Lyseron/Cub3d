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

void	fill_map(Game *game, char **map_tab)
{
	int	y;
	int	i;

	y = 0;
	i = 0;
	game->map.grid = malloc(sizeof(char *) * (ft_dba_len(map_tab) + 1));
	if (!game->map.grid)
		return ;
	while (map_tab[y])
	{
		game->map.grid[i] = ft_strdup(map_tab[y]);
		i++;
		y++;
	}
	game->map.grid[i] = NULL;
}

int	parsing(Game *game, char **av, int ac)
{
	char	*map_tab[] = {
		"    111111",
		"    100001",
		"111110N001",
		"1000000001",
		"1111111111",
		NULL
	};

	fill_map(game, map_tab);
	if (!game->map.grid)
		return (ERROR);
	if (ft_decide(av[1]) == ERROR)
		return (ft_putstr_fd("Error: Wrong map extension\n", 2), ERROR);
	if (check_map(&game->map) == ERROR)
		return (ft_putstr_fd("Error: Wrong map\n", 2), ERROR);
	if (fill_struct_player(&game->player, game->map.grid) == ERROR)
		return (ERROR);
	if (init_mlx(game) == ERROR)
		return (ERROR);
	return (OK);
}

int	main(int ac, char **av)
{
	Game	game;

	if (ac != 2)
		return (ft_putstr_fd("Error: Wrong number of args\n", 2), ERROR);
	ft_memset(&game, 0, sizeof(game));
	if (parsing(&game, av, ac) == ERROR)
		return (ERROR);
	create_img(&game);
	mlx_hook(game.win, 2, 1L << 0, key, &game);
	mlx_hook(game.win, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
	return (OK);
}
