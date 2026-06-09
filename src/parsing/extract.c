/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:48:48 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/09 20:00:20 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static bool	verif_init_value(Map *map)
{
	int	i;

	i = 0;
	if (!map->texture.NO || !map->texture.SO || !map->texture.WE || !map->texture.EA
		|| !map->Ceiling || !map->Floor || map->error_doublon)
		return (false);
	if (map->Ceiling[3] || map->Floor[3])
		return (false);
	i = 0;
	while (map->Ceiling[i])
	{
		if (map->Ceiling[i] < 0 || map->Ceiling[i] > 255)
			return (false);
		i++;
	}
	i = 0;
	while (map->Floor[i])
	{
		if (map->Floor[i] < 0 || map->Floor[i] > 255)
			return (false);
		i++;
	}
	return (true);
}

static bool	all_info_grab(char *line, Map *map)
{
	if (map->texture.NO && map->texture.SO && map->texture.WE && map->texture.EA
		&& map->Ceiling && map->Floor)
	{
		free(line);
		return (true);
	}
	return (false);
}

bool extract_data(Map *map)
{
	char	*line;

	map->map_fd = open(map->map_name, O_RDONLY);
	if (map->map_fd == -1)
		return (print_error("Error: Error open map", map, ERROR));
	while (1)
	{
		line = get_next_line(map->map_fd);
		if (!line || all_info_grab(line, map))
			break;
		sort_value(line, map);
		free(line);
	}
	extract_map(line, map);
	if (verif_init_value(map) == false)
		print_error("Error: Value not correct", map, ERROR);
	return (false);
}
