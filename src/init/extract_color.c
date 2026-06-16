/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:41:09 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/11 14:53:42 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static bool	check_digit(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i++]))
			count++;
	}
	if (count && count < 4)
		return (true);
	return (false);
}

static char	**split_color(char *line, char *find, t_map *map)
{
	char	**tab_char;
	char	*value;

	value = ft_strnstr(line, find, ft_strlen(line));
	value = &value[1];
	tab_char = ft_split(value, ',');
	if (ft_dba_len(tab_char) != 3)
	{
		map->error_doublon = true;
		ft_free_dba(tab_char);
		return (NULL);
	}
	return (tab_char);
}

static int	*add_color(char *line, char *find, t_map *map)
{
	char	**tab_char;
	int		*tab_int;
	int		i;

	tab_char = split_color(line, find, map);
	if (!tab_char)
		return (print_error("Error: number rgb not good", map, ERROR), NULL);
	tab_int = malloc(sizeof(int) * (ft_dba_len(tab_char) + 1));
	if (!tab_int)
		return (print_error("Error...", map, ERROR), NULL);
	i = 0;
	while (tab_char[i])
	{
		if (check_digit(tab_char[i]))
			tab_int[i] = ft_atoi(tab_char[i]);
		else
			return (free(tab_int),
				print_error("Error: number rgb not good", map, ERROR), NULL);
		i++;
	}
	tab_int[i] = -1;
	ft_free_dba(tab_char);
	return (tab_int);
}

static bool	add_var_color(char *line, t_map *map, char *find, int **color)
{
	if (*color)
	{
		map->error_doublon = true;
		return (ERROR);
	}
	else
	{
		*color = add_color(line, find, map);
		if (map->error_doublon)
			return (ERROR);
	}
	return (OK);
}

int	sort_color(char *line, t_map *map)
{
	if (ft_strnstr(line, "C", ft_strlen(line)))
		if (add_var_color(line, map, "C", &map->ceiling))
			return (ERROR);
	if (ft_strnstr(line, "F", ft_strlen(line)))
		if (add_var_color(line, map, "F", &map->floor))
			return (ERROR);
	return (OK);
}
