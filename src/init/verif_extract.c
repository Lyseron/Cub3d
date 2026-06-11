/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_extract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:09:54 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/11 16:44:56 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

bool	line_not_parasite(char *line, t_map *map)
{
	int	i;

	i = 0;
	if (ft_strnstr(line, "NO", ft_strlen(line)) || ft_strnstr(line, "SO", ft_strlen(line))
	|| ft_strnstr(line, "WE", ft_strlen(line)) || ft_strnstr(line, "EA", ft_strlen(line))
	|| ft_strnstr(line, "C", ft_strlen(line)) || ft_strnstr(line, "F", ft_strlen(line))
	|| ft_strnstr(line, "0", ft_strlen(line)) || ft_strnstr(line, "1", ft_strlen(line))
	|| ft_strnstr(line, "S", ft_strlen(line)) || ft_strnstr(line, "E", ft_strlen(line))
	|| ft_strnstr(line, "N", ft_strlen(line)) || ft_strnstr(line, "W", ft_strlen(line)))
		return (false);
	if (line[0] != '\n' || line[0] != '\0')
	{
		while (ft_iswhitespace(line[i]))
			i++;
		if (!(!line[i]))
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
	i = 0;
	while (Floor[i])
		i++;
	if (i >= 3)
		return (false);
	return (true);
}

bool	verif_name_texture(t_map *map)
{
	if (ft_decide_name_texture(map->texture.NO)
		|| ft_decide_name_texture(map->texture.SO)
		|| ft_decide_name_texture(map->texture.WE)
		|| ft_decide_name_texture(map->texture.EA))
		return (true);
	return (false);
}

bool	verif_init_value(t_map *map)
{
	int	i;

	i = 0;
	if (!map->texture.NO || !map->texture.SO || !map->texture.WE
		|| !map->texture.EA || !map->Ceiling || !map->Floor
		|| map->error_doublon || verif_name_texture(map))
		return (false);
	if (good_len_color(map->Ceiling, map->Floor))
		return (false);
	i = 0;
	while (i < 3)
	{
		if (map->Ceiling[i] < 0 || map->Ceiling[i] > 255)
			return (false);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (map->Floor[i] < 0 || map->Floor[i] > 255)
			return (false);
		i++;
	}
	return (true);
}
