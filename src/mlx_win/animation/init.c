/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 22:31:12 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/03 22:31:12 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	init_img_hand(t_game *game)
{
	if (laod_texture(game, &game->hand,
		"textures/texture_gall/hand/palette_0.xpm") == ERROR)
		return (ERROR);
	if (laod_texture(game, &game->brush,
		"textures/texture_gall/hand/brush_0.xpm") == ERROR)
		return (ERROR);
	return (OK);
}

// int	init_img_door(t_game *game)
// {
// 	game->hand.nb_of_img = 3;
// 	game->hand.time_frame = 2000;
// 	game->hand.frame_id = 0;
// 	game->hand.nb_of_loop = 0;

// 	if (laod_texture(game, &game->hand.anim_img[0],
// 		"textures/texture_gall/door/door_0.xpm") == ERROR)
// 		return (ERROR);
// 	if (laod_texture(game, &game->hand.anim_img[1],
// 		"textures/texture_gall/door/door_1.xpm") == ERROR)
// 		return (ERROR);
// 	if (laod_texture(game, &game->hand.anim_img[2],
// 		"textures/texture_gall/door/door_2.xpm") == ERROR)
// 		return (ERROR);
// 	if (laod_texture(game, &game->hand.anim_img[2],
// 		"textures/texture_gall/door/door_3.xpm") == ERROR)
// 		return (ERROR);
// 	return (OK);
// }

int	init_img_hand2_bis(t_game *game)
{
	if (laod_texture(game, &game->hand_2.anim_img[0],
		"textures/texture_gall/hand2/paper_0.xpm") == ERROR)
		return (ERROR);
	if (laod_texture(game, &game->hand_2.anim_img[1],
		"textures/texture_gall/hand2/paper_1.xpm") == ERROR)
		return (ERROR);
	if (laod_texture(game, &game->hand_2.anim_img[2],
		"textures/texture_gall/hand2/paper_2.xpm") == ERROR)
		return (ERROR);
	if (laod_texture(game, &game->hand_2.anim_img[3],
		"textures/texture_gall/hand2/paper_3.xpm") == ERROR)
		return (ERROR);
	if (laod_texture(game, &game->hand_2.anim_img[4],
		"textures/texture_gall/hand2/paper_4.xpm") == ERROR)
		return (ERROR);
	if (laod_texture(game, &game->hand_2.anim_img[5],
		"textures/texture_gall/hand2/paper_5.xpm") == ERROR)
		return (ERROR);
	if (laod_texture(game, &game->hand_2.anim_img[6],
		"textures/texture_gall/hand2/paper_6.xpm") == ERROR)
		return (ERROR);
	if (laod_texture(game, &game->hand_2.anim_img[7],
		"textures/texture_gall/hand2/paper_7.xpm") == ERROR)
		return (ERROR);
	return (OK);
}

int	init_img_hand2(t_game *game)
{
	game->hand_2.nb_of_img = 8;
	game->hand_2.time_frame = 2000;
	game->hand_2.frame_id = 0;
	game->hand_2.nb_of_loop = 0;

	if (init_img_hand2_bis(game) == ERROR)
		return (ERROR);
	return (OK);
}
