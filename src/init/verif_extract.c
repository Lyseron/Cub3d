/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_extract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:09:54 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/30 16:30:52 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

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
		|| ft_strnstr(line, "W", ft_strlen(line))
		|| ft_strnstr(line, "DOOR", ft_strlen(line)))
		return (true);
	return (false);
}

bool	line_not_parasite(char *line, t_map *map)
{
	int	i;

	i = 0;
	if (good_caractere(line))
		return (false);
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

bool	verif_name_texture(t_map *map)
{
	if (ft_decide_name_texture(map->texture.path[IS_NORTH])
		|| ft_decide_name_texture(map->texture.path[IS_SOUTH])
		|| ft_decide_name_texture(map->texture.path[IS_WEAST])
		|| ft_decide_name_texture(map->texture.path[IS_EAST]))
		return (true);
	return (false);
}

bool	verif_init_value(t_map *map)
{
	if (!map->texture.path[IS_NORTH] || !map->texture.path[IS_SOUTH]
		|| !map->texture.path[IS_WEAST] || !map->texture.path[IS_EAST]
		|| !map->ceiling || !map->floor
		|| map->error || verif_name_texture(map))
		return (false);
	return (true);
}
