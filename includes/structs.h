/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scructs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:48:45 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/11 16:48:45 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../libft/libft.h"
# include <stdbool.h>

/*------------------------------------------------------------------ STRUCT ---------------------------------------------------------*/

typedef struct s_player
{
	char	where_look;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
}	t_player;

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
}	t_texture;

typedef struct s_map
{
	char	*map_name;
	int		map_fd;

	char	**grid;
	int		map_x;
	int		map_y;

	t_texture	texture;
	int		*Floor;
	bool	extract_floor;
	int		*Ceiling;
	bool	extract_ceiling;

	t_list	*extract;
	bool	error_doublon;
}	t_map;

typedef struct s_cub
{
	bool	error_doublon;
	t_map		*map;
	t_player	*player;
	t_texture	*texture;
} t_cub;

typedef struct	s_img
{
	int				width;
	int				height;
	void			*img_ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	char			*img_addr;
} t_img;

typedef struct	s_mini_map_coordonate
{
	int				win_x;
	int				win_y;
	int				start_y;
	int				start_x;
	int				end_y;
	int				end_x;
}	t_mini_map;

typedef struct s_mini_map_player
{
	double			start_y;
	double			start_x;
	double			end_y;
	double			end_x;
	double			player_pixel_y;
	double			player_pixel_x;
} t_mini_player;

typedef struct s_game
{
	t_map			map;
	t_player		player;
	void			*mlx;
	void			*win;
	t_img			img;
	t_mini_map		mini_map;
	t_mini_player	mini_player;
}	t_game;


#endif

