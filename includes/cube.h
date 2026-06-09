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
# include <stdbool.h>

# define OK 0
# define ERROR 1
# define HEIGHT 600
# define WIDTH 600

/*------------------------------------------------------------------ STRUCT ---------------------------------------------------------*/

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	int		dir_x;
	int		dir_y;
}	Player;

typedef	struct s_texture
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
}	Texture;

typedef struct s_map
{
	char	**map;
	Texture	texture;
	int		*Floor;
	int		*Ceiling;
}	Map;

typedef struct s_key
{

}	Key;

typedef struct	s_img
{
	int		width;
	int		height;
	void	*img_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*img_addr;
} Img;


typedef struct s_game
{
	Map		map;
	Player	player;
	void	*mlx;
	void	*win;
	Img		img;
}	Game;

#endif