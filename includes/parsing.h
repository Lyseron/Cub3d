/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-08 13:35:57 by lyaberge          #+#    #+#             */
/*   Updated: 2026-06-08 13:35:57 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "cube.h"

/* ------------------- Check_valid_map_utils.c ------------- */
bool	is_player(char c);
bool	is_valid_component(char c);

/* ------------------- Check_valid_map.c ------------------- */
int		check_map(Map *maps);

/* ------------------- Check_map_cub.c ------------- */
int		ft_decide(char *av);

#endif