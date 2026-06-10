/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:53:12 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/09 16:53:12 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"
#include "../includes/parsing.h"

static int	found_pos_player(char **map, int *x, int *y)
{
	*y = 0;
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x])
		{
			if (is_player(map[*y][*x]) == true)
				return (OK);
			(*x)++;
		}
		(*y)++;
	}
	return (ERROR);
}

int	fill_struct_player(Player *player, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (found_pos_player(map, &x, &y) == ERROR)
		return (ERROR);
	player->pos_x = (double)x;
	player->pos_y = (double)y;
	return (OK);
}
