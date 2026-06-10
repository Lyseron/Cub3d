/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:48:41 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/09 20:56:30 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	print_data(Map *map)
{
	printf("\nPRINT TEXTURE\n");
	if (map->texture.NO)
		printf(map->texture.NO);
	if (map->texture.SO)
		printf(map->texture.SO);
	if (map->texture.WE)
		printf(map->texture.WE);
	if (map->texture.EA)
		printf(map->texture.EA);

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
}

int main(int ac, char **av)
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