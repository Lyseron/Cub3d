/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:56:44 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/11 16:46:37 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLEAN_EXIT_H
# define CLEAN_EXIT_H

/* ------------------- free_mlx.c ------------- */
void	free_data_fd(t_map *map);
int		print_error(char *str, t_map *map, int r);
void	free_line_and_gnl(char *line);

#endif
