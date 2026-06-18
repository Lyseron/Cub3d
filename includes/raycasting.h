/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:28:37 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/18 15:44:29 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cube.h"


void	draw_all_3d(t_game *game);
void	raycasting(t_game *game);
void	moov_player(t_game *game, double cos_p, double sin_p);

#endif