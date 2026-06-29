/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:08:07 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/29 12:08:13 by mvignes          ###   ########.fr       */
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

static bool	is_bordplayer_touchwall(t_game *game, double next_x, double next_y)
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

void	moove(t_game *game, t_player *player, double *next_x, double *next_y)
{
	if (game->bool_key.w)
	{
		*next_x += (game->ray.cos_p * player->speed_player);
		*next_y += (game->ray.sin_p * player->speed_player);
	}
	if (game->bool_key.a)
	{
		*next_x += (game->ray.sin_p * player->speed_player);
		*next_y -= (game->ray.cos_p * player->speed_player);
	}
	if (game->bool_key.s)
	{
		*next_x -= (game->ray.cos_p * player->speed_player);
		*next_y -= (game->ray.sin_p * player->speed_player);
	}
	if (game->bool_key.d)
	{
		*next_x -= (game->ray.sin_p * player->speed_player);
		*next_y += (game->ray.cos_p * player->speed_player);
	}
	if (game->bool_key.right)
		player->plane += TURN_RIGTH * SPEED_CAM;
	if (game->bool_key.left)
		player->plane += TURN_LEFT * SPEED_CAM;
}

static void	init_speed(t_game *game)
{
	if (game->bool_key.shift)
		game->player.speed_player = (SPEED * SPEED_SPRIT) * update_time(game); // * fragtime
	else
		game->player.speed_player = SPEED * update_time(game); // * fragtime
}

void	move_player(t_game *game)
{
	double	next_pos_play_x;
	double	next_pos_play_y;

	init_speed(game);
	next_pos_play_x = game->player.pos_x;
	next_pos_play_y = game->player.pos_y;
	moove(game, &game->player, &next_pos_play_x, &next_pos_play_y);
	if (next_pos_play_x - BORDER_PLAYER < 0
		|| next_pos_play_y - BORDER_PLAYER < 0)
		return ;
	if (next_pos_play_x + BORDER_PLAYER >= game->map.map_x
		|| next_pos_play_y + BORDER_PLAYER >= game->map.map_y)
		return ;
	if (game->map.grid[(int)(next_pos_play_y)][(int)(game->player.pos_x)] != '1') // a revoir, pas mal parce quon se bloque pas mais passe a travers les coins des mures
		game->player.pos_y = next_pos_play_y;
	if (game->map.grid[(int)(game->player.pos_y)][(int)next_pos_play_x] != '1')
		game->player.pos_x = next_pos_play_x;
	// if (is_bordplayer_touchwall(game, next_pos_play_x, next_pos_play_y))
	// {
	// 	printf("OUI OUI BAGUETTE\n");
	// 	return ;
	// }
		// return ;
	// game->player.pos_x = next_pos_play_x;
	// game->player.pos_y = next_pos_play_y;
}
