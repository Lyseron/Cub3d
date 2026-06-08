/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:48:23 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/08 17:18:40 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	*extract_value(char *line, char *to_find)
{
	char	*extract_line;
	char	*value;

	extract_line = ft_strtrim(line, to_find);
	value = ft_strtrim(extract_line, " ");
	// free(extract_line);
	return (value);
}

char	*sort_value(char *line, char *to_find)
{
	char 	*complete_line;
	char	*value;

	complete_line = ft_strnstr(line, to_find, ft_strlen(line));
	value = extract_value(complete_line, to_find);
	return (value);
}

bool extract_data(char *map_name, Map *map)
{
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error open map\n", 2), ERROR);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		map->texture.NO = sort_value(line, "NO");
		printf("%s", map->texture.NO);
		// map->texture.EA = sort_value(line, "EA");
		// map->texture.SO = sort_value(line, "SO");
		// map->texture.WE = sort_value(line, "WE");
	}
	// if (verif_init_value(map) == false)
		// return (false);
	return (true);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (ft_putstr_fd("Wrong number of args\n", 2), ERROR);
	Map	maps;
	// ft_memset(&maps, 0, sizeof(Map));
	extract_data(av[1], &maps);
	printf("%s", maps.texture.EA);
}
