/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:38:07 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/10 17:00:09 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <stdbool.h>

# include "parsing.h"

# define OK 0
# define ERROR 1

/*------------------------------------------------------------------ STRUCT ---------------------------------------------------------*/

typedef struct s_player
{

}	Player;

typedef	struct s_texture
{
	char	*NO;
	void	*img_no;
	char	*SO;
	void	*img_so;
	char	*WE;
	void	*img_we;
	char	*EA;
	void	*img_ea;
}	Texture;

typedef struct s_map
{
	char	*map_name;
	int		map_fd;

	char	**grid;
	int		map_x;
	int		map_y;

	Texture	texture;
	int		*Floor;
	bool	extract_floor;
	int		*Ceiling;
	bool	extract_ceiling;

	t_list	*extract;
	bool	error_doublon;
}	Map;

typedef struct s_key
{

}	Key;

typedef struct s_cub
{
	bool	error_doublon;
	Map		*map;
	Player	*player;
	Texture	*texture;
} Cub;

#endif