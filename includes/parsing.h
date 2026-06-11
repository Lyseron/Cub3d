/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:35:57 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/11 16:48:54 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cube.h"

typedef struct s_player		t_player;		// pas encore utile ici
typedef	struct s_texture	t_texture;	// pas encore utile ici
typedef struct s_map		t_map;		// utile ici
typedef struct s_key		t_key;		// pas encore utile ici
typedef struct s_cub		t_cub;		// pas encore utile ici

typedef struct s_game		t_game;		// utile ici

/*------------------------------------------------------------------ FONCTION ---------------------------------------------------------*/

bool	extract_map(char *line, t_map *map);
bool	extract_data(t_map *map);
int		sort_value(char *line, t_map *map);
int		read_map(char *line, t_map *map);
bool	verif_init_value(t_map *map);
int		sort_color(char *line, t_map *map);
int		ft_decide_name_texture(char *av);
int		print_error(char *str, t_map *map, int r);
void	free_data_fd(t_map *map);
void	free_line_and_gnl(char *line);
bool	verif_init_value(t_map *map);
bool	line_not_parasite(char *line, t_map *map);

/* ------------------- Check_valid_map_utils.c ------------- */
bool	is_player(char c);
bool	is_valid_component(char c);

/* ------------------- Check_valid_map.c ------------------- */
int		check_map(t_map *maps);

/* ------------------- Check_map_cub.c --------------------- */
int		ft_decide(char *av);

/* ------------------- init_player.c ----------------------- */
int		fill_struct_player(t_player *player, char **map);

/* ------------------- init_mlx.c -------------------------- */
int		key(int key_choice, t_game *game);
int		init_mlx(t_game *game);

/* ------------------- create_img.c ------------------------ */
int		create_img(t_game *game);
int		draw_pixel(t_game *game, int x, int y, unsigned int color);

/* ------------------- mini_map.c -------------------------- */
int		draw_tiny_map(t_game *game);

#endif