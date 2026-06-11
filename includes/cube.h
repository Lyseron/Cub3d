/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:38:07 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/10 22:17:01 by mvignes          ###   ########.fr       */
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
// # include <X11/keysym.h>

# include "parsing.h"
#include "clean_exit.h"

# define OK 0
# define ERROR 1
# define HEIGHT 400
# define WIDTH 600
# define SIZE_SQUARE 10

/*------------------------------------------------------------------ STRUCT ---------------------------------------------------------*/

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
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

typedef struct	s_mini_map_coordonate
{
	int	win_x;
	int	win_y;
	int	start_y;
	int	start_x;
	int	end_y;
	int	end_x;
}	Mini_map;

typedef struct s_game
{
	Map			map;
	Player		player;
	void		*mlx;
	void		*win;
	Img			img;
	Mini_map	mini_map;
}	Game;

#endif