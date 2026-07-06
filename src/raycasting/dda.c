/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vignesmattheu <vignesmattheu@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 13:32:41 by mvignes           #+#    #+#             */
/*   Updated: 2026/07/06 09:16:47 by vignesmatth      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_dda(t_game *game, t_ray *ray, double angle_rayon)
{
	ray->cos_p = cos(angle_rayon);
	ray->sin_p = sin(angle_rayon);
	ray->map_x = (int)game->player.pos_x;
	ray->map_y = (int)game->player.pos_y;
	ray->delta_dist_x = fabs(1 / ray->cos_p);
	ray->delta_dist_y = fabs(1 / ray->sin_p);
}

void	calcul_direct_wall(t_player *p, t_ray *ray)
{
	if (ray->cos_p < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (p->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - p->pos_x) * ray->delta_dist_x;
	}
	if (ray->sin_p < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (p->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - p->pos_y) * ray->delta_dist_y;
	}
}


static bool	cell_is_door(t_game *game, int x, int y)
{
	if (y < 0 || y >= game->map.map_y)
		return (false);
	if (x < 0 || x >= (int)ft_strlen(game->map.grid[y]))
		return (false);
	return (game->map.grid[y][x] == '2');
}

bool	player_proche_door(t_game *game, t_player *player)
{
	int	px;
	int	py;

	px = (int)player->pos_x;
	py = (int)player->pos_y;
	return (cell_is_door(game, px, py)
		|| cell_is_door(game, px + 1, py) || cell_is_door(game, px - 1, py)
		|| cell_is_door(game, px, py + 1) || cell_is_door(game, px, py - 1));
}

// bool	player_proche_door(t_game *game, t_player *player)
// {
// // printf("door = %d\n", game->bool_key.door);
// if (!game->bool_key.door)
// // return (false);
// if (game->map.grid[(int)player->pos_y][(int)player->pos_x] == '2'
// // || game->map.grid[(int)player->pos_y + 1][(int)player->pos_x] == '2'
// // || game->map.grid[(int)player->pos_y - 1][(int)player->pos_x] == '2'
// // || game->map.grid[(int)player->pos_y][(int)player->pos_x + 1] == '2'
// // || game->map.grid[(int)player->pos_y][(int)player->pos_x - 1] == '2'
// // || game->map.grid[(int)player->pos_y + 1][(int)player->pos_x + 1] == '2'
// // || game->map.grid[(int)player->pos_y - 1][(int)player->pos_x + 1] == '2'
// // || game->map.grid[(int)player->pos_y - 1][(int)player->pos_x - 1] == '2'
// // || game->map.grid[(int)player->pos_y + 1][(int)player->pos_x - 1] == '2')
// // return (true);
// return (false);
//}

void	calcul_horizontal_intersection(t_game *game, t_ray *ray)
{
	ray->touch = false;
	// ray->wall_touch = 0;
	while (ray->touch == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->wall_touch = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->wall_touch = 1;
		}
		if (ray->map_y < 0 || ray->map_x < 0)
			break ;
		if (game->map.grid[ray->map_y][ray->map_x] == '1' /*|| game->map.grid[ray->map_y][ray->map_x] == '3'*/)
		{
			// if ()
			ray->touch = 1;
		}
		else if (game->map.grid[ray->map_y][ray->map_x] == '2' /*&& !game->bool_key.door *//*!player_proche_door(game, &game->player)*/)
		{
			// game->map.grid[ray->map_y][ray->map_x] = '3';
			// game->is_door_open = true;
			ray->touch = 2;
		}
	}
}

void	calcul_dist(t_game *game, t_ray *ray, double angle_rayon)
{
	t_player	*player;
	double		angle_correctif;

	player = &game->player;
	if (ray->wall_touch == 0)
		ray->dist_perp = (ray->map_x - player->pos_x + (1 - ray->step_x) / 2)
			/ ray->cos_p;
	else
		ray->dist_perp = (ray->map_y - player->pos_y + (1 - ray->step_y) / 2)
			/ ray->sin_p;
	angle_correctif = angle_rayon - player->plane;			//<----- regle le probleme du fisheye mais fait twerker les murs
	ray->dist_perp *= cos(angle_correctif);					//<----- regle le probleme du fisheye mais fait twerker les murs
	if (ray->dist_perp < 0.05)
		ray->dist_perp = 0.05;
}

// 3 == ouest/ 4 == est/ 1 == nord/ 2 == sud
void	search_cote_wall(t_game *game, t_ray *ray)
{
	// if (ray->touch == 2)
	// 	return ;
	(void)game;
	if (ray->wall_touch == 0)
	{
		if (ray->step_x > 0)
			ray->wall_touch = 3;
		else
			ray->wall_touch = 4;
	}
	else
	{
		if (ray->step_y > 0)
			ray->wall_touch = 1;
		else
			ray->wall_touch = 2;
	}
}
