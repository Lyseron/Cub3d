/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:48:48 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/10 18:21:13 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

bool	line_not_parasite(char *line, Map *map)
{
	int	i = 0;

	if (ft_strnstr(line, "NO", ft_strlen(line)) || ft_strnstr(line, "SO", ft_strlen(line))
	|| ft_strnstr(line, "WE", ft_strlen(line)) || ft_strnstr(line, "EA", ft_strlen(line))
	|| ft_strnstr(line, "C", ft_strlen(line)) || ft_strnstr(line, "F", ft_strlen(line))
	|| ft_strnstr(line, "0", ft_strlen(line)) || ft_strnstr(line, "1", ft_strlen(line))
	|| ft_strnstr(line, "S", ft_strlen(line)) || ft_strnstr(line, "E", ft_strlen(line))
	|| ft_strnstr(line, "N", ft_strlen(line)) || ft_strnstr(line, "W", ft_strlen(line)))
	{
		while (ft_iswhitespace(line[i]))
			i++;
		if (line[i] == '\0')
		{
			map->error_doublon = true;
			return (true);
		}
	}
	return (false);
}

bool	good_len_color(int *Ceiling, int *Floor)
{
	int	i;
	
	i = 0;
	while (Ceiling[i] != -1)
		i++;
	if (i >= 3)
		return (false);
	if (i != 3)
		while (i < 3)
			Ceiling[i] = 0;
	i = 0;
	while (Floor[i])
		i++;
	if (i >= 3)
		return (false);
	if (i != 3)
		while (i < 3)
			Floor[i] = 0;
	return (true);
}

bool	verif_init_value(Map *map)
{
	int	i;

	i = 0;
	if (!map->texture.NO || !map->texture.SO || !map->texture.WE || !map->texture.EA
		|| !map->Ceiling || !map->Floor || map->error_doublon)
		return (false);
	// printf("map->Ceiling, map->Floor = %i, %i\n", map->Ceiling[1], map->Floor[1]);
	// if (map->Ceiling[3] != -1 || map->Floor[3] != -1)
	if (good_len_color(map->Ceiling, map->Floor))
		return (false);
	i = 0;
	while (i < 3)
	{
		if (map->Ceiling[i] < 0 || map->Ceiling[i] > 255)
			return (false);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (map->Floor[i] < 0 || map->Floor[i] > 255)
			return (false);
		i++;
	}
	return (true);
}

static bool	all_info_grab(Map *map)
{
	if (map->texture.NO && map->texture.SO && map->texture.WE && map->texture.EA
		&& map->Ceiling && map->Floor)
	{
		// free(line);
		return (true);
	}
	// else if (ft_strnstr(line, "0", ft_strlen(line)) || ft_strnstr(line, "1", ft_strlen(line))
	// 		|| ft_strnstr(line, "S", ft_strlen(line)) || ft_strnstr(line, "E", ft_strlen(line))
	// 		|| ft_strnstr(line, "N", ft_strlen(line)) || ft_strnstr(line, "W", ft_strlen(line)))
	// 			return (true);
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
		if (!line/* || line_not_parasite(line, map)*/)
			break;
		if (sort_value(line, map))
		{
			free(line);
			get_next_line(-1);
			return (print_error("Error: Value not correct", map, ERROR));
		}
		free(line);
		if (all_info_grab(map))
			break;
	}
	if (verif_init_value(map) == false)
		return (free(line), line = NULL, print_error("Error: Value not correct", map, ERROR));
	if (extract_map(line, map))
		return (print_error("in fd", map, ERROR), ERROR);
	return (false);
}
