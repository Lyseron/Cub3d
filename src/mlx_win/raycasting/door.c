/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:04:47 by mvignes           #+#    #+#             */
/*   Updated: 2026/07/07 12:07:24 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/// @brief Verifie s'il y a une porte sur la case y de x
/// @param game 
/// @param x 
/// @param y 
/// @return  retour true s'il y a une porte
static bool	is_door_cell(t_game *game, int x, int y)
{
	if (y < 0 || y >= game->map.map_y)
		return (false);
	if (x < 0 || x >= (int)ft_strlen(game->map.grid[y]))
		return (false);
	if (game->map.grid[y][x] == '2' || game->map.grid[y][x] == '3')
        return (true);
    return (false);
}

/// @brief Regarde si devant le joueur il y a une porte (la distance est = a DOOR_RANGE)
/// @param game 
/// @param tx 
/// @param ty 
/// @return 
static bool	get_door_target(t_game *game, int *tx, int *ty)
{
	double	d;
	int		cx;
	int		cy;

	d = 0.2;
	while (d <= DOOR_RANGE)
	{
		cx = (int)(game->player.pos_x + game->ray.cos_p * d);
		cy = (int)(game->player.pos_y + game->ray.sin_p * d);
		if (is_door_cell(game, cx, cy))
		{
			*tx = cx;
			*ty = cy;
			return (true);
		}
		d += 0.1;
	}
	return (false);
}

/// @brief Cherche une porte devant le joueur
/// @param game 
void	door_open(t_game *game)
{
	int	x;
	int	y;

	if (!get_door_target(game, &x, &y))
		return ;
	if (game->map.grid[y][x] == '2')
		game->map.grid[y][x] = '3';
	else if (game->map.grid[y][x] == '3')
	{
		if ((int)game->player.pos_x != x || (int)game->player.pos_y != y)
			game->map.grid[y][x] = '2';
	}
}
