/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vignesmattheu <vignesmattheu@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 21:50:21 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/13 09:11:43 by vignesmatth      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	draw_line_test(t_game *game)
{
	int	i = 0;

	while (i < 64)
	{
		put_pixel(game, game->width / 2 + i, game->height / 2, 0x0000FF);
		i++;
	}
	return (false);
}

static int	mini_maps_choice(t_game *game)
{
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
	return (OK);
}

static int	hand_choice(t_game *game)
{
	if (game->bool_key.change_hand == false)
	{
		if (draw_left_img(game,
				&game->left_hand.anim_img[game->left_hand.frame_id]) == ERROR)
			return (ERROR);
		if (draw_right_img(game,
				&game->right_hand.anim_img[game->right_hand.frame_id]) == ERROR)
			return (ERROR);
	}
	else
	{
		if (draw_middle_img(game,
				&game->phone.anim_img[game->phone.frame_id]) == ERROR)
			return (ERROR);
	}
	return (OK);
}

int	display(t_game *game)
{
	if (raycasting(game, &game->player) == ERROR)
		return (ERROR);
	if (mini_maps_choice(game) == ERROR)
		return (ERROR);
	if (hand_choice(game) == ERROR)
		return (ERROR);
	if (game->bool_key.view_key_press)
	{
		// printf("Bool activé\n");
		if (view_key_press(game, &game->bool_key))
		{
			// printf("Error view key press\n");
			return (ERROR);
		}
	}
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
