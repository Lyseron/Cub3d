/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:57:12 by mvignes           #+#    #+#             */
/*   Updated: 2026/07/05 11:42:22 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

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
