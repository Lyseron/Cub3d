/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:11:19 by lyaberge          #+#    #+#             */
/*   Updated: 2026/06/22 15:42:24 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// static bool	create_all_image(t_game *game, t_texture *texture)
// {
// 	int	i;

// 	i = 64;
// 	game->img.img_ptr = mlx_new_image(game->mlx, game->width, game->height);
// 	if (!game->img.img_ptr)
// 		return (ERROR);
// 	texture->img_no = mlx_xpm_file_to_image(game->mlx, texture->no, &i, &i);
// 	if (!texture->img_no)
// 	{
// 		printf("WOW\n");
// 		printf("\n\n\nprobleme avec le fichier :%s\n", texture->no);
// 		return (ERROR);
// 	}
// 	texture->img_so = mlx_xpm_file_to_image(game->mlx, texture->so, &i, &i);
// 	if (!texture->img_so)
// 	{
// 		printf("WAW\n");
// 		return (ERROR);
// 	}
// 	texture->img_we = mlx_xpm_file_to_image(game->mlx, texture->we, &i, &i);
// 	if (!texture->img_we)
// 	{
// 		printf("WEW\n");
// 		return (ERROR);
// 	}
// 	texture->img_ea = mlx_xpm_file_to_image(game->mlx, texture->ea, &i, &i);
// 	if (!texture->img_ea)
// 	{
// 		printf("WYW\n");
// 		return (ERROR);
// 	}
// 	return (OK);
// }

int	create_initial_img(t_game *game)
{
	if (!game || !game->mlx || !game->win)
		return (ERROR);
	game->img.img_ptr = mlx_new_image(game->mlx, game->width, game->height);
	if (!game->img.img_ptr)
		return (ERROR);
	// if (create_all_image(game, &game->map.texture))
	// 	return (ERROR);
	game->img.img_addr = mlx_get_data_addr(game->img.img_ptr,
			&game->img.bits_per_pixel, &game->img.size_line, &game->img.endian);
	if (!game->img.img_addr)
		return (ERROR);
	// if (draw_mini_map(game) == ERROR)
	// 	return (ERROR);
	// mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	return (OK);
}
