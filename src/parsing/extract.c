/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:48:48 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/09 14:54:42 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static bool	verif_init_value(Map *map)
{
	if (!map->texture.NO || !map->texture.SO || !map->texture.WE || !map->texture.EA
		|| !map->Ceiling || !map->Floor || map->error_doublon)
		return (false);
	if (map->Ceiling[3] || map->Floor[3])
		return (false);
	for (int i = 0; map->Ceiling[i]; i++)
		if (map->Ceiling[i] < 0 || map->Ceiling[i] > 255)
			return (false);
	for (int i = 0; map->Floor[i]; i++)
		if (map->Floor[i] < 0 || map->Floor[i] > 255)
			return (false);
	return (true);
}

static bool	all_info_grab(Map *map)
{
	if (map->texture.NO && map->texture.SO && map->texture.WE && map->texture.EA
		&& map->Ceiling && map->Floor)
		return (true);
	return (false);
}

bool extract_data(char *map_name, Map *map)
{
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error open map", 2), ERROR);
	while (1)
	{
		line = get_next_line(fd);
		if (!line || all_info_grab(map))
			break;
		sort_value(line, map);
	}
	if (verif_init_value(map) == false)
	{
		printf("verif dit c'est pas bon\n");
		return (false);
	}

	return (true);
}
