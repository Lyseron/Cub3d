/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:04:47 by mvignes           #+#    #+#             */
/*   Updated: 2026/07/10 14:16:11 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/// @brief Write the good pixel which good color in address image
/// @param game 
/// @param x 
/// @param y 
/// @param color 
void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= game->width || y < 0 || y >= game->height)
		return ;
	pixel = game->img.img_addr + (y * game->img.size_line + x
			* (game->img.bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}
