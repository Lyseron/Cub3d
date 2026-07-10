/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:38:07 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/10 19:03:25 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

// Function include
# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <math.h>
# include <sys/time.h>
# include <termios.h>
# include <X11/keysym.h>

// Struct
# include "structs.h"

// Prototypes
# include "parsing.h"
# include "clean_exit.h"
# include "mlx_win.h"

typedef int	(*t_mlx_func)();

// Bool for returns 
# define OK 0
# define ERROR 1

// Window size
# define SIZE LONG_MAX

// Square size for the mini_map in pixel
# define SIZE_SQUARE 10

// Size of the player in pixel
# define SIZE_PLAYER 6

// Border of the player on each side in map size (SIZE_PLAYER / 2) / SIZE_SQUARE
# define BORDER_PLAYER 0.3

// The nb of advancement the player mooves in the window
# define SPEED 1

// The steps size to avance the ray in the map bound
# define RAY_STEP_SIZE 0.1

// The nb of advancement the player mooves in the window
# define SPEED_CAM 0.02

// The marge between the top right and the map
# define MARGE 25

// How many case from the player the tiny map shows
# define CASE_FROM_PLAYER 8

// For the angle of the camera
# define PI 3.14159265358979323846

// Define the frame size around the mini/tiny map in pixel
# define FRAME_SIZE 10

// The nb of advancement the player mooves in the window
# define SPEED_SPRIT 1.5

// How sensitive the mouse is
# define SENSITIVITY_MOUSE 0.001

// Sense in which one turns one’s head
# define TURN_RIGTH 1
# define TURN_LEFT -1

// Information about the door
# define DOOR_RANGE 1
# define DOOR_PATH "./textures/texture_gall/door/door_lily.xpm"

// For the animation to define how many loop before a frame change
# define TIME_FRAME_PHONE 20000
# define TIME_FRAME_HAND 50
# define TIME_FRAME_MONA 20000
# define TIME_FRAME_MUNCH 20000

// The color for the mini/tiny maps
# define COLOR_WALL 0x009999
# define COLOR_FLOOR 0x1e1e2e
# define COLOR_PLAYER 0xd745ff
# define COLOR_RAY 0xd745ff
# define COLOR_FRAME 0x009999
# define COLOR_BACKGROUND 0x202020
# define COLOR_DOOR 0xa08a06

# define GOOD_NORTH "./textures/texture_gall/munch/wall_anim_0.xpm"
# define GOOD_SOUTH "./textures/texture_gall/wall_mona/wall_mona_0.xpm"

# define W_PRESS "./textures/key/xpm/key_w.xpm"
# define A_PRESS "./textures/key/xpm/key_a.xpm"
# define S_PRESS "./textures/key/xpm/key_s.xpm"
# define D_PRESS "./textures/key/xpm/key_d.xpm"
# define ARROW_LEFT_PRESS "./textures/key/xpm/key_arrow_left.xpm"
# define ARROW_RIGHT_PRESS "./textures/key/xpm/key_arrow_right.xpm"
# define O_PRESS "./textures/key/xpm/key_o.xpm"
# define P_PRESS "./textures/key/xpm/key_p.xpm"
# define SHIFT_PRESS "./textures/key/xpm/key_shift.xpm"
# define CTRL_PRESS "./textures/key/xpm/key_ctrl.xpm"
# define ALT_PRESS "./textures/key/xpm/key_alt.xpm"

# define W_RELEASE "./textures/key/xpm/key_w_release.xpm"
# define A_RELEASE "./textures/key/xpm/key_a_release.xpm"
# define S_RELEASE "./textures/key/xpm/key_s_release.xpm"
# define D_RELEASE "./textures/key/xpm/key_d_release.xpm"
# define ARROW_LEFT_RELEASE "./textures/key/xpm/key_arrow_left_release.xpm"
# define ARROW_RIGHT_RELEASE "./textures/key/xpm/key_arrow_right_release.xpm"
# define O_RELEASE "./textures/key/xpm/key_o_release.xpm"
# define P_RELEASE "./textures/key/xpm/key_p_release.xpm"
# define SHIFT_RELEASE "./textures/key/xpm/key_shift_release.xpm"
# define CTRL_RELEASE "./textures/key/xpm/key_ctrl_release.xpm"
# define ALT_RELEASE "./textures/key/xpm/key_alt_release.xpm"

// Keypress Mac
# ifdef MAC

// ECHAP
# define ESC 53
// UP -> W 
# define UP 13
// LEFT -> A 
# define LEFT 0
// RIGHT -> D
# define RIGHT 2
// DOWN -> S
# define DOWN 1

// ARROWS
# define ARROW_UP 126
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125

// MAP_CHANGE  -> M
# define MAP_CHANGE 46
// START_ANIM_WALL -> P
# define START_ANIM_WALL 35
// HAND_CHANGE && DOOR -> O
# define HAND_CHANGE 14
# define DOOR 14
// SHIFT RIGHT
# define SHIFT 257
// CTRL
# define MOUSE 256
// ALT
# define ALT 261

# endif

// Keypress Linux
# ifdef LINUX

// ECHAP
# define ESC 65307
// UP -> W 
# define UP 119
// LEFT -> A 
# define LEFT 97
// RIGHT -> D
# define RIGHT 100
// DOWN -> S
# define DOWN 115

// ARROWS
# define ARROW_UP 65362
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364

// MAP_CHANGE  -> M
# define MAP_CHANGE 109
// START_ANIM_WALL -> P
# define START_ANIM_WALL 112
// HAND_CHANGE && DOOR -> O
# define HAND_CHANGE 111
# define DOOR 111
// SHIFT RIGHT
# define SHIFT XK_Shift_L
// CTRL
# define MOUSE XK_Control_L
// ALT
# define VIEW_KEY_PRESS XK_Alt_L

#endif

#endif