/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:50:07 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/09 11:03:19 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	has_good_component(char **map)
{
	int	x;
	int	y;
	int	nb_of_player;

	y = 0;
	nb_of_player = 0;
	while (map[y])
	{
		x = 0;
		if (map[y][x] == '\0' && map[y + 1] != NULL)
			return (false);
		while (map[y][x])
		{
			if (is_valid_component(map[y][x]) == false)
				return (false);
			if (is_player(map[y][x]) == true)
				nb_of_player++;
			x++;
		}
		y++;
	}
	if (nb_of_player != 1)
		return (false);
	return (true);
}

bool	is_player(char c)
{
	if (c && (c == 'N' || c == 'S' || c == 'E' || c == 'W'))
		return (true);
	return (false);
}

bool	is_valid_component(char c)
{
	if (c && (c == '1' || c == '0' || c == '2'
			|| is_player(c) || ft_iswhitespace(c)))
		return (true);
	return (false);
}
