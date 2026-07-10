/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:48:05 by mvignes           #+#    #+#             */
/*   Updated: 2026/07/10 17:10:41 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/// @brief Check the data int line for extract map
/// @param map 
/// @param line 
/// @return Return it's for good
static bool	good_value_map(t_map *map, char *line)
{
	if (!line)
		return (false);
	if (ft_strnstr(line, "2", ft_strlen(line)))
		map->door = true;
	if (!ft_strnstr(line, "NO", !ft_strlen(line))
		|| !ft_strnstr(line, "SO", !ft_strlen(line))
		|| !ft_strnstr(line, "WE", !ft_strlen(line))
		|| !ft_strnstr(line, "EA", !ft_strlen(line))
		|| !ft_strnstr(line, "C", !ft_strlen(line))
		|| !ft_strnstr(line, "F", !ft_strlen(line)))
	{
		if (ft_strnstr(line, "0", ft_strlen(line))
			|| ft_strnstr(line, "1", ft_strlen(line))
			|| ft_strnstr(line, "S", ft_strlen(line))
			|| ft_strnstr(line, "E", ft_strlen(line))
			|| ft_strnstr(line, "N", ft_strlen(line))
			|| ft_strnstr(line, "W", ft_strlen(line)))
			return (true);
	}
	return (false);
}

/// @brief Calcul the dimenssion of the map for malloc the char **
/// @param map 
/// @return Return 0 for it's good
static bool	get_dimenssion(t_map *map)
{
	int		i;
	t_list	*tmp;
	char	*tmp_char;

	tmp = map->extract;
	while (tmp && !good_value_map(map, tmp->content))
		tmp = tmp->next;
	if (!tmp)
		return (ERROR);
	while (tmp)
	{
		if (!good_value_map(map, tmp->content))
			break ;
		i = 0;
		tmp_char = tmp->content;
		while (tmp_char[i])
			i++;
		if (i > map->map_x)
			map->map_x = i;
		tmp = tmp->next;
		map->map_y++;
	}
	return (OK);
}

/// @brief Allow the memory in heap which one char **grid
/// @param map 
/// @return 
int	allow_memory_grid(t_map *map)
{
	int	i;

	map->grid = malloc(sizeof(char *) * (map->map_y + 1));
	if (!map->grid)
		return (ERROR);
	i = 0;
	while (i < map->map_y)
	{
		map->grid[i] = malloc(sizeof(char) * (map->map_x + 1));
		if (!map->grid[i])
			return (ft_free_before_i(map->grid, i), ERROR);
		i++;
	}
	return (OK);
}

/// @brief Write the data for the map extract of fd
/// @param map 
void	write_map(t_map *map)
{
	int		i;
	int		j;
	t_list	*tmp;
	char	*tmp_char;

	tmp = map->extract;
	while (!good_value_map(map, tmp->content))
		tmp = tmp->next;
	i = 0;
	while (tmp)
	{
		if (!good_value_map(map, tmp->content))
			break ;
		tmp_char = tmp->content;
		j = 0;
		while (tmp_char[j])
		{
			map->grid[i][j] = tmp_char[j];
			j++;
		}
		map->grid[i][j] = '\0';
		tmp = tmp->next;
		i++;
	}
	map->grid[i] = NULL;
}

/// @brief Function master for extract the map of fd
/// @param line 
/// @param map 
/// @return Return 0 for it's good
bool	extract_map(char *line, t_map *map)
{
	if (read_map(line, map))
	{
		get_next_line(-1);
		return (ft_putendl_fd("Error donblon data", 2), ERROR);
	}
	if (get_dimenssion(map))
		return (ft_putendl_fd("void map in fd", 2), ERROR);
	if (allow_memory_grid(map) == ERROR)
		return (ft_putendl_fd("Malloc fail", 2), ERROR);
	write_map(map);
	return (OK);
}
