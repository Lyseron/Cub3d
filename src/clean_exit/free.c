/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:23:50 by mvignes           #+#    #+#             */
/*   Updated: 2026/07/11 08:54:56 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/// @brief Allows you to write a message and to quit
/// @brief the program properly as soon as the parsing is done
/// @param str 
/// @param map 
/// @param r 
/// @return Code exit
int	print_error(char *str, t_map *map, int r)
{
	map->error = true;
	ft_putendl_fd(str, 2);
	free_data_fd(map);
	return (r);
}

/// @brief Free string and free static char * in get_next_line
/// @param line 
void	free_line_and_gnl(char *line)
{
	free(line);
	line = NULL;
	get_next_line(-1);
}

/// @brief Free void data and assign NULL value
/// @param data 
void	free_and_null(void **data)
{
	free(*data);
	*data = NULL;
}

/// @brief Free all image use for animation
/// @param anim 
/// @param game 
void	free_anim(t_anim *anim, t_game *game)
{
	int	i;

	i = 0;
	while (i < anim->nb_of_img)
	{
		if (anim->anim_img[i].img_ptr && game->mlx)
			mlx_destroy_image(game->mlx, anim->anim_img[i].img_ptr);
		i++;
	}
}

/// @brief Free all data allows for parsing
/// @param map 
void	free_data_fd(t_map *map)
{
	if (map->map_fd >= 0)
	{
		close(map->map_fd);
		map->map_fd = -1;
	}
	if (map->texture.path[IS_NORTH])
		free_and_null((void *)&map->texture.path[IS_NORTH]);
	if (map->texture.path[IS_SOUTH])
		free_and_null((void *)&map->texture.path[IS_SOUTH]);
	if (map->texture.path[IS_WEAST])
		free_and_null((void *)&map->texture.path[IS_WEAST]);
	if (map->texture.path[IS_EAST])
		free_and_null((void *)&map->texture.path[IS_EAST]);
	if (map->floor)
		free_and_null((void *)&map->floor);
	if (map->ceiling)
		free_and_null((void *)&map->ceiling);
	if (map->extract)
		ft_lstclear(&(map->extract), free);
	if (map->grid)
		ft_free_dba(map->grid);
}
