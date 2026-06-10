/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:41:09 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/10 20:12:27 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

// static bool	good_data_color(char *line)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (ft_iswhitespace(line[i]))
// 		i++;
// 	if (line[i] == 'F' || line[i] == 'C')
// 		i++;
// 	while (ft_iswhitespace(line[i]))
// 		i++;
// 	while (line[i])
// 	{
// 		while (ft_isdigit(line[i]))
// 			i++;
// 		if (line[i++] == ',' && ft_isdigit(line[i]))
// 		{
// 			while (ft_isdigit(line[i]))
// 				i++;
// 			j++;
// 		}
// 		else
// 			return (false);
// 	}
// 	if (j == 2)
// 		return (true);
// 	return (false);
// }

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
	if (count && count < 10)
		return (true);
	return (false);
}

static int	*add_color(char *line, char *find, Map *map)
{
	char	**tab_char;
	int		*tab_int;
	int		i;
	char	*value;

	value = ft_strnstr(line, find, ft_strlen(line));
	value = &value[1];
	tab_char = ft_split(value, ',');
	i = 0;
	if (ft_dba_len(tab_char) != 3)
		return (ft_free_dba(tab_char), print_error("Error: number rgb not good", map, ERROR), NULL);
	tab_int = malloc(sizeof(int) * (ft_dba_len(tab_char) + 1));
	if (!tab_int)
		return (print_error("Error...", NULL, ERROR), NULL);
	while (tab_char[i])
	{
		if (check_digit(tab_char[i]))
			tab_int[i] = ft_atoi(tab_char[i]);
		else
			return (ft_free_dba(tab_char), free(tab_int), print_error("Error: number rgb not good", map, ERROR), NULL);
		i++;
	}
	tab_int[i] = -1;
	ft_free_dba(tab_char);
	return (tab_int);
}

// static bool	add_var_color(char *line, Map *map, char *find, int **color)
// {
// 	if (*color)
// 	{
// 		// printf("color[0] = %i\n", *color[0]);
// 		map->error_doublon = true;
// 		return (ERROR);
// 	}
// 	else
// 	{
// 		*color = add_color(line, find, map);
// 		if (map->error_doublon)
// 			return (ERROR);
// 	}
// 	return (OK);
// }

int	sort_color(char *line, Map *map)
{
	if (ft_strnstr(line, "C", ft_strlen(line)))
		// if (add_var_color(line, map, "C", &map->Ceiling))
		// 	return (ERROR);
	{
		if (map->extract_ceiling)
		{
			printf("PROUBLEME DETECTER\n\n");
			map->error_doublon = true;
			return (ERROR);
		}
		else
		{
			// if (!good_data_color(line))
			// 	return (ERROR);
			map->extract_ceiling = true;
			printf("extract ceiling = %i\n", map->extract_ceiling);
			map->Ceiling = add_color(line, "C", map);
			if (map->error_doublon)
				return (ERROR);
		}
	}
	if (ft_strnstr(line, "F", ft_strlen(line)))
		// if (add_var_color(line, map, "F", &map->Floor))
		// 	return (ERROR);
	{
		if (map->extract_floor)
		{
			map->error_doublon = true;
			return (ERROR);
		}
		else
		{
			// if (!good_data_color(line))
			// 	return (ERROR);
			map->extract_floor = true;
			map->Floor = add_color(line, "F", map);
			if (map->error_doublon)
				return (ERROR);
		}
	}
	return (OK);
}
