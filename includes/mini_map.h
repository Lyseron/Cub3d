/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:57:51 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/18 15:35:34 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_MAP_H
# define MINI_MAP_H
# include "structs.h"

/* ------------------- Draw_mini_map.c --------------------- */
int	draw_mini_map(t_game *game);

/* ------------------- Draw_mini_map_utils.c --------------- */
int	tiny_map_conditions(t_game *game, int x, int y);
int	draw_tiny_square(t_game *game, int map_x, int map_y, int color);
int	draw_pixel(t_game *game, int x, int y, unsigned int color);
int	draw_mini_map(t_game *game);

/* ------------------- Gameplay.c -------------------------- */
int	key(int key_choice, t_game *game);

#endif