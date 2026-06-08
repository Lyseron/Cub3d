/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:48:23 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/08 19:36:55 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	verif_init_value(Map *map)
{
	if (!map->texture.NO || !map->texture.SO || !map->texture.WE || !map->texture.EA
		|| !map->Ceiling || !map->Floor)
		return (false);
	if (map->Ceiling[3] || map->Floor[3])
		return (false);
	for (int i = 0; map->Ceiling[i]; i++)
		if (map->Ceiling[i] < 0 || map->Ceiling[i] > 255)
			return (false);
	for (int i = 0; map->Floor[i]; i++)
		if (map->Floor[i] < 0 || map->Floor[i] > 255)
			return (false);
	return (true);
}

char	*add_texture(char *line, char *find)
{
	char	*value;
	int		i;

	value = ft_strnstr(line, find, ft_strlen(line));
	i = 2;
	while (ft_iswhitespace(line[i]))
		i++;
	return (&value[i]);
}

int	*add_color(char *line, char *find)
{
	char	**tab_char;
	int		*tab_int;
	int		i;
	char	*value;

	value = ft_strnstr(line, find, ft_strlen(line));
	value = &value[1];
	tab_char = ft_split(value, ',');
	i = 0;
	tab_int = malloc (sizeof(int) * ft_dba_len(tab_char));
	while (tab_char[i])
	{
		tab_int[i] = ft_atoi(tab_char[i]);
		i++;
	}
	return (tab_int);
}

// void	check_doublon(char *line, Map *map)
// {
// 	// remplacer le code du dessous
// 	{
// 		if (map->texture.NO)
// 			map->error_doublon = true;
// 		else
// 			map->texture.NO = ft_strdup(add_texture(line, "NO"));
// 	}
// }

void	sort_value(char *line, Map *map)
{
	if (ft_strnstr(line, "NO", ft_strlen(line)))
		map->texture.NO = ft_strdup(add_texture(line, "NO"));
	if (ft_strnstr(line, "SO", ft_strlen(line)))
		map->texture.SO = ft_strdup(add_texture(line, "SO"));
	if (ft_strnstr(line, "WE", ft_strlen(line)))
		map->texture.WE = ft_strdup(add_texture(line, "WE"));
	if (ft_strnstr(line, "EA", ft_strlen(line)))
		map->texture.EA = ft_strdup(add_texture(line, "EA"));

	if (ft_strnstr(line, "C", ft_strlen(line)))
		map->Ceiling = add_color(line, "C");
	if (ft_strnstr(line, "F", ft_strlen(line)))
		map->Floor = add_color(line, "F");
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
	{
		printf("verif dit c'est pas bon\n");
		return (false);
	}

	
	printf("\nPRINT TEXTURE\n");
	if (map->texture.NO)
		printf(map->texture.NO);
	if (map->texture.SO)
		printf(map->texture.SO);
	if (map->texture.WE)
		printf(map->texture.WE);
	if (map->texture.EA)
		printf(map->texture.EA);

	printf("\nPRINT COLOR\n");
	if (map->Floor)
		for (int i = 0; map->Floor[i];i++)
			printf("floor i = %i\n", map->Floor[i]);
	if (map->Ceiling)
		for (int i = 0; map->Ceiling[i];i++)
			printf("Ceiling i = %i\n", map->Ceiling[i]);
	return (true);
}

int main(int ac, char **av)
{
	(void)ac;
	// if (ac != 2)
	// 	return (print_error("Wrong number of args", 2))
	Map	maps;
	ft_memset(&maps, 0, sizeof(Map));
	// Cub	cub;
	// ft_memset(&cub, 0, sizeof(Cub));
	// cub.map = &map;
	extract_data(av[1], &maps);
}
