/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:57:51 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/11 16:57:51 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_MAP_H
# define MINI_MAP_H

/* ------------------- Mini_maps.c -------------------------- */
int		display_check(t_game *game);

/* ------------------- Draw_mini_map.c --------------------- */
int		draw_mini_map(t_game *game);

/* ------------------- Draw_mp_components.c ---------------- */
int		draw_all_ray(t_game *game);
int		draw_player(t_game *game);
int		draw_mini_square(t_game *game, int map_x, int map_y, int color);
int		draw_pixel(t_game *game, int x, int y, unsigned int color);

/* ------------------- Draw_tiny_map.c --------------------- */
int		draw_tiny_map(t_game *game);
int		draw_tiny_square(t_game *game, int color);

/* ------------------- Draw_tm_components.c ---------------- */
int		draw_tiny_player(t_game *game);
int		draw_all_tiny_ray(t_game *game);
int		draw_background(t_game *game);

/* ------------------- Gameplay.c -------------------------- */
int		is_moove_ok(t_game *game, int key_choice);
int		game_loop(t_game *game);

/* ------------------- Gameplay_utils.c -------------------- */
bool	is_bordplayer_touch_wall(t_game *game, double next_x, double next_y);

/* ------------------- Init_mini_player.c ------------------ */
void	init_mini_player(t_game *game);
void	init_mini_player_square(t_game *game, double next_x, double next_y);

/* ------------------- Init_mini_map.c --------------------- */
void	init_mini_map_coord(t_mini_map *mini_map, int map_x, int map_y);
void	init_mini_map_square(t_game *game, int x, int y);

/* ------------------- Init_tiny_player.c ------------------ */
void	init_tiny_player(t_game *game);

/* ------------------- Init_tiny_map.c --------------------- */
void	init_tiny_map_bound(t_game *game);
void	init_tiny_map_coord(t_tiny_map *tiny_map);

/* ------------------- Init_ray.c -------------------------- */
void	init_ray(t_game *game);

/* ------------------- Draw_mp_utils.c --------------------- */
int		convert_map_y_to_win_y(int map_y);
int		convert_map_x_to_win_x(int map_x);

/* ------------------- Draw_tm_utils.c --------------------- */
int		convert_x_to_pixel(t_game *game, double x);
int		convert_y_to_pixel(t_game *game, double y);
bool	is_ray_stay_in_bound(t_game *game, double ray_pos_x, double ray_pos_y);
bool	is_ray_pixel_in_bound(t_game *game, int ray_pixel_x, int ray_pixel_y);

#endif