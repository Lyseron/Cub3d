/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_key_press.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vignesmattheu <vignesmattheu@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 17:47:33 by mvignes           #+#    #+#             */
/*   Updated: 2026/07/13 09:11:24 by vignesmatth      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	draw_img_key(t_game *game, t_img *img, int offset_x, int offset_y)
{
	int	x;
	int	y;
	int	color_pixel;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			color_pixel = get_pixel_from_texture(img, x, y);
			if (offset_x + x >= 0 && offset_x + x < game->width
				&& offset_y + y >= 0 && offset_y + y < game->height)
				put_pixel(game, offset_x + x, offset_y + y, color_pixel);
			x++;
		}
		y++;
	}
	return (OK);
}

static void	display_key(t_game *game, t_img *img, int x, int y)
{
	draw_img_key(game, img, x, y);
}

static void	view_key_press_wasdlr(t_game *game, t_bool_key *b)
{
	if (b->left)
		display_key(game, &b->key_press[4], game->width - 280, game->height / 40);
	else
		display_key(game, &b->key_release[4], game->width - 260, game->height / 40);
	if (b->w)
		display_key(game, &b->key_press[0], game->width - 190, game->height / 100);
	else
		display_key(game, &b->key_release[0], game->width - 190, game->height / 40);
	if (b->right)
		display_key(game, &b->key_press[5], game->width - 100, game->height / 40);
	else
		display_key(game, &b->key_release[5], game->width - 120, game->height / 40);
	if (b->a)
		display_key(game, &b->key_press[1], game->width - 280, game->height / 40 + 70);
	else
		display_key(game, &b->key_release[1], game->width - 260, game->height / 40 + 70);
	if (b->s)
		display_key(game, &b->key_press[2], game->width - 190, game->height / 40 + 80);
	else
		display_key(game, &b->key_release[2], game->width - 190, game->height / 40 + 70);
	if (b->d)
		display_key(game, &b->key_press[3], game->width - 100, game->height / 40 + 70);
	else
		display_key(game, &b->key_release[3], game->width - 120, game->height / 40 + 70);
}

static void	view_key_press_other(t_game *game, t_bool_key *b)
{
	if (b->door)
		display_key(game, &b->key_press[6], game->width - 260, game->height / 40 + 180);
	else
		display_key(game, &b->key_release[6], game->width - 260, game->height / 40 + 180);
	if (b->view_key_press)
		display_key(game, &b->key_press[10], game->width - 190, game->height / 40 + 180);
	else
		display_key(game, &b->key_release[10], game->width - 190, game->height / 40 + 180);
	if (game->start_anim_wall)
		display_key(game, &b->key_press[7], game->width - 120, game->height / 40 + 180);
	else
		display_key(game, &b->key_release[7], game->width - 120, game->height / 40 + 180);
	if (b->shift)
		display_key(game, &b->key_press[8], game->width - 225, game->height / 40 + 250);
	else
		display_key(game, &b->key_release[8], game->width - 225, game->height / 40 + 250);
	if (b->mouse)
		display_key(game, &b->key_press[9], game->width - 155, game->height / 40 + 250);
	else
		display_key(game, &b->key_release[9], game->width - 155, game->height / 40 + 250);
}

bool	view_key_press(t_game *game, t_bool_key *b)
{
	view_key_press_wasdlr(game, b);
	view_key_press_other(game, b);
	return (false);
}

int	init_img_key_release(t_game *game, t_bool_key *b)
{
	if (laod_texture(game, &b->key_release[0], W_RELEASE) == ERROR)
		return (ERROR);
	if (laod_texture(game, &b->key_release[1], A_RELEASE) == ERROR)
		return (ERROR);
	if (laod_texture(game, &b->key_release[2], S_RELEASE) == ERROR)
		return (ERROR);
	if (laod_texture(game, &b->key_release[3], D_RELEASE) == ERROR)
		return (ERROR);
	if (laod_texture(game, &b->key_release[4], ARROW_LEFT_RELEASE) == ERROR)
		return (ERROR);
	if (laod_texture(game, &b->key_release[5], ARROW_RIGHT_RELEASE) == ERROR)
		return (ERROR);
	if (laod_texture(game, &b->key_release[6], O_RELEASE) == ERROR)
		return (ERROR);
	if (laod_texture(game, &b->key_release[7], P_RELEASE) == ERROR)
		return (ERROR);
	if (laod_texture(game, &b->key_release[8], SHIFT_RELEASE) == ERROR)
		return (ERROR);
	if (laod_texture(game, &b->key_release[9], CTRL_RELEASE) == ERROR)
		return (ERROR);
	if (laod_texture(game, &b->key_release[10], ALT_RELEASE) == ERROR)
		return (ERROR);
	return (OK);
}

int	init_img_key_press(t_game *game, t_bool_key *b)
{
	if (laod_texture(game, &b->key_press[0], W_PRESS) == ERROR)
		return (ERROR);
	if (laod_texture(game, &b->key_press[1], A_PRESS) == ERROR)
		return (ERROR);
	if (laod_texture(game, &b->key_press[2], S_PRESS) == ERROR)
		return (ERROR);
	if (laod_texture(game, &b->key_press[3], D_PRESS) == ERROR)
		return (ERROR);
	if (laod_texture(game, &b->key_press[4], ARROW_LEFT_PRESS) == ERROR)
		return (ERROR);
	if (laod_texture(game, &b->key_press[5], ARROW_RIGHT_PRESS) == ERROR)
		return (ERROR);
	if (laod_texture(game, &b->key_press[6], O_PRESS) == ERROR)
		return (ERROR);
	if (laod_texture(game, &b->key_press[7], P_PRESS) == ERROR)
		return (ERROR);
	if (laod_texture(game, &b->key_press[8], SHIFT_PRESS) == ERROR)
		return (ERROR);
	if (laod_texture(game, &b->key_press[9], CTRL_PRESS) == ERROR)
		return (ERROR);
	if (laod_texture(game, &b->key_press[10], ALT_PRESS) == ERROR)
		return (ERROR);
	return (OK);
}
