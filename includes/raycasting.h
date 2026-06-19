/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:28:37 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/19 13:56:02 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cube.h"


void	draw_all_3d(t_game *game);
void	draw_square(int x, int y, int size, int color, t_game *game);
void	draw_map(t_game *game);
void	draw_line(t_player *player, t_game *game, float start_x, int i);
void	raycasting(t_game *game, t_player *player);
void	move_player(t_game *game);
void	put_pixel(t_game *game, int x, int y, int color);

#endif