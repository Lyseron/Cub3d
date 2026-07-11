/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:38:07 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/11 08:58:35 by mvignes          ###   ########.fr       */
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
# define TIME_FRAME_PHONE 10000
# define TIME_FRAME_HAND 20
# define TIME_FRAME_MONA 10000
# define TIME_FRAME_MUNCH 10000

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

#endif