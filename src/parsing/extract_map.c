/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:48:05 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/09 19:47:54 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static bool	good_value_map(char *line)
{
	if (!line)
		return (false);
	if (!ft_strnstr(line, "NO", !ft_strlen(line)) || !ft_strnstr(line, "SO", !ft_strlen(line))
		|| !ft_strnstr(line, "WE", !ft_strlen(line)) || !ft_strnstr(line, "EA", !ft_strlen(line))
		|| !ft_strnstr(line, "C", !ft_strlen(line)) || !ft_strnstr(line, "F", !ft_strlen(line)))
	{
		if (ft_strnstr(line, "0", ft_strlen(line)) || ft_strnstr(line, "1", ft_strlen(line))
			|| ft_strnstr(line, "S", ft_strlen(line)) || ft_strnstr(line, "E", ft_strlen(line))
			|| ft_strnstr(line, "N", ft_strlen(line)) || ft_strnstr(line, "W", ft_strlen(line)))
				return (true);
	}
	return (false);
}

void	get_dimenssion(Map *map)
{
	int		i;
	t_list	*tmp;
	char	*tmp_char;

	tmp = map->extract;
	while (!good_value_map(tmp->content))
		tmp = tmp->next;
	while (tmp)
	{
		if (!good_value_map(tmp->content))
			break;
		i = 0;
		tmp_char = tmp->content;
		while (tmp_char[i])
			i++;
		if (i > map->map_x)
			map->map_x = i;
		tmp = tmp->next;
		map->map_y++;
	}
}

void	allow_memory_grid(Map *map)
{
	int	i;

	map->grid = malloc(sizeof(char *) * (map->map_y + 1));
	i = 0;
	while (i < map->map_y)
	{
		map->grid[i] = malloc(sizeof(char) * (map->map_x + 1));
		i++;
	}
}

void	write_map(Map *map)
{
	int		i;
	int		j;
	t_list	*tmp;
	char	*tmp_char;

	tmp = map->extract;
	while (!good_value_map(tmp->content))
		tmp = tmp->next;
	i = 0;
	while (tmp)
	{
		if (!good_value_map(tmp->content))
			break;
		tmp_char = tmp->content;
		j = 0;
		while (tmp_char[j])
		{
			map->grid[i][j] = tmp_char[j];
			j++;
		}
		i++;
		tmp = tmp->next;
	}
	map->grid[i] = NULL;
}

bool	extract_map(char *line, Map *map)
{
	if (read_map(line, map))
		return (print_error("Error donblon data", map, ERROR));
	map->map_fd = open(map->map_name, O_RDONLY);
	if (map->map_fd == -1)
		return (print_error("Error open map", map, ERROR));
	get_dimenssion(map);
	allow_memory_grid(map);
	write_map(map);
	return (OK);
}
