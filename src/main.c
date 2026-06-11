/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:48:41 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/11 17:46:35 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// void	print_data(t_map *map)
// {
// 	printf("\nPRINT TEXTURE\n");
// 	if (map->texture.NO)
// 		printf("%s\n", map->texture.NO);
// 	if (map->texture.SO)
// 		printf("%s\n", map->texture.SO);
// 	if (map->texture.WE)
// 		printf("%s\n", map->texture.WE);
// 	if (map->texture.EA)
// 		printf("%s\n", map->texture.EA);

// 	printf("\nPRINT COLOR\n");
// 	if (map->Floor)
// 		for (int i = 0; i < 3;i++)
// 			printf("floor i = %i\n", map->Floor[i]);
// 	if (map->Ceiling)
// 		for (int i = 0; i < 3;i++)
// 			printf("Ceiling i = %i\n", map->Ceiling[i]);
	
// 	printf("\nPRINT MAP\n");
// 	for (int i = 0; i < map->map_y;i++)
// 	{
// 		for (int j = 0; j < map->map_x; j++)
// 			printf("%c", map->grid[i][j]);
// 	}
// }

int	parsing(t_game *game, char **av)
{
	game->map.map_name = av[1];
	if (ft_decide(game->map.map_name) == ERROR)
		return (ft_putstr_fd("Error: Wrong map extension\n", 2), ERROR);
	if (extract_data(&game->map))
		return (1);
	// print_data(&game->map);
	// free_data_fd(&maps);
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
	t_game	game;

	if (ac != 2)
		return (ft_putstr_fd("Error: Wrong number of args\n", 2), ERROR);
	ft_memset(&game, 0, sizeof(game));
	if (parsing(&game, av) == ERROR)
		return (ERROR);
	// print_data(&game.map);	// <------------- Penser a retirer cest juste pour print le parscing etre sur que tout est bon
	create_img(&game);
	mlx_hook(game.win, 2, 1L << 0, ((mlx_func_t)(uintptr_t)key), &game);
	mlx_hook(game.win, 17, 0, ((mlx_func_t)(uintptr_t)exit_game), &game);
	mlx_loop(game.mlx);
	return (OK);
}
