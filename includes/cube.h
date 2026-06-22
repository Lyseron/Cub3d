/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:38:07 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/22 20:17:00 by mvignes          ###   ########.fr       */
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
# include <X11/keysym.h>
# include <limits.h>
# include <math.h>

# include "parsing.h"
# include "clean_exit.h"
# include "raycasting.h"

// Bool for returns 
# define OK 0
# define ERROR 1

// Window size
// # define HEIGHT 1200
// # define WIDTH 1800
# define SIZE LONG_MAX

// Square size for the mini_map in pixel
# define SIZE_SQUARE 32

// Size of the player in pixel
# define SIZE_PLAYER 6

// Border of the player on each side in map size (SIZE_PLAYER / 2) / SIZE_SQUARE
# define BORDER_PLAYER .2

// The nb of advancement the player mooves in the window
# define SPEED 0.06
# define SPEED_CAM 0.05

# define TURN_RIGTH 1
# define TURN_LEFT -1

# define PI 3.14159265358979323846


# define DEBUG 0

// Keypress Mac
// UP = W ; LEFT = A ; RIGHT = D ; DOWN = S
// # define ESC 53
// # define UP 13
// # define LEFT 0
// # define RIGHT 2
// # define DOWN 1

// // Keypress Linux
// // UP = W ; LEFT = A ; RIGHT = D ; DOWN = S
# define ESC 65307
# define UP 119
# define LEFT 97
# define RIGHT 100
# define DOWN 115
# define SHIFT 0xffe1
# define ARROW_LEFT 0xff51
# define ARROW_RIGHT 0xff53

// Struct
# include "structs.h"

// Prototypes
# include "parsing.h"
# include "clean_exit.h"
# include "init.h"
# include "mini_map.h"
# include "mlx_win.h"

#endif