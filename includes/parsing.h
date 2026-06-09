/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:35:57 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/09 14:19:23 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/*------------------------------------------------------------------ STRUCT ---------------------------------------------------------*/

typedef struct s_player		Player;		// pas encore utile ici
typedef	struct s_texture	Texture;	// pas encore utile ici
typedef struct s_map		Map;		// utile ici
typedef struct s_key		Key;		// pas encore utile ici
typedef struct s_cub		Cub;		// pas encore utile ici

/*------------------------------------------------------------------ FONCTION ---------------------------------------------------------*/

bool	extract_data(char *map_name, Map *map);
void	sort_value(char *line, Map *map);

#endif