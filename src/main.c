/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:48:41 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/11 14:39:11 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	fill_map(t_game *game, char **map_tab)
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

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_putstr_fd("Error: Wrong number of args\n", 2), ERROR);
	ft_memset(&game, 0, sizeof(game));
	if (parsing(&game, av) == ERROR)
		return (free_data_fd(&game.map), ERROR);
	init_img(&game);
	init_key(&game);
	if (display(&game) == ERROR)
		return (ERROR);
	mlx_hook(game.win, 2, 1L << 0, ((mlx_func_t)(uintptr_t)keywee), &game);
	mlx_hook(game.win, 3, 1L << 1, ((mlx_func_t)(uintptr_t)keyno), &game);
	mlx_hook(game.win, 17, 0, ((mlx_func_t)(uintptr_t)exit_game), &game);
	mlx_loop_hook(game.mlx, ((mlx_func_t)(uintptr_t)game_loop), &game);
	mlx_loop(game.mlx);
	return (OK);
}
