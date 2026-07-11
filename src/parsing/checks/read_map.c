/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:47:20 by mvignes           #+#    #+#             */
/*   Updated: 2026/07/11 08:54:00 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/// @brief Check is no double in fd
/// @param line 
/// @param map 
/// @return Return true for double in fd (error)
bool	check_no_double_data(char *line, t_map *map)
{
	if (!line || ft_strnstr(line, "NO", ft_strlen(line))
		|| ft_strnstr(line, "SO", ft_strlen(line))
		|| ft_strnstr(line, "WE", ft_strlen(line))
		|| ft_strnstr(line, "EA", ft_strlen(line))
		|| ft_strnstr(line, "C", ft_strlen(line))
		|| ft_strnstr(line, "F", ft_strlen(line)))
	{
		map->error = true;
		return (true);
	}
	return (false);
}

bool	data_after_map(t_map *map, char *line)
{
	while (1 || map->error)
	{
		line = get_next_line(map->map_fd);
		if (!line || !line[0])
			break ;
		if (line_not_parasite(line, map, true))
		{
			free_line_and_gnl(line);
			return (true);
		}
		free(line);
	}
	return (false);
}

/// @brief Function master for read map in fd
/// @param line 
/// @param map 
/// @return Return 0 for it's good
int	read_map(char *line, t_map *map)
{
	t_list	*new;

	while (1 || map->error)
	{
		line = get_next_line(map->map_fd);
		if (!line || !line[0] || check_no_double_data(line, map)
			|| line_not_parasite(line, map, false)
			|| (line[0] == '\n' && map->extract_map))
			break ;
		if (ft_strnstr(line, "1", ft_strlen(line))
			|| ft_strnstr(line, "1", ft_strlen(line)))
			map->extract_map = true;
		new = ft_lstnew(line);
		if (!new)
			return (print_error("Error: Error open map", map, ERROR));
		ft_lstadd_back(&(map->extract), new);
	}
	if (data_after_map(map, line))
		map->error = true;
	close(map->map_fd);
	if (map->error)
		return (free(line), print_error("Error: Data doublon in fd",
				map, ERROR));
	return (OK);
}
