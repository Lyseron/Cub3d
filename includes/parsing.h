/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:35:57 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/10 20:15:36 by mvignes          ###   ########.fr       */
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

bool	extract_map(char *line, Map *map);
bool	extract_data(Map *map);
int		sort_value(char *line, Map *map);
int		read_map(char *line, Map *map);
bool	verif_init_value(Map *map);
int		sort_color(char *line, Map *map);
int		ft_decide_name_texture(char *av);

int		print_error(char *str, Map *map, int r);
void	free_data_fd(Map *map);

#endif