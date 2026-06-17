/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:48:45 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/17 17:37:26 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../libft/libft.h"
# include <stdbool.h>

/*------------------------------------------------------------------ STRUCT ---------------------------------------------------------*/

typedef int (*mlx_func_t)();

typedef struct s_player
{
	char	where_look;
	double	pos_x;
	double	pos_y;
	double	plane;
	double	dir_x;
	double	dir_y;
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


typedef struct s_raycasting
{
	double	ray_pos_x;
	double	ray_pos_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	plane_x;
	double	plane_y;
	int		map_x;
	int		map_y;
	double	dir_x;
	double	dir_y;

	double	wall_x;
	int		side;
	int		step_x;
	int		step_y;
	double	line_height;
	double	end;
	bool	hit_a_wall;
}	t_ray;


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

	t_ray		ray;
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
	int		win_x;
	int		win_y;
	int		start_y;
	int		start_x;
	int		end_y;
	int		end_x;
	int		map_case_left;
	int		map_case_right;
	int		map_case_top;
	int		map_case_bottom;
}	t_mini_map;

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
	int		player_pixel_y;
	int		player_pixel_x;
}	t_mini_player;

typedef struct s_game
{
	t_map			map;
	t_player		player;
	void			*mlx;
	void			*win;
	t_img			img;
	t_mini_map		mini_map;
	t_mini_player	mini_player;
	t_ray			ray;
}	t_game;

#endif
