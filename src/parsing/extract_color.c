/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:41:09 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/10 17:07:16 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"


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
		tab_int[i] = ft_atoi(tab_char[i]);
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
			map->extract_floor = true;
			map->Floor = add_color(line, "F", map);
			if (map->error_doublon)
				return (ERROR);
		}
	}
	return (OK);
}
