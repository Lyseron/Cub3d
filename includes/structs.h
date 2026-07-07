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
	t_img	img[5];
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
	double	cos_p;			// direction des rayons FOV				<----- utiliser dans raycasting
	double	sin_p;			// direction des rayons FOV				<----- utiliser dans raycasting
	int		map_x;			// position dans la map en int			<----- utiliser dans raycasting
	int		map_y;			// position dans la map en int			<----- utiliser dans raycasting
	double	delta_dist_x;	// distance rayon						<----- utiliser dans raycasting
	double	delta_dist_y;	// distance rayon						<----- utiliser dans raycasting
	int		step_x;			// sense du rayon Est Ouest				<----- utiliser dans raycasting
	int		step_y;			// sense du rayon Nord Sud				<----- utiliser dans raycasting
	double	side_dist_x;	// distance jusqua la prochaine ligne	<----- utiliser dans raycasting
	double	side_dist_y;	// distance jusqua la prochaine ligne	<----- utiliser dans raycasting
	int		touch;												//	<----- utiliser dans raycasting
	int		wall_touch; //											<----- utiliser dans raycasting
	double	dist_perp;		// distance de l'intersection			<----- utiliser dans raycasting
	double	line_height;	// hauteur mur							<----- utiliser dans raycasting
	double	start_y;//												<----- utiliser dans raycasting
	double	end;//													<----- utiliser dans raycasting
	double	fraction;											//	<----- utiliser dans raycasting mais surtout pour le speed
	double	start_x;											//	<----- utiliser dans raycasting mais surtout pour le speed
	double	pos_tex;		// position du pixel de texture			<----- utiliser dans raycasting
	int		pos_tex_x;		// postion en x du fichier xpm			<----- utiliser dans raycasting
	int		pos_tex_y;		// postion en y du fichier xpm			<----- utiliser dans raycasting
	double	step;			// pas d'avance pour la loc dans xpm	<----- utiliser dans raycasting
	t_img	*tex_projet;	// la texture qui sera projeté			<----- utiliser dans raycasting
	double	ray_pos_x;		// calcul rayon				// <----- j'utilise pas mais lily utilise
	double	ray_pos_y;		// calcul rayon				// <----- j'utilise pas mais lily utilise
	double	plane_x;		// plan a gauche de lecran	// <----- j'utilise pas mais lily utilise
	double	plane_y;		// plan a droite de lecran	// <----- j'utilise pas mais lily utilise
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
	t_anim			hand_2;
	t_img			hand;
	t_img			brush;
}	t_game;

#endif
