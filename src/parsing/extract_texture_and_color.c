/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrac_texture_and_color.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:05:45 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/09 14:42:26 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

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

static int	*add_color(char *line, char *find)
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

static void	add_value_or_check_doublon(char *line, Map *map, char *find, char **texture)
{

	if (*texture)
		map->error_doublon = true;
	else
		*texture = ft_strdup(add_texture(line, find));
}

void	sort_value(char *line, Map *map)
{
	if (ft_strnstr(line, "NO", ft_strlen(line)))
		add_value_or_check_doublon(line, map, "NO", &map->texture.NO);		// map->texture.NO = ft_strdup(add_texture(line, "NO"));
	if (ft_strnstr(line, "SO", ft_strlen(line)))
		add_value_or_check_doublon(line, map, "SO", &map->texture.SO);		// map->texture.SO = ft_strdup(add_texture(line, "SO"));
	if (ft_strnstr(line, "WE", ft_strlen(line)))
		add_value_or_check_doublon(line, map, "WE", &map->texture.WE);		// map->texture.WE = ft_strdup(add_texture(line, "WE"));
	if (ft_strnstr(line, "EA", ft_strlen(line)))
		add_value_or_check_doublon(line, map, "EA", &map->texture.EA);		// map->texture.EA = ft_strdup(add_texture(line, "EA"));

	if (ft_strnstr(line, "C", ft_strlen(line)))
		map->Ceiling = add_color(line, "C");
	if (ft_strnstr(line, "F", ft_strlen(line)))
		map->Floor = add_color(line, "F");
}
