/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:34:39 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/07 11:56:05 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	init_speed(t_game *game)
{
	if (game->bool_key.shift)
		game->player.speed_player = (SPEED * SPEED_SPRIT) * update_time(game); // * fragtime
	else
		game->player.speed_player = SPEED * update_time(game); // * fragtime
}

static int	moove_player(t_game *game, double dir_x, double dir_y)
{
	double	next_pos_player_x;
	double	next_pos_player_y;

	next_pos_player_x = game->player.pos_x + dir_x * game->player.speed_player;
	next_pos_player_y = game->player.pos_y + dir_y * game->player.speed_player;
	// printf("current: x=%f y=%f\n", game->player.pos_x,
		// game->player.pos_y);
	// printf("next: x=%f, y=%f\n", next_pos_player_x,
		// next_pos_player_y);
	if (next_pos_player_x - BORDER_PLAYER >= 0
		&& next_pos_player_x + BORDER_PLAYER < game->map.map_x)
	{
		if (is_bordplayer_touch_wall(game, next_pos_player_x,
				game->player.pos_y) == false)
			game->player.pos_x = next_pos_player_x;
	}
	if (next_pos_player_y - BORDER_PLAYER >= 0
		&& next_pos_player_y + BORDER_PLAYER < game->map.map_y)
	{
		if (is_bordplayer_touch_wall(game, game->player.pos_x,
				next_pos_player_y) == false)
			game->player.pos_y = next_pos_player_y;
	}
	// printf("suposidly moove to x=%f y=%f\n",
		// game->player.pos_x, game->player.pos_y);
	return (OK);
}

int	is_moove_ok(t_game *game, int key_choice)
{
	if (key_choice == UP)
		return (moove_player(game, game->player.dir_x, game->player.dir_y));
	else if (key_choice == LEFT)
		return (moove_player(game, game->player.dir_y, -game->player.dir_x));
	else if (key_choice == RIGHT)
		return (moove_player(game, -game->player.dir_y, game->player.dir_x));
	else if (key_choice == DOWN)
		return (moove_player(game, -game->player.dir_x, -game->player.dir_y));
	else
		return (ERROR);
}

void	key_moove(t_game *game)
{
	if (game->bool_key.w && is_moove_ok(game, UP) == OK)
		game->moved = true;
	if (game->bool_key.a && is_moove_ok(game, LEFT) == OK)
		game->moved = true;
	if (game->bool_key.s && is_moove_ok(game, DOWN) == OK)
		game->moved = true;
	if (game->bool_key.d && is_moove_ok(game, RIGHT) == OK)
		game->moved = true;
	if (game->bool_key.left)
	{
		game->player.angle += TURN_LEFT * SPEED_CAM;
		update_dir(game);
		game->moved = true;
	}
	if (game->bool_key.right)
	{
		game->player.angle += TURN_RIGTH * SPEED_CAM;
		update_dir(game);
		game->moved = true;
	}
}

// en ajoutant la distance depuis le milieu de lcran
void	mouse_moove(t_game *game)
{
	int	x;
	int	y;
	int	dist_from_middle_screen;

	if (game->bool_key.mouse)
	{
		mlx_mouse_get_pos(game->mlx, game->win, &x, &y);
		dist_from_middle_screen = x - (game->width / 2);
		if (dist_from_middle_screen == 0)
			return ;
		game->player.angle += dist_from_middle_screen * SENSITIVITY_MOUSE;
		update_dir(game);
		game->moved = true;
		mlx_mouse_move(game->mlx, game->win, game->width / 2, game->height / 2);
		mlx_mouse_hide(game->mlx, game->win);
	}
	else
		mlx_mouse_show(game->mlx, game->win);
}

int	game_loop(t_game *game)
{
	bool	hand2_anim_change;

	game->moved = false;
	init_speed(game);
	key_moove(game);
	mouse_moove(game);
	hand2_anim_change = moove_anim(&game->hand_2);
	if (game->moved == true
		|| hand2_anim_change == true)
	{
		if (display_check(game) == ERROR)
			return (ERROR);
	}
	return (OK);
}
