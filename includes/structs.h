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

typedef struct s_player
{
	char	where_look;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	angle;
}	t_player;

typedef struct s_texture
{
	char	*no;
	void	*img_no;
	char	*so;
	void	*img_so;
	char	*we;
	void	*img_we;
	char	*ea;
	void	*img_ea;
}	t_texture;

typedef struct s_map
{
	char		*map_name;
	int			map_fd;
	char		**grid;
	int			map_x;
	int			map_y;
	t_texture	texture;
	int			*floor;
	bool		extract_floor;
	int			*ceiling;
	bool		extract_ceiling;
	t_list		*extract;
	bool		error_doublon;
}	t_map;

typedef struct s_cub
{
	bool		error_doublon;
	t_map		*map;
	t_player	*player;
	t_texture	*texture;
}	t_cub;

typedef struct s_img
{
	int		width;
	int		height;
	void	*img_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*img_addr;
}	t_img;

typedef struct s_mini_map
{
	int		start_y;
	int		start_x;
	int		end_y;
	int		end_x;
	int		map_case_left;
	int		map_case_right;
	int		map_case_top;
	int		map_case_bottom;
}	t_mini_map;

typedef struct s_tiny_map
{
	int	start_y;
	int	end_y;
	int	start_x;
	int	end_x;

	int	pixel_x;
	int	pixel_y;
	int	start_pixel_x;
	int	start_pixel_y;
	int	end_pixel_y;
	int	end_pixel_x;
	int	player_center_x;
	int	player_center_y;

	int	max_x;
	int	max_y;
	int	min_y;
	int	min_x;
}	t_tiny_map;

typedef struct s_mini_map_player
{
	int		center_y;
	int		center_x;
	int		start_y;
	int		start_x;
	int		end_y;
	int		end_x;
	double	player_top;
	double	player_bottom;
	double	player_left;
	double	player_right;
}	t_mini_player;

typedef struct s_bool_key
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
	bool	change_map;
}	t_bool_key;

typedef struct s_raycasting
{
	double	ray_pos_x;
	double	ray_pos_y;
	double	plane_x;
	double	plane_y;
}	t_ray;

typedef struct s_game
{
	t_tiny_map		tiny_map;
	t_map			map;
	t_player		player;
	void			*mlx;
	void			*win;
	t_img			img;
	t_mini_map		mini_map;
	t_mini_player	mini_player;
	t_ray			ray;
	t_bool_key		bool_key;
	bool			moved;
}	t_game;

#endif
