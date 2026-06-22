/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:23:50 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/21 17:19:40 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	print_error(char *str, t_map *map, int r)
{
	map->error_doublon = true;
	ft_putendl_fd(str, 2);
	free_data_fd(map);
	return (r);
}

void	free_line_and_gnl(char *line)
{
	free(line);
	line = NULL;
	get_next_line(-1);
}

void	free_and_null(void **data)
{
	free(*data);
	*data = NULL;
}

void	free_all_img(t_game *game)
{
	if (game->img.img_ptr)
		mlx_destroy_image(game->mlx, game->img.img_ptr);
	if (game->map.texture.img_no)
		mlx_destroy_image(game->mlx, game->map.texture.img_no);
	if (game->map.texture.img_so)
		mlx_destroy_image(game->mlx, game->map.texture.img_no);
	if (game->map.texture.img_we)
		mlx_destroy_image(game->mlx, game->map.texture.img_no);
	if (game->map.texture.img_ea)
		mlx_destroy_image(game->mlx, game->map.texture.img_no);
}

void	free_data_fd(t_map *map)
{
	if (map->map_fd)
		close(map->map_fd);
	if (map->texture.no)
		free_and_null((void *)&map->texture.no);
	if (map->texture.so)
		free_and_null((void *)&map->texture.so);
	if (map->texture.we)
		free_and_null((void *)&map->texture.we);
	if (map->texture.ea)
		free_and_null((void *)&map->texture.ea);
	if (map->floor)
		free_and_null((void *)&map->floor);
	if (map->ceiling)
		free_and_null((void *)&map->ceiling);
	if (map->extract)
		ft_lstclear(&(map->extract), free);
	if (map->grid)
		ft_free_dba(map->grid);
}
