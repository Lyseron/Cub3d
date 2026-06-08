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

char	*return_value(char *line, char *find)
{

}

void	sort_value(char *line, Map *map)
{
	char *value = ft_strnstr(line, "NO", ft_strlen(line));
	if (value_check() == OK)
		
	map->texture.SO = return_value(line, "SO");

	value = ft_strnstr(line, "NO", ft_strlen(line));
	if (value)
		return ;
	value = ft_strnstr(line, "SO", ft_strlen(line));

}

bool extract_data(char *map_name, Map *map)
{
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error open map", 2), ERROR);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		sort_value(line, map);
	}
	if (verif_init_value(map) == false)
		return (false);
	return (true);
}

int main(int ac, char **av)
{
	// if (ac != 2)
	// 	return (print_error("Wrong number of args", 2))
	Map	maps;
	ft_memset(&maps, 0, sizeof(Map));
	extract_data(av[1], &maps);
}
