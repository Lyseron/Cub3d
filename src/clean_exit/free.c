/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:23:50 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/11 13:33:21 by mvignes          ###   ########.fr       */
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

void	free_data_fd(t_map *map)
{
	if (map->map_fd)
		close(map->map_fd);
	if (map->texture.NO)
		free_and_null((void *)&map->texture.NO);
	if (map->texture.SO)
		free_and_null((void *)&map->texture.SO);
	if (map->texture.WE)
		free_and_null((void *)&map->texture.WE);
	if (map->texture.EA)
		free_and_null((void *)&map->texture.EA);
	if (map->Floor)
		free_and_null((void *)&map->Floor);
	if (map->Ceiling)
		free_and_null((void *)&map->Ceiling);
	if (map->extract)
		ft_lstclear(&(map->extract), free);
	// if (map->grid)
	// 	ft_free_dba(map->grid);
}
