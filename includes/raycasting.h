/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:28:37 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/21 11:30:43 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cube.h"

typedef struct s_game	t_game;

// void	draw_all_3d(t_game *game);
void	draw_square(int x, int y, int color, t_game *game);
void	draw_square_player(int x, int y, int color, t_game *game);
void	draw_map(t_game *game);

void	draw_line(t_game *game, double angle_rayon, int i);
void	draw_line_2d(t_player *player, t_game *game, double start_x, int i);
void	raycasting(t_game *game, t_player *player);
void	move_player(t_game *game);
void	put_pixel(t_game *game, int x, int y, int color);


//	dda
void	search_cote_wall(t_game *game, t_ray *ray);
void	calcul_dist(t_game *game, t_ray *ray, double angle_rayon);
void	calcul_horizontal_intersection(t_game *game, t_ray *ray);
void	calcul_direct_wall(t_player *, t_ray *ray);
void	init_dda(t_game *game, t_ray *ray, double angle_rayon);

// texture
int	init_all_textures(t_game *game, t_texture *texture);
int	calcul_pos_texture(t_game *game, t_ray *ray, int tex_width);
int	get_pixel_from_texture(t_img *tex, int tex_x, int tex_y);



double	update_time(t_game *game);
void	door_open(t_game *game);
bool	player_proche_door(t_game *game, t_player *player);

#endif