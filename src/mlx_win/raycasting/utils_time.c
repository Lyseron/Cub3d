/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:57:12 by mvignes           #+#    #+#             */
/*   Updated: 2026/07/10 14:22:31 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/// @brief Look at the weather since January 1, 1970
/// @param (void)
/// @return Return time
long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/// @brief fluidizes a constant number of frames per second to avoid variations
/// @param game 
/// @return 
double	update_time(t_game *game)
{
	double	frame_time;

	game->old_time = game->time;
	game->time = get_time();
	frame_time = game->time - game->old_time;
	if (frame_time > 0.05 || frame_time < 0)
		frame_time = 0.05;
	return (frame_time);
}
