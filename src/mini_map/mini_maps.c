/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 21:50:21 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/18 21:50:21 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	display(t_game *game)
{
	ft_bzero(game->img.img_addr, HEIGHT * game->img.size_line);
	if ((MARGE + game->map.map_x * SIZE_SQUARE < WIDTH
			&& MARGE + game->map.map_y * SIZE_SQUARE < HEIGHT)
		&& game->bool_key.change_map == false)
	{
		if (draw_mini_map(game) == ERROR)
			return (ERROR);
	}
	else
	{
		if (draw_tiny_map(game) == ERROR)
			return (ERROR);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	return (OK);
}

int	adaptative_mini_map(t_game *game)
{
	if (display(game) == ERROR)
		return (ERROR);
	return (OK);
}
