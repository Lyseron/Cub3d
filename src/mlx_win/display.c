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
	ft_bzero(game->img.img_addr, game->height * game->img.size_line);
	if (raycasting(game, &game->player) == ERROR)
		return (ERROR);
	if ((MARGE + game->map.map_x * SIZE_SQUARE <= game->width / 2
			&& MARGE + game->map.map_y * SIZE_SQUARE <= game->height / 2)
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
	if (game->bool_key.change_hand == false)
	{
		if (draw_left_img(game, &game->hand) == ERROR)
			return (ERROR);
		if (draw_right_img(game, &game->brush) == ERROR)
			return (ERROR);
	}
	else
	{
		if (draw_middle_img(game, &game->hand_2.anim_img[game->hand_2.frame_id]) == ERROR)
			return (ERROR);
	}
	// if (DEBUG)
	// 	ft_bzero(game->img.img_addr, game->height * game->width * (game->img.bits_per_pixel / 8));
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	return (OK);
}

int	display_check(t_game *game)
{
	if (!game || !game->img.img_addr)
		return (ERROR);
	if (display(game) == ERROR)
		return (ERROR);
	return (OK);
}
