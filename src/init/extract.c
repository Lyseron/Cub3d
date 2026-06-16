/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:48:48 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/16 15:29:27 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	line_not_parasite(char *line, t_map *map)
{
	int	i;

	i = 0;
	if (ft_strnstr(line, "NO", ft_strlen(line))
		|| ft_strnstr(line, "SO", ft_strlen(line))
		|| ft_strnstr(line, "WE", ft_strlen(line))
		|| ft_strnstr(line, "EA", ft_strlen(line))
		|| ft_strnstr(line, "C", ft_strlen(line))
		|| ft_strnstr(line, "F", ft_strlen(line))
		|| ft_strnstr(line, "0", ft_strlen(line))
		|| ft_strnstr(line, "1", ft_strlen(line))
		|| ft_strnstr(line, "S", ft_strlen(line))
		|| ft_strnstr(line, "E", ft_strlen(line))
		|| ft_strnstr(line, "N", ft_strlen(line))
		|| ft_strnstr(line, "W", ft_strlen(line)))
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
	// if (i != 3)
	// 	while (i < 3)
	// 		Ceiling[i] = 0;
	i = 0;
	while (Floor[i])
		i++;
	if (i >= 3)
		return (false);
	// if (i != 3)
	// 	while (i < 3)
	// 		Floor[i] = 0;
	return (true);
}

bool	verif_name_texture(t_map *map)
{
	if (ft_decide_name_texture(map->texture.no)
		|| ft_decide_name_texture(map->texture.so)
		|| ft_decide_name_texture(map->texture.we)
		|| ft_decide_name_texture(map->texture.ea))
		return (true);
	return (false);
}

bool	verif_init_value(t_map *map)
{
	int	i;

	i = 0;
	if (!map->texture.no || !map->texture.so || !map->texture.we
		|| !map->texture.ea || !map->ceiling || !map->floor
		|| map->error_doublon || verif_name_texture(map))
		return (false);
	if (good_len_color(map->ceiling, map->floor))
		return (false);
	i = 0;
	while (i < 3)
	{
		if (map->ceiling[i] < 0 || map->ceiling[i] > 255)
			return (false);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (map->floor[i] < 0 || map->floor[i] > 255)
			return (false);
		i++;
	}
	return (true);
}

static bool	all_info_grab(t_map *map)
{
	if (map->texture.no && map->texture.so && map->texture.we && map->texture.ea
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
