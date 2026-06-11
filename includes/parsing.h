/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:35:57 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/11 14:36:48 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cube.h"

typedef struct s_player		Player;		// pas encore utile ici
typedef	struct s_texture	Texture;	// pas encore utile ici
typedef struct s_map		Map;		// utile ici
typedef struct s_key		Key;		// pas encore utile ici
typedef struct s_cub		Cub;		// pas encore utile ici

typedef struct s_game		Game;		// utile ici

/*------------------------------------------------------------------ FONCTION ---------------------------------------------------------*/

bool	extract_map(char *line, Map *map);
bool	extract_data(Map *map);
int		sort_value(char *line, Map *map);
int		read_map(char *line, Map *map);
bool	verif_init_value(Map *map);
int		sort_color(char *line, Map *map);
int		ft_decide_name_texture(char *av);

int		print_error(char *str, Map *map, int r);
void	free_data_fd(Map *map);
void	free_line_and_gnl(char *line);
/* ------------------- Check_valid_map_utils.c ------------- */
bool	is_player(char c);
bool	is_valid_component(char c);

/* ------------------- Check_valid_map.c ------------------- */
int		check_map(Map *maps);

/* ------------------- Check_map_cub.c --------------------- */
int		ft_decide(char *av);

/* ------------------- init_player.c ----------------------- */
int		fill_struct_player(Player *player, char **map);

/* ------------------- init_mlx.c -------------------------- */
int		key(int key_choice, void *game);
int		init_mlx(Game *game);

/* ------------------- create_img.c ------------------------ */
int		create_img(Game *game);
int		draw_pixel(Game *game, int x, int y, unsigned int color);

/* ------------------- mini_map.c -------------------------- */
int		draw_tiny_map(Game *game);

#endif