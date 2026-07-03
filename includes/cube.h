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

// Fonction include
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

// Struct
# include "structs.h"

// Prototypes
# include "parsing.h"
# include "clean_exit.h"
# include "init.h"
# include "mini_map.h"
# include "mlx_win.h"
# include "raycasting.h"

typedef int	(*t_mlx_func)();

// Bool for returns 
# define OK 0
# define ERROR 1

// Window size
# define HEIGHT 600
# define WIDTH 800
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
# define SPEED_CAM 0.01

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

# define TURN_RIGTH 1
# define TURN_LEFT -1

# define DEBUG 0

// The color for the mini/tiny maps
# define COLOR_WALL 0x009999
# define COLOR_FLOOR 0x1e1e2e
# define COLOR_PLAYER 11691775
# define COLOR_RAY 11691775
# define COLOR_FRAME 0x009999
# define COLOR_BACKGROUND 0x202020

// Keypress Mac
// UP = W ; LEFT = A ; RIGHT = D ; DOWN = S
# define ESC 53
# define UP 13
# define LEFT 0
# define RIGHT 2
# define DOWN 1
# define ARROW_UP 126
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define MAP_CHANGE 46

// // Keypress Linux
// // UP = W ; LEFT = A ; RIGHT = D ; DOWN = S
// # define ESC 65307
// # define UP 119
// # define LEFT 97
// # define RIGHT 100
// # define DOWN 115
// # define ARROW_UP 65362
// # define ARROW_LEFT 65361
// # define ARROW_RIGHT 65363
// # define ARROW_DOWN 65364
// # define MAP_CHANGE 109

#endif