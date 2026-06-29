/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:57:12 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/18 14:23:01 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WIN_H
# define MLX_WIN_H
# include "structs.h"

/* ------------------- create_img.c ------------------------ */
int		create_initial_img(t_game *game);

int		keyno(int key, t_game *game);
int		keywee(int key, t_game *game);

#endif