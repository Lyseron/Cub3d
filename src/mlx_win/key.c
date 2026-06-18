/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:16:59 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/18 18:39:21 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


// static bool	bordplayer_cond(t_game *game)
// {
// 	if (game->mini_player.player_left < game->mini_map.map_case_right
// 		&& game->mini_player.player_right > game->mini_map.map_case_left
// 		&& game->mini_player.player_top < game->mini_map.map_case_bottom
// 		&& game->mini_player.player_bottom > game->mini_map.map_case_top)
// 		return (true);
// 	return (false);
// }

// static bool	is_bordplayer_touch_wall(t_game *game, double next_x, double next_y)
// {
// 	int	y;
// 	int	x;

// 	init_mini_player_square(game, next_x, next_y);
// 	y = 0;
// 	while (y < game->map.map_y)
// 	{
// 		x = 0;
// 		while (x < game->map.map_x)
// 		{
// 			init_mini_map_square(game, x, y);
// 			if (game->map.grid[y][x] == '1')
// 			{
// 				if (bordplayer_cond(game) == true)
// 					return (true);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (false);
// }

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

// static int	moove_player(t_game *game, double dir_x, double dir_y, int key, double cos_p, double sin_p)
// {
// 	double	next_pos_player_x;
// 	double	next_pos_player_y;

// 	// next_pos_player_x = game->player.pos_x + dir_x * SPEED;
// 	// next_pos_player_y = game->player.pos_y + dir_y * SPEED;

// 	moove_player_utils(game, dir_x, dir_y, key, &next_pos_player_x, &next_pos_player_y, cos_p, sin_p);
// 	// printf("current: x=%f y=%f\n", game->player.pos_x,
// 		// game->player.pos_y);
// 	// printf("next: x=%f, y=%f\n", next_pos_player_x,
// 		// next_pos_player_y);
// 	if (next_pos_player_x - BORDER_PLAYER < 0
// 		|| next_pos_player_y - BORDER_PLAYER < 0)
// 		return (/*printf("ERROR: Negative Value\n"), */ERROR);
// 	if (next_pos_player_x + BORDER_PLAYER >= game->map.map_x
// 		|| next_pos_player_y + BORDER_PLAYER >= game->map.map_y)
// 		return (/*printf("ERROR: out of map\n"), */ERROR);
// 	if (is_bordplayer_touch_wall(game, next_pos_player_x,
// 			next_pos_player_y) == true)
// 		return (/*printf("ERROR: Touching wall\n"), */ERROR);
// 	game->player.pos_x = next_pos_player_x;
// 	game->player.pos_y = next_pos_player_y;
// 	// printf("suposidly moove to x=%f y=%f\n",
// 		// game->player.pos_x, game->player.pos_y);
// 	return (OK);
// }

// // static void	update_dir(t_game *game, char look)
// // {
// // 	game->player.dir_x = get_dir_x(look);
// // 	game->player.dir_y = get_dir_y(look);
// // 	game->ray.plane_x = -game->player.dir_y * 0.66;
// // 	game->ray.plane_y = game->player.dir_x * 0.66;
// // }

// static int	update_plane(t_game *game, int key)
// {
// 	if (key == XK_Left)
// 	{
// 		// printf("OUI OUI BAGUETTE \n");
// 		// printf("play dir y = \n", )
// 		printf("play dir y = %f\n", game->player.dir_y);
// 		printf("play dir x = %f\n", game->player.dir_x);
// 		game->player.dir_y -= SPEED_CAM;
// 		if (game->player.dir_y >= 2 * PI)
// 			game->player.dir_y = 0;
// 		if (game->player.dir_y < 0)
// 			game->player.dir_y = 2 * PI;
// 		game->player.dir_x -= SPEED_CAM;
// 		if (game->player.dir_x >= 2 * PI)
// 			game->player.dir_x = 0;
// 		if (game->player.dir_x < 0)
// 			game->player.dir_x = 2 * PI;
// 		return (OK);
// 	}
// 	else if (key == XK_Right)
// 	{
// 		// printf("NON NON BAGUETTE \n");
// 		printf("play dir y = %f\n", game->player.dir_y);
// 		printf("play dir x = %f\n", game->player.dir_x);
// 		game->player.dir_y += SPEED_CAM;
// 		game->player.dir_x += SPEED_CAM;
// 		return (OK);
// 	}
// 	return (ERROR);
// }

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
	if (game->bool_key.left)
	{
		game->player.plane += TURN_LEFT * SPEED_CAM;
	}
	if (game->bool_key.w)
	{
		/*int x // changer pour next*/game->player.pos_x = game->player.pos_x + (cos_p /* *ud_direction */ * SPEED);
		/*int y // changer pour next*/game->player.pos_y = game->player.pos_y + (sin_p /* *ud_direction */ * SPEED);
	}
	if (game->bool_key.a)
	{
		/*int x // changer pour next*/game->player.pos_x = game->player.pos_x + (sin_p * SPEED);
		/*int y // changer pour next*/game->player.pos_y = game->player.pos_y - (cos_p * SPEED);
	}
	if (game->bool_key.s)
	{
		/*int x // changer pour next*/game->player.pos_x = game->player.pos_x - (cos_p /* *ud_direction */ * SPEED);
		/*int y // changer pour next*/game->player.pos_y = game->player.pos_y - (sin_p /* *ud_direction */ * SPEED);
	}
	if (game->bool_key.d)
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

