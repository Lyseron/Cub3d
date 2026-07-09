/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texture_and_color.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:05:45 by mvignes           #+#    #+#             */
/*   Updated: 2026/07/09 15:32:06 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/// @brief Check if we have all the necessary data before the extraction from
/// @brief the map and if there are any characters in the map
/// @param line 
/// @param map 
/// @return Return true for it's ok
static bool	good_value_not_map(char *line, t_map *map)
{
	if (!map->texture.path[IS_NORTH] || !map->texture.path[IS_SOUTH]
		|| !map->texture.path[IS_WEAST] || !map->texture.path[IS_EAST]
		|| !map->ceiling || !map->floor || map->error)
	{
		if (ft_strnstr(line, "01", ft_strlen(line))
			|| ft_strnstr(line, "11", ft_strlen(line))
			||ft_strnstr(line, "00", ft_strlen(line))
			|| ft_strnstr(line, "10", ft_strlen(line))
			|| ft_strnstr(line, "S1", ft_strlen(line))
			|| ft_strnstr(line, "E1", ft_strlen(line))
			|| ft_strnstr(line, "N1", ft_strlen(line))
			|| ft_strnstr(line, "W1", ft_strlen(line))
			|| ft_strnstr(line, "S0", ft_strlen(line))
			|| ft_strnstr(line, "E0", ft_strlen(line))
			|| ft_strnstr(line, "N0", ft_strlen(line))
			|| ft_strnstr(line, "W0", ft_strlen(line)))
			return (true);
	}
	return (false);
}

static char	*add_texture(char *line, char *find)
{
	char	*value;
	int		i;

	value = ft_strnstr(line, find, ft_strlen(line));
	i = 2;
	while (ft_iswhitespace(line[i]))
		i++;
	return (&value[i]);
}

static int	add_value_or_check_doublon(char *line, t_map *map,
	char *find, char **texture)
{
	char	*tmp;

	if (*texture)
		map->error = true;
	else
	{
		tmp = ft_strdup(add_texture(line, find));
		if (!tmp)
			return (print_error("Error: Malloc *texture for add_texture crash",
					map, ERROR));
		*texture = ft_strtrim(tmp, " 	\n");
		if (!*texture)
			return (print_error("Error: Malloc *texture for add_texture crash",
					map, ERROR));
		free(tmp);
	}
	return (0);
}

/// @brief check if there are any characters to extract the textures or colors
/// @param line 
/// @param map 
/// @return return 1 for error
int	sort_value(char *line, t_map *map)
{
	t_texture	*text;

	text = &map->texture;
	if (ft_strnstr(line, "NO", ft_strlen(line)))
		add_value_or_check_doublon(line, map, "NO", &text->path[IS_NORTH]);
	if (ft_strnstr(line, "SO", ft_strlen(line)))
		add_value_or_check_doublon(line, map, "SO", &text->path[IS_SOUTH]);
	if (ft_strnstr(line, "WE", ft_strlen(line)))
		add_value_or_check_doublon(line, map, "WE", &text->path[IS_WEAST]);
	if (ft_strnstr(line, "EA", ft_strlen(line)))
		add_value_or_check_doublon(line, map, "EA", &text->path[IS_EAST]);
	if (ft_strnstr(line, "C", ft_strlen(line))
		|| ft_strnstr(line, "F", ft_strlen(line)))
		if (sort_color(line, map))
			return (ERROR);
	if (good_value_not_map(line, map))
		return (map->error = true, ERROR);
	return (OK);
}
