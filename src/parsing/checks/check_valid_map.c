/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:47:59 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/09 11:08:09 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static bool	is_invalid_next_case(char **map, int x, int y)
{
	if (!map)
		return (true);
	if (x < 0 || y < 0)
		return (true);
	if (map[y] == NULL)
		return (true);
	if (map[y][x] == '\0')
		return (true);
	if (map[y][x] == ' ')
		return (true);
	if (map[y][x] == '\n')
		return (true);
	return (false);
}

static bool	has_invalid_next_pos(char **map, int x, int y, char player_to_test)
{
	if (map && map[y][x] == player_to_test)
	{
		if (is_invalid_next_case(map, x + 1, y))
			return (true);
		if (is_invalid_next_case(map, x - 1, y))
			return (true);
		if (is_invalid_next_case(map, x, y + 1))
			return (true);
		if (is_invalid_next_case(map, x, y - 1))
			return (true);
	}
	return (false);
}

static bool	condition_is_valid_map(char **map, int x, int y)
{
	if (has_invalid_next_pos(map, x, y, 'N'))
		return (false);
	if (has_invalid_next_pos(map, x, y, 'E'))
		return (false);
	if (has_invalid_next_pos(map, x, y, 'W'))
		return (false);
	if (has_invalid_next_pos(map, x, y, 'S'))
		return (false);
	if (has_invalid_next_pos(map, x, y, '0'))
		return (false);
	if (has_invalid_next_pos(map, x, y, '2'))
		return (false);
	return (true);
}

static bool	is_valid_map(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (condition_is_valid_map(map, x, y) == false)
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

int	check_map(t_map *maps)
{
	if (maps->grid == NULL)
		return (ft_putstr_fd("Error: No map\n", 2), ERROR);
	if (has_good_component(maps->grid) == false)
		return (ft_putstr_fd("Error: Wrong map component\n", 2), ERROR);
	if (is_valid_map(maps->grid) == false)
		return (ft_putstr_fd("Error: Wrong map\n", 2), ERROR);
	return (OK);
}
