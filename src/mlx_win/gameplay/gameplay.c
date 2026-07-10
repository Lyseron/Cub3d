/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:34:39 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/10 14:19:09 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/// @brief Check if the player sprit or no
/// @param game 
static void	init_speed(t_game *game)
{
	if (game->bool_key.shift)
		game->player.speed_player = (SPEED * SPEED_SPRIT) * update_time(game);
	else
		game->player.speed_player = SPEED * update_time(game);
}

/// @brief Check it is the next moove player it's correct
/// @param game 
/// @param dir_x 
/// @param dir_y 
/// @return return 0
static int	moove_player(t_game *game, double dir_x, double dir_y)
{
	double	next_pos_player_x;
	double	next_pos_player_y;

	next_pos_player_x = game->player.pos_x + dir_x * game->player.speed_player;
	next_pos_player_y = game->player.pos_y + dir_y * game->player.speed_player;
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

void	game_loop_action(t_game *game, bool *has_moved, bool *mona, bool *munch)
{
	if (game->bool_key.change_hand == true)
	{
		*has_moved = moove_anim(&game->phone);
		if (*has_moved == true
			&& game->phone.frame_id == game->phone.nb_of_img - 1)
		{
			door_open(game);
			game->bool_key.change_hand = false;
			game->anim_is_finish = true;
		}
	}
	if (game->start_anim_wall == true)
	{
		*mona = moove_anim(&game->mona);
		*munch = moove_anim(&game->munch);
		if (*mona == true
			&& game->mona.frame_id == game->mona.nb_of_img - 1)
			game->start_anim_wall = false;
		if (*munch == true
			&& game->munch.frame_id == game->munch.nb_of_img - 1)
			game->start_anim_wall = false;
	}
}

int	game_loop(t_game *game)
{
	bool	has_moved;
	bool	mona_has_moved;
	bool	munch_has_moved;

	game->moved = false;
	game->anim_is_finish = true;
	has_moved = false;
	mona_has_moved = false;
	munch_has_moved = false;
	init_speed(game);
	key_moove(game);
	#ifdef LINUX
	mouse_moove(game);
	#endif
	game_loop_action(game, &has_moved, &mona_has_moved, &munch_has_moved);
	if (game->moved == true
		|| has_moved == true
		|| mona_has_moved == true
		|| munch_has_moved == true)
	{
		if (display_check(game) == ERROR)
			return (ERROR);
	}
	return (OK);
}
