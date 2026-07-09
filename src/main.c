/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:48:41 by mvignes           #+#    #+#             */
/*   Updated: 2026/07/09 11:27:40 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_putstr_fd("Error: Wrong number of args\n", 2), ERROR);
	ft_memset(&game, 0, sizeof(game));
	if (parsing(&game, av) == ERROR)
		return (exit_game(&game), ERROR);
	if (init_img(&game) == ERROR)
		return (exit_game(&game), ERROR);
	init_key(&game);
	game.start_anim_wall = false;
	if (display_check(&game) == ERROR)
		return (exit_game(&game), ERROR);
	mlx_hook(game.win, 2, 1L << 0, ((t_mlx_func)(uintptr_t)keywee), &game);
	mlx_hook(game.win, 3, 1L << 1, ((t_mlx_func)(uintptr_t)keyno), &game);
	mlx_hook(game.win, 17, 0, ((t_mlx_func)(uintptr_t)exit_game), &game);
	mlx_loop_hook(game.mlx, ((t_mlx_func)(uintptr_t)game_loop), &game);
	mlx_loop(game.mlx);
	return (OK);
}
