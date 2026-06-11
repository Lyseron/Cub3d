/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:35:57 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/11 14:36:48 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/* ------------------- Check_map_cub.c --------------------- */
int		ft_decide(char *av);

/* ------------------- Check_name_texture ------------------*/
int		ft_decide_name_texture(char *av);

/* ------------------- Check_valid_map_utils.c ------------- */
bool	is_player(char c);
bool	is_valid_component(char c);

/* ------------------- Check_valid_map.c ------------------- */
int		check_map(t_map *maps);

/* ------------------- Read_map.c -------------------------- */
int		read_map(char *line, t_map *map);

#endif