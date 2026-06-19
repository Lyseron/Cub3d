/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:16:59 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/19 15:16:03 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


static bool	bordplayer_cond(t_game *game)
{
	if (game->mini_player.player_left < game->mini_map.map_case_right
		&& game->mini_player.player_right > game->mini_map.map_case_left
		&& game->mini_player.player_top < game->mini_map.map_case_bottom
		&& game->mini_player.player_bottom > game->mini_map.map_case_top)
		return (true);
	return (false);
}

static bool	is_bordplayer_touch_wall(t_game *game, double next_x, double next_y)
{
	int	y;
	int	x;

	init_mini_player_square(game, next_x, next_y);
	y = 0;
	while (y < game->map.map_y)
	{
		x = 0;
		while (x < game->map.map_x)
		{
			init_mini_map_square(game, x, y);
			if (game->map.grid[y][x] == '1')
			{
				if (bordplayer_cond(game) == true)
					return (true);
			}
			x++;
		}
		y++;
	}
	return (false);
}

// void	moove_player_utils(t_game *game, double dir_x, double dir_y, int key, double *next_pos_player_x, double *next_pos_player_y, double cos_p, double sin_p)
// {
// 	(void)cos_p;
// 	(void)sin_p;
// 	// (void)dir_x;
// 	// (void)dir_y;
// 	// printf("x = %f\n", dir_x);
// 	// printf("y = %f\n", dir_y);
// 	if (key == UP)
// 	{
// 		*next_pos_player_x = game->player.pos_x + dir_x * SPEED;
// 		*next_pos_player_y = game->player.pos_y + dir_y * SPEED;
// 	}
// 	if (key == DOWN)
// 	{
// 		*next_pos_player_x = game->player.pos_x - dir_x * SPEED;
// 		*next_pos_player_y = game->player.pos_y - dir_y * SPEED;
// 	}
// 	if (key == LEFT)
// 	{
// 		*next_pos_player_x = game->player.pos_x + dir_y * SPEED;
// 		*next_pos_player_y = game->player.pos_y + dir_x * SPEED;
// 	}
// 	if (key == RIGHT)
// 	{
// 		*next_pos_player_x = game->player.pos_x - dir_y * SPEED;
// 		*next_pos_player_y = game->player.pos_y - dir_x * SPEED;
// 	}
// }

// void	move_player(t_game *game)
// {
// 	if (game->bool_key.right)
// 		game->player.plane += TURN_RIGTH * SPEED_CAM;
// 	if (game->bool_key.left)
// 		game->player.plane += TURN_LEFT * SPEED_CAM;
// 	if (game->bool_key.w)
// 	{
// 		game->player.pos_x = game->player.pos_x + (game->ray.cos_p * SPEED);
// 		game->player.pos_y = game->player.pos_y + (game->ray.sin_p * SPEED);
// 	}
// 	if (game->bool_key.a)
// 	{
// 		game->player.pos_x = game->player.pos_x + (game->ray.sin_p * SPEED);
// 		game->player.pos_y = game->player.pos_y - (game->ray.cos_p * SPEED);
// 	}
// 	if (game->bool_key.s)
// 	{
// 		game->player.pos_x = game->player.pos_x - (game->ray.cos_p * SPEED);
// 		game->player.pos_y = game->player.pos_y - (game->ray.sin_p * SPEED);
// 	}
// 	if (game->bool_key.d)
// 	{
// 		game->player.pos_x = game->player.pos_x - (game->ray.sin_p * SPEED);
// 		game->player.pos_y = game->player.pos_y + (game->ray.cos_p * SPEED);
// 	}
// }





void	moove_player_utils(t_game *game, double *next_x, double *next_y)
{
	if (game->bool_key.w)
	{
		printf("OUI OUI TG\n");
		*next_x = game->player.pos_x + (game->ray.cos_p * SPEED);
		*next_y = game->player.pos_y + (game->ray.sin_p * SPEED);
	}
	if (game->bool_key.a)
	{
		printf("OUI NON TG\n");
		*next_x = game->player.pos_x + (game->ray.sin_p * SPEED);
		*next_y = game->player.pos_y - (game->ray.cos_p * SPEED);
	}
	if (game->bool_key.s)
	{
		printf("NONO NONO TG\n");
		*next_x = game->player.pos_x - (game->ray.cos_p * SPEED);
		*next_y = game->player.pos_y - (game->ray.sin_p * SPEED);
	}
	if (game->bool_key.d)
	{
		printf("NON OUI TG\n");
		*next_x = game->player.pos_x - (game->ray.sin_p * SPEED);
		*next_y = game->player.pos_y + (game->ray.cos_p * SPEED);
	}
	if (game->bool_key.right)
		game->player.plane += TURN_RIGTH * SPEED_CAM;
	if (game->bool_key.left)
		game->player.plane += TURN_LEFT * SPEED_CAM;
}

void	move_player(t_game *game)
{
	double	next_pos_player_x;
	double	next_pos_player_y;

	moove_player_utils(game, &next_pos_player_x, &next_pos_player_y);
	if (next_pos_player_x - BORDER_PLAYER < 0
		|| next_pos_player_y - BORDER_PLAYER < 0)
		return ;
	if (next_pos_player_x + BORDER_PLAYER >= game->map.map_x
		|| next_pos_player_y + BORDER_PLAYER >= game->map.map_y)
		return ;
	if (game->map.grid[(int)(next_pos_player_y)][(int)(next_pos_player_x)] == '1')
		return ;
	// if (is_bordplayer_touch_wall(game, next_pos_player_x, next_pos_player_y) == true)
	// {
	game->player.pos_x = next_pos_player_x;
	game->player.pos_y = next_pos_player_y;
	// }
}

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

int	keywee(int key, t_game *game)
{
	if (key == ESC)
		return (exit_game(game), OK);
	if (key == XK_w)
		game->bool_key.w = true;
	if (key == XK_a)
		game->bool_key.a = true;
	if (key == XK_s)
		game->bool_key.s = true;
	if (key == XK_d)
		game->bool_key.d = true;
	if (key == XK_Left)
		game->bool_key.left = true;
	if (key == XK_Right)
		game->bool_key.right = true;
	return (0);
}

