/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:38:07 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/08 17:17:08 by mvignes          ###   ########.fr       */
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

# define OK 0
# define ERROR 1

/*------------------------------------------------------------------ STRUCT ---------------------------------------------------------*/

typedef struct s_player
{

}	player;

typedef	struct s_texture
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
}	Texture;

typedef struct s_map
{
	Texture	texture;
	int		*Floor;
	int		*Ceiling;
}	Map;

typedef struct s_key
{

}	Key;

#endif