/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:56:19 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/29 11:08:31 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H
# include "structs.h"

/* ------------------- Exctract_color.c -------------------- */
int		sort_color(char *line, t_map *map);

/* ------------------- verif_extract.c ----------------------- */
bool	line_not_parasite(char *line, t_map *map);

/* ------------------- Exctract_map.c ---------------------- */
bool	extract_map(char *line, t_map *map);

/* ------------------- Exctract_texture_and_color.c -------- */
int		sort_value(char *line, t_map *map);

/* ------------------- Exctract.c -------------------------- */
bool	extract_data(t_map *map);
bool	verif_init_value(t_map *map);

/* ------------------- Init_mlx.c -------------------------- */
int		init_mlx(t_game *game);

/* ------------------- Init_player.c ----------------------- */
int		fill_struct_player(t_player *player, char **map);
int		get_dir_y(char where_player_look);
int		get_dir_x(char where_player_look);

/* ------------------- Init_mini_player.c --------------------- */
void	init_mini_player(t_game *game);
void	init_mini_player_square(t_game *game, double next_x, double next_y);

/* ------------------- Init_mini_map.c --------------------- */
void	init_mini_map_coord(t_mini_map *mini_map, int map_x, int map_y);
void	init_mini_map_square(t_game *game, int x, int y);

/* ------------------- Init_ray.c ----------------------- */
// void	init_ray(t_game *game);

#endif