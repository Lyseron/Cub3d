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

#include "cube.h"

static int	found_pos_player(char **map, int *x, int *y, char *letter_player)
{
	*y = 0;
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x])
		{
			if (is_player(map[*y][*x]) == true)
			{
				*letter_player = map[*y][*x];
				map[*y][*x] = '0';
				return (OK);
			}
			(*x)++;
		}
		(*y)++;
	}
	return (ERROR);
}

double	get_angle(char where_player_look)
{
	if (where_player_look == 'N')
		return (3 * PI / 2);
	else if (where_player_look == 'S')
		return (PI / 2);
	else if (where_player_look == 'E')
		return (0);
	else if (where_player_look == 'W')
		return (PI);
	else
		return (10);
}

void	update_dir(t_game *game)
{
	game->player.dir_x = cos(game->player.angle);
	game->player.dir_y = sin(game->player.angle);
	game->ray.plane_x = -game->player.dir_y * 0.66;
	game->ray.plane_y = game->player.dir_x * 0.66;
}

int	fill_struct_player(t_game *game)
{
	int		x;
	int		y;
	char	letter_player;

	x = 0;
	y = 0;
	letter_player = '\0';
	if (found_pos_player(game->map.grid, &x, &y, &letter_player) == ERROR)
		return (ERROR);
	game->player.pos_x = (double)x + 0.5;
	game->player.pos_y = (double)y + 0.5;
	game->player.where_look = letter_player;
	game->player.angle = get_angle(letter_player);
	update_dir(game);
	return (OK);
}
