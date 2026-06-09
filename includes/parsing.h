/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-08 13:35:57 by lyaberge          #+#    #+#             */
/*   Updated: 2026-06-08 13:35:57 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cube.h"

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
int		key(int key_choice, Game *game);
int		init_mlx(Game *game);

/* ------------------- create_img.c ------------------------ */
int		create_img(Game *game);

#endif