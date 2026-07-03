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
int	init_img(t_game *game);
int	init_color_c_and_f(t_game *game);

/* ------------------- key.c ------------------------------- */
int	keyno(int key, t_game *game);
int	keywee(int key, t_game *game);

#endif