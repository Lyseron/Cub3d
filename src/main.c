/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:48:41 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/10 21:53:20 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	print_data(Map *map)
{
	printf("\nPRINT TEXTURE\n");
	if (map->texture.NO)
		printf("%s\n", map->texture.NO);
	if (map->texture.SO)
		printf("%s\n", map->texture.SO);
	if (map->texture.WE)
		printf("%s\n", map->texture.WE);
	if (map->texture.EA)
		printf("%s\n", map->texture.EA);

	printf("\nPRINT COLOR\n");
	if (map->Floor)
		for (int i = 0; i < 3;i++)
			printf("floor i = %i\n", map->Floor[i]);
	if (map->Ceiling)
		for (int i = 0; i < 3;i++)
			printf("Ceiling i = %i\n", map->Ceiling[i]);
	
	printf("\nPRINT MAP\n");
	for (int i = 0; i < map->map_y;i++)
	{
		for (int j = 0; j < map->map_x; j++)
			printf("%c", map->grid[i][j]);
	}
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
	(void)ac;
	// if (ac != 2)
	// 	return (print_error("Wrong number of args", NULL, 2));
	Map	maps;
	ft_memset(&maps, 0, sizeof(Map));
	// Cub	cub;
	// ft_memset(&cub, 0, sizeof(Cub));
	// cub.map = &map;
	maps.map_name = av[1];
	if (extract_data(&maps))
		return (1);
	print_data(&maps);
	free_data_fd(&maps);
}
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
