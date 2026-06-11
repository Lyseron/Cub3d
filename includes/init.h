/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:56:19 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/11 17:43:34 by mvignes          ###   ########.fr       */
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
int		key(int key_choice, t_game *game);
int		init_mlx(t_game *game);

/* ------------------- Init_player.c ----------------------- */
int		fill_struct_player(t_player *player, char **map);

#endif