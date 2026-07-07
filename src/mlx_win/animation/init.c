/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 22:31:12 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/07 13:32:22 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	init_img_left_hand(t_game *game)
{
	game->left_hand.nb_of_img = 4;
	game->left_hand.time_frame = TIME_FRAME_HAND;
	game->left_hand.frame_id = 0;
	game->left_hand.nb_of_loop = 0;
	if (laod_texture(game, &game->left_hand.anim_img[0],
			"textures/texture_gall/hands/palette_0.xpm") == ERROR)
		return (ERROR);
	if (laod_texture(game, &game->left_hand.anim_img[1],
			"textures/texture_gall/hands/palette_1.xpm") == ERROR)
		return (ERROR);
	if (laod_texture(game, &game->left_hand.anim_img[2],
			"textures/texture_gall/hands/palette_2.xpm") == ERROR)
		return (ERROR);
	if (laod_texture(game, &game->left_hand.anim_img[3],
			"textures/texture_gall/hands/palette_3.xpm") == ERROR)
		return (ERROR);
	return (OK);
}

int	init_img_right_hand(t_game *game)
{
	game->right_hand.nb_of_img = 4;
	game->right_hand.time_frame = TIME_FRAME_HAND;
	game->right_hand.frame_id = 0;
	game->right_hand.nb_of_loop = 0;
	if (laod_texture(game, &game->right_hand.anim_img[0],
			"textures/texture_gall/hands/brush_0.xpm") == ERROR)
		return (ERROR);
	if (laod_texture(game, &game->right_hand.anim_img[1],
			"textures/texture_gall/hands/brush_1.xpm") == ERROR)
		return (ERROR);
	if (laod_texture(game, &game->right_hand.anim_img[2],
			"textures/texture_gall/hands/brush_2.xpm") == ERROR)
		return (ERROR);
	if (laod_texture(game, &game->right_hand.anim_img[3],
			"textures/texture_gall/hands/brush_3.xpm") == ERROR)
		return (ERROR);
	return (OK);
}

static int	init_bis(t_game *game)
{
	if (laod_texture(game, &game->phone.anim_img[4],
			"textures/texture_gall/phone/paper_4.xpm") == ERROR)
		return (ERROR);
	if (laod_texture(game, &game->phone.anim_img[5],
			"textures/texture_gall/phone/paper_5.xpm") == ERROR)
		return (ERROR);
	if (laod_texture(game, &game->phone.anim_img[6],
			"textures/texture_gall/phone/paper_6.xpm") == ERROR)
		return (ERROR);
	if (laod_texture(game, &game->phone.anim_img[7],
			"textures/texture_gall/phone/paper_7.xpm") == ERROR)
		return (ERROR);
	if (laod_texture(game, &game->phone.anim_img[8],
			"textures/texture_gall/phone/paper_8.xpm") == ERROR)
		return (ERROR);
	return (OK);
}

int	init_img_phone_textures(t_game *game)
{
	if (laod_texture(game, &game->phone.anim_img[0],
			"textures/texture_gall/phone/paper_0.xpm") == ERROR)
		return (ERROR);
	if (laod_texture(game, &game->phone.anim_img[1],
			"textures/texture_gall/phone/paper_1.xpm") == ERROR)
		return (ERROR);
	if (laod_texture(game, &game->phone.anim_img[2],
			"textures/texture_gall/phone/paper_2.xpm") == ERROR)
		return (ERROR);
	if (laod_texture(game, &game->phone.anim_img[3],
			"textures/texture_gall/phone/paper_3.xpm") == ERROR)
		return (ERROR);
	if (init_bis(game) == ERROR)
		return (ERROR);
	return (OK);
}

int	init_img_phone(t_game *game)
{
	game->phone.nb_of_img = 9;
	game->phone.time_frame = TIME_FRAME_PHONE;
	game->phone.frame_id = 0;
	game->phone.nb_of_loop = 0;
	if (init_img_phone_textures(game) == ERROR)
		return (ERROR);
	return (OK);
}
