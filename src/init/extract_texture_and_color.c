/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texture_and_color.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:05:45 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/22 13:23:35 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static bool	good_value_not_map(char *line, t_map *map)
{
	if (!map->texture.no || !map->texture.so
		|| !map->texture.we || !map->texture.ea
		|| !map->ceiling || !map->floor || map->error_doublon)
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
		map->error_doublon = true;
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

int	sort_value(char *line, t_map *map)
{
	if (ft_strnstr(line, "NO", ft_strlen(line)))
		add_value_or_check_doublon(line, map, "NO", &map->texture.no);
	if (ft_strnstr(line, "SO", ft_strlen(line)))
		add_value_or_check_doublon(line, map, "SO", &map->texture.so);
	if (ft_strnstr(line, "WE", ft_strlen(line)))
		add_value_or_check_doublon(line, map, "WE", &map->texture.we);
	if (ft_strnstr(line, "EA", ft_strlen(line)))
		add_value_or_check_doublon(line, map, "EA", &map->texture.ea);
	if (ft_strnstr(line, "C", ft_strlen(line))
		|| ft_strnstr(line, "F", ft_strlen(line)))
		if (sort_color(line, map))
			return (ERROR);
	if (good_value_not_map(line, map))
		return (map->error_doublon = true, ERROR);
	return (OK);
}
