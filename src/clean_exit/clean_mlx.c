/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:55:55 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/09 16:55:55 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"
#include "../includes/parsing.h"

int	exit_game(Game *game)
{
	(void)game;
	exit(OK);
	return (OK);
}
