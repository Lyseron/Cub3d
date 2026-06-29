/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:41:09 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/29 14:33:12 by mvignes          ###   ########.fr       */
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
		if (ft_isdigit(str[i]))
			count++;
		else if (!ft_iswhitespace(str[i]) && str[i] != ',')
			return (false);
		i++;
	}
	i = atoi(str);
	if (i < 0 || i > 255)
		return (false);
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
		map->error = true;
		ft_free_dba(tab_char);
		return (NULL);
	}
	return (tab_char);
}

static int	add_color(char *line, char *find, t_map *map)
{
	char	**tab_char;
	int		color;
	int		i;

	tab_char = split_color(line, find, map);
	if (!tab_char)
		return (print_error("Error: number rgb not good", map, ERROR));
	i = 0;
	color = 0;
	while (tab_char[i])
	{
		if (check_digit(tab_char[i]))
			color += ft_atoi(tab_char[i]) << ( (2 - i) * 8);
		else
			return (ft_free_dba(tab_char),
				print_error("Error: number rgb not good", map, ERROR));
		i++;
	}
	ft_free_dba(tab_char);
	return (color);
}

static bool	add_var_color(char *line, t_map *map, char *find, int *color)
{
	if (*color)
	{
		map->error = true;
		return (ERROR);
	}
	else
	{
		*color = add_color(line, find, map);
		if (map->error)
			return (ERROR);
			printf("color = %d\n", *color);
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
