/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:48:45 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/07 10:52:03 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*---------------------- ENUMERATION -----------------------*/

typedef enum e_status
{
	IS_NULL,
	IS_NORTH,
	IS_SOUTH,
	IS_WEAST,
	IS_EAST,
	IS_DOOR
}	t_status;

/*---------------------- STRUCT ----------------------------*/

typedef struct s_player
{
	char	where_look;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	angle;
	float	speed_player;
}	t_player;

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

typedef struct s_texture
{
	char	*path[6];
	t_img	img[6];
	t_img	animation[7];
	int		convert_color_c;
	int		convert_color_f;
}	t_texture;

typedef struct s_anim
{
	int		nb_of_img;
	int		frame_id;
	t_img	anim_img[10];
	int		time_frame;
	int		nb_of_loop;
}	t_anim;

typedef struct s_point
{
	void	*x;
	void	*y;
}	t_point;

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
	bool		error;
	bool		door;
}	t_map;

typedef struct s_raycasting
{
	double	cos_p;
	double	sin_p;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	int		touch;
	int		wall_touch;
	double	dist_perp;
	double	line_height;
	double	start_y;
	double	end;
	double	fraction;
	double	start_x;
	double	pos_tex;
	int		pos_tex_x;
	int		pos_tex_y;
	double	step;
	t_img	*tex_projet;
	double	ray_pos_x;
	double	ray_pos_y;
	double	plane_x;
	double	plane_y;
}	t_ray;

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
	bool	change_hand;
	bool	shift;
	bool	mouse;
	bool	door;
}	t_bool_key;

typedef struct s_game
{
	long			old_time;
	long			time;
	int				width;
	int				height;
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
	t_texture		textures;
	t_anim			phone;
	t_anim			right_hand;
	t_anim			left_hand;
	bool			close_door;
	bool			open_door;
	bool			anim_is_finish;
	bool			start_anim_wall;
	t_anim			mona;
	t_anim			munch;
}	t_game;

#endif
