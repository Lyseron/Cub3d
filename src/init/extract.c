/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:48:48 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/22 16:30:57 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static bool	all_info_grab(t_map *map)
{
	if (map->texture.path[IS_NORTH] && map->texture.path[IS_SOUTH]
		&& map->texture.path[IS_WEAST] && map->texture.path[IS_EAST]
		&& map->ceiling && map->floor)
		return (true);
	return (false);
}

bool	extract_data(t_map *map)
{
	char	*line;

	map->map_fd = open(map->map_name, O_RDONLY);
	if (map->map_fd == -1)
		return (print_error("Error: Error open map", map, ERROR));
	while (1)
	{
		line = get_next_line(map->map_fd);
		if (!line)
			break;
		if (sort_value(line, map) || line_not_parasite(line, map))
			return (free_line_and_gnl(line),
				print_error("Error: Value not correct", map, ERROR));
		free(line);
		if (all_info_grab(map))
			break ;
	}
	if (verif_init_value(map) == false)
		return (get_next_line(-1),
			print_error("Value not correct", map, ERROR));
	if (extract_map(line, map))
		return (print_error(NULL, map, ERROR), ERROR);
	return (false);
}
