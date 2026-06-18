/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:48:45 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/18 16:23:59 by mvignes          ###   ########.fr       */
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
	double	pos_x;	// pos player en x						<----- utiliser dans raycasting
	double	pos_y;	// pos player en y						<----- utiliser dans raycasting
	double	plane;	// angle de rotation					<----- utiliser dans raycasting
	double	dir_x;	//										pas encore utiliser
	double	dir_y;	//										pas encore utiliser
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
	double	ray_pos_x;		// calcul rayon
	double	ray_pos_y;		// calcul rayon
	double	ray_dir_x;		// angle direction rayon
	double	ray_dir_y;		// angle direction rayon
	double	delta_dist_x;	// distance rayon
	double	delta_dist_y;	// distance rayon
	double	plane_x;		// plan a gauche de lecran
	double	plane_y;		// plan a droite de lecran
	int		map_x;			// position dans la map en int
	int		map_y;			// position dans la map en int

	double	wall_x;			// distantce du mur
	int		side;			// si x < y side == 1
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

typedef struct	s_bool_key
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
}	t_bool_key;

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
	t_bool_key		bool_key;
}	t_game;

#endif
