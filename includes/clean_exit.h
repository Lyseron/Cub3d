/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:56:44 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/09 16:56:44 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_EXIT_H
# define CLEAN_EXIT_H

/* ------------------- clean_mlx.c ------------- */
int		exit_game(t_game *game);

/* ------------------- free_mlx.c ------------- */
void	free_data_fd(t_map *map);
void	free_all_img(t_game *game);
int		print_error(char *str, t_map *map, int r);
void	free_line_and_gnl(char *line);

#endif
