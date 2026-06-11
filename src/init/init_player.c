/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:53:12 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/11 16:49:15 by mvignes          ###   ########.fr       */
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

static int	get_dir_x(char where_player_look)
{
	if (where_player_look == 'N')
		return (0);
	else if (where_player_look == 'S')
		return (0);
	else if (where_player_look == 'E')
		return (1);
	else if (where_player_look == 'W')
		return (-1);
	else
		return (10);
}

static int	get_dir_y(char where_player_look)
{
	if (where_player_look == 'N')
		return (-1);
	else if (where_player_look == 'S')
		return (1);
	else if (where_player_look == 'E')
		return (0);
	else if (where_player_look == 'W')
		return (0);
	else
		return (10);
}

static int	found_dir_player(char **map, int *x, int *y)
{
	char	look_player;

	look_player = map[*y][*x];
	if (!look_player)
		return (ERROR);
	*x = get_dir_x(look_player);
	*y = get_dir_y(look_player);
	if (*x == 10 || *y == 10)
		return (ERROR);
	return (OK);
}

int	fill_struct_player(t_player *player, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (found_pos_player(map, &x, &y) == ERROR)
		return (ERROR);
	player->pos_x = (double)x;
	player->pos_y = (double)y;
	if (found_dir_player(map, &x, &y) == ERROR)
		return (ERROR);
	player->dir_x = (double)x;
	player->dir_y = (double)y;
	return (OK);
}
