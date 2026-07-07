/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:35:57 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/07 11:33:38 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/* =================== INIT.c =========================== */

/* ------------------- Exctract_color.c -------------------- */
int		sort_color(char *line, t_map *map);

/* ------------------- Exctract_map.c ---------------------- */
bool	extract_map(char *line, t_map *map);

/* ------------------- verif_extract.c ----------------------- */
bool	line_not_parasite(char *line, t_map *map);

/* ------------------- Exctract_texture_and_color.c -------- */
int		sort_value(char *line, t_map *map);

/* ------------------- Exctract.c -------------------------- */
bool	extract_data(t_map *map);
bool	verif_init_value(t_map *map);

/* ------------------- Init_mlx.c -------------------------- */
int		init_mlx(t_game *game);
void	init_key(t_game *game);

/* ------------------- Init_player.c ----------------------- */
int		fill_struct_player(t_game *game);
int		get_dir_y(char where_player_look);
int		get_dir_x(char where_player_look);
void	update_dir(t_game *game);

/* =================== PARSING.c =========================== */

/* ------------------- Parsing.c --------------------------= */
int		parsing(t_game *game, char **av);

/* ------------------- Check_map_cub.c --------------------- */
int		ft_decide(char *av);

/* ------------------- Check_name_texture ------------------*/
int		ft_decide_name_texture(char *av);

/* ------------------- Check_valid_map_utils.c ------------- */
bool	is_player(char c);
bool	is_valid_component(char c);
bool	has_good_component(char **map);

/* ------------------- Check_valid_map.c ------------------- */
int		check_map(t_map *maps);

/* ------------------- Read_map.c -------------------------- */
int		read_map(char *line, t_map *map);

void	door_open(t_game *game);
#endif