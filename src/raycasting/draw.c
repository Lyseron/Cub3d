/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:35:41 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/18 14:39:29 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// void	put_pixel(t_game *game, int x, int y, int color)
// {
// 	char	*pixel;

// 	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
// 		return ;
// 	pixel = game->img.img_addr + (y * game->img.size_line + x
// 			* (game->img.bits_per_pixel / 8));
// 	*(unsigned int *)pixel = color;
// }

void	draw_all_3d(t_game *game)
{
	(void)game;
	printf("CC TU ES LA \n");
}
