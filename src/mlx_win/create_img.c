/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:11:19 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/09 17:11:19 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	create_initial_img(t_game *game)
{
	if (!game || !game->mlx || !game->win)
		return (ERROR);
	game->img.img_ptr = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img.img_ptr)
		return (ERROR);
	game->img.img_addr = mlx_get_data_addr(game->img.img_ptr,
			&game->img.bits_per_pixel, &game->img.size_line, &game->img.endian);
	if (!game->img.img_addr)
		return (ERROR);
	if (draw_mini_map(game) == ERROR)
		return (ERROR);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	return (OK);
}
