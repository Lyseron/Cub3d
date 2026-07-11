/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_extract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:09:54 by mvignes           #+#    #+#             */
/*   Updated: 2026/07/11 08:52:13 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/// @brief check on the line if there are any explicitly good characters
/// @param line 
/// @return return true for it's ok
static bool	good_caractere(char *line)
{
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
		return (true);
	return (false);
}

/// @brief Check if the line of contents does not contain
/// @brief any parasitic containers
/// @param line 
/// @param map 
/// @return return false for it's ok and return true for error
bool	line_not_parasite(char *line, t_map *map, bool finish)
{
	int	i;

	i = 0;
	if (finish == false)
	{
		if (good_caractere(line))
			return (false);
	}
	if (line[0] != '\n' || line[0] != '\0')
	{
		while (ft_iswhitespace(line[i]))
			i++;
		if (!(!line[i]))
		{
			map->error = true;
			return (true);
		}
	}
	return (false);
}

/// @brief check all code color for ceiling and floor
/// @param Ceiling 
/// @param Floor 
/// @return return true for it's ok and return false for error
bool	good_len_color(int *Ceiling, int *Floor)
{
	int	i;

	i = 0;
	while (Ceiling[i] != -1)
		i++;
	if (i >= 3)
		return (false);
	i = 0;
	while (Floor[i])
		i++;
	if (i >= 3)
		return (false);
	return (true);
}

/// @brief check that each texture name ends up with . xpm
/// @param map 
/// @return return true for it's ok and return false for error
bool	verif_name_texture(t_map *map)
{
	if (ft_decide_name_texture(map->texture.path[IS_NORTH])
		&& ft_decide_name_texture(map->texture.path[IS_SOUTH])
		&& ft_decide_name_texture(map->texture.path[IS_WEAST])
		&& ft_decide_name_texture(map->texture.path[IS_EAST]))
		return (true);
	return (false);
}

/// @brief Simple function to check everything that came out of the file. cub
/// @param map 
/// @return return true for it's ok and return false for error
bool	verif_init_value(t_map *map)
{
	int	i;

	i = 0;
	if (!map->texture.path[IS_NORTH] || !map->texture.path[IS_SOUTH]
		|| !map->texture.path[IS_WEAST] || !map->texture.path[IS_EAST]
		|| !map->extract_ceiling || !map->extract_floor
		|| map->error || verif_name_texture(map))
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
