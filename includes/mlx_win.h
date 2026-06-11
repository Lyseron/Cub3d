/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:57:12 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/11 16:57:12 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WIN_H
# define MLX_WIN_H

/* ------------------- create_img.c ------------------------ */
int		create_img(t_game *game);
int		draw_pixel(t_game *game, int x, int y, unsigned int color);

#endif