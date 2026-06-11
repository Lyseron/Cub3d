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
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>

// Bool for returns 
# define OK 0
# define ERROR 1

// Window size
# define HEIGHT 400
# define WIDTH 600

// Square size for the mini_map
# define SIZE_SQUARE 10

// Keypress Mac
// UP = W ; LEFT = A ; RIGHT = D ; DOWN = S
# define ESC 53
# define UP 13
# define LEFT 0
# define RIGHT 2
# define DOWN 1

// // Keypress Linux
// // UP = W ; LEFT = A ; RIGHT = D ; DOWN = S
// # define ESC 65307
// # define UP 119
// # define LEFT 97
// # define RIGHT 100
// # define DOWN 115

// Struct
# include "structs.h"

// Prototypes
# include "parsing.h"
# include "clean_exit.h"
# include "init.h"
# include "mini_map.h"
# include "mlx_win.h"

#endif