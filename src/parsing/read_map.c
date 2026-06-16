/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:47:20 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/11 16:44:58 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	check_no_double_data(char *line, t_map *map)
{
	if (!line || ft_strnstr(line, "NO", ft_strlen(line))
		|| ft_strnstr(line, "SO", ft_strlen(line))
		|| ft_strnstr(line, "WE", ft_strlen(line))
		|| ft_strnstr(line, "EA", ft_strlen(line))
		|| ft_strnstr(line, "C", ft_strlen(line))
		|| ft_strnstr(line, "F", ft_strlen(line)))
	{
		map->error_doublon = true;
		// free(line);
		return (true);
	}
	return (false);
}

int	read_map(char *line, t_map *map)
{
	t_list	*new;

	while (1 || map->error_doublon)
	{
		line = get_next_line(map->map_fd);
		if (!line || !line[0] || check_no_double_data(line, map)
			|| line_not_parasite(line, map))
			break ;
		new = ft_lstnew(line);
		if (!new)
			return (print_error("Error: Error open map", map, ERROR));
		ft_lstadd_back(&(map->extract), new);
	}
	close(map->map_fd);
	if (map->error_doublon)
		return (free(line), print_error("Error: Data doublon in fd",
				map, ERROR));
	return (OK);
}
