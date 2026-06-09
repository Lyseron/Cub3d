/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:50:07 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/09 13:50:07 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

bool	is_player(char c)
{
	if (c && (c == 'N' || c == 'S' || c == 'E' || c == 'W'))
		return (true);
	return (false);
}

bool	is_valid_component(char c)
{
	if (c && (c == '1' || c == '0' || is_player(c) || c == ' '))
		return (true);
	return (false);
}

