/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mp_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 19:30:15 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/02 19:30:15 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// convert the coordonate of map_x into windows coordonne in pixel
int	convert_map_x_to_win_x(int map_x)
{
	return (map_x * SIZE_SQUARE + MARGE);
}

int	convert_map_y_to_win_y(int map_y)
{
	return (map_y * SIZE_SQUARE + MARGE);
}
