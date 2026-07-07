/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:57:12 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/07 13:44:19 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WIN_H
# define MLX_WIN_H

/* =================== MLX_WIN.c =========================== */

/* ------------------- create_img.c ------------------------ */
int		init_img(t_game *game);
int		init_color_c_and_f(t_game *game);

/* ------------------- create_img_utils.c ------------------ */
bool	is_valid_color(int color);
int		laod_texture(t_game *game, t_img *tex, char *path);
int		convert_rgb_to_int(int t, int r, int g, int b);

/* ------------------- key.c ------------------------------- */
int		keyno(int key, t_game *game);
int		keywee(int key, t_game *game);
void	mouse_moove(t_game *game);

/* =================== MINI_MAP.c =========================== */

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

/* =================== RAYCASTING.c =========================== */

// void	draw_all_3d(t_game *game);
void	draw_square(int x, int y, int color, t_game *game);
void	draw_square_player(int x, int y, int color, t_game *game);
void	draw_map(t_game *game);

void	draw_line(t_game *game, double angle_rayon, int i);
void	draw_line_2d(t_player *player, t_game *game, double start_x, int i);
int		raycasting(t_game *game, t_player *player);
void	put_pixel(t_game *game, int x, int y, int color);

//	dda
void	search_cote_wall(t_game *game, t_ray *ray);
void	calcul_dist(t_game *game, t_ray *ray, double angle_rayon);
void	calcul_horizontal_intersection(t_game *game, t_ray *ray);
void	calcul_direct_wall(t_player *p, t_ray *ray);
void	init_dda(t_game *game, t_ray *ray, double angle_rayon);

// texture
int		calcul_pos_texture(t_game *game, t_ray *ray, int tex_width);
int		get_pixel_from_texture(t_img *tex, int tex_x, int tex_y);

double	update_time(t_game *game);

/* =================== ANIMATION.c ========================= */

/* ------------------- Init.c --------------------------==== */
int		init_img_hand(t_game *game);
int		init_img_hand2(t_game *game);
int		init_img_door(t_game *game);

/* ------------------- Init_ray.c -------------------------- */
bool	moove_anim(t_anim *anim);

/* ------------------- Draw_hand.c ------------------------- */
int		draw_left_img(t_game *game, t_img *img);
int		draw_right_img(t_game *game, t_img *img);
int		draw_middle_img(t_game *game, t_img *img);
#endif