/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:16:59 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/18 17:57:35 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"



int	keyno(int key, t_game *game)
{
	if (key == XK_w)
		game->bool_key.w = false;
	if (key == XK_a)
		game->bool_key.a = false;
	if (key == XK_s)
		game->bool_key.s = false;
	if (key == XK_d)
		game->bool_key.d = false;
	if (key == XK_Left)
		game->bool_key.left = false;
	if (key == XK_Right)
		game->bool_key.right = false;
	return (0);
}

void	moov_player(t_game *game, double cos_p, double sin_p)
{
	if (game->bool_key.right)
	{
		game->player.plane += TURN_RIGTH * SPEED_CAM;
	}
	else if (game->bool_key.left)
	{
		game->player.plane += TURN_LEFT * SPEED_CAM;
	}
	else if (game->bool_key.w)
	{
		/*int x // changer pour next*/game->player.pos_x = game->player.pos_x + (cos_p /* *ud_direction */ * SPEED);
		/*int y // changer pour next*/game->player.pos_y = game->player.pos_y + (sin_p /* *ud_direction */ * SPEED);
	}
	else if (game->bool_key.a)
	{
		/*int x // changer pour next*/game->player.pos_x = game->player.pos_x + (sin_p * SPEED);
		/*int y // changer pour next*/game->player.pos_y = game->player.pos_y - (cos_p * SPEED);
	}
	else if (game->bool_key.s)
	{
		/*int x // changer pour next*/game->player.pos_x = game->player.pos_x - (cos_p /* *ud_direction */ * SPEED);
		/*int y // changer pour next*/game->player.pos_y = game->player.pos_y - (sin_p /* *ud_direction */ * SPEED);
	}
	else if (game->bool_key.d)
	{
		/*int x // changer pour next*/game->player.pos_x = game->player.pos_x - (sin_p * SPEED);
		/*int y // changer pour next*/game->player.pos_y = game->player.pos_y + (cos_p * SPEED);
	}
}

int	keywee(int key, t_game *game)
{
	// double	cos_p = cos(game->player.plane);
	// double	sin_p = sin(game->player.plane);
	// (void)cos_p;
	// (void)sin_p;
	if (key == ESC)
		return (exit_game(game), OK);
	if (key == XK_w)
	{
		game->bool_key.w = true;
	}
	if (key == XK_a)
	{
		
		game->bool_key.a = true;
	}
	if (key == XK_s)
	{
		
		game->bool_key.s = true;
	}
	if (key == XK_d)
	{

		game->bool_key.d = true;
	}
	if (key == XK_Left)
	{

		game->bool_key.left = true;
	}
	if (key == XK_Right)
	{
		
		game->bool_key.right = true;
	}
	return (0);
}

