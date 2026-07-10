/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_key_press.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 17:47:33 by mvignes           #+#    #+#             */
/*   Updated: 2026/07/10 19:00:04 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	draw_img_key(t_game *game, t_img *img)
{
	int	x;
	int	y;
	int	pixel_y;
	int	pixel_x;
	int	color_pixel;

	pixel_x = 90;
	pixel_y = game->height - img->height;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			int	dest_x = pixel_x + x;
			int	dest_y = pixel_y + y;
			color_pixel = get_pixel_from_texture(img, x, y);
			if (dest_x >= 0 && dest_x < game->width && dest_y >= 0 && dest_y < game->height)
			{
				if (color_pixel != 0xffffff)
					put_pixel(game, dest_x, dest_y, color_pixel);
			}
			x++;
		}
		y++;
	}
	return (OK);
}

static void	display_key(t_game *game, void *img, int x, int y)
{
	(void)x;
	(void)y;
	draw_img_key(game, img);
	// mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

static void	view_key_press_wasdlr(t_game *game, t_bool_key *b)
{
	if (b->w)
		display_key(game, b->key_press[0].img_addr, 0, 0);
	else
		display_key(game, b->key_release[0].img_addr, 0, 0);
	if (b->a)
		display_key(game, b->key_press[1].img_addr, 10, 10);
	else
		display_key(game, b->key_release[1].img_addr, 10, 10);
	if (b->s)
		display_key(game, b->key_press[2].img_addr, 20, 20);
	else
		display_key(game, b->key_release[2].img_addr, 20, 20);
	if (b->d)
		display_key(game, b->key_press[3].img_addr, 30, 30);
	else
		display_key(game, b->key_release[3].img_addr, 30, 30);
	if (b->left)
		display_key(game, b->key_press[4].img_addr, 40, 40);
	else
		display_key(game, b->key_release[4].img_addr, 40, 40);
	if (b->right)
		display_key(game, b->key_press[5].img_addr, 50, 50);
	else
		display_key(game, b->key_release[5].img_addr, 50, 50);
}

static void	view_key_press_other(t_game *game, t_bool_key *b)
{
	if (b->door)
		display_key(game, b->key_press[6].img_addr, 0, 0);
	else
		display_key(game, b->key_release[6].img_addr, 0, 0);
	if (game->start_anim_wall)
		display_key(game, b->key_press[7].img_addr, 10, 10);
	else
		display_key(game, b->key_release[7].img_addr, 10, 10);
	if (b->shift)
		display_key(game, b->key_press[8].img_addr, 20, 20);
	else
		display_key(game, b->key_release[8].img_addr, 20, 20);
	if (b->mouse)
		display_key(game, b->key_press[9].img_addr, 30, 30);
	else
		display_key(game, b->key_release[9].img_addr, 30, 30);
	if (b->view_key_press)
		display_key(game, b->key_press[10].img_addr, 40, 40);
	else
		display_key(game, b->key_release[10].img_addr, 40, 40);
}

bool	view_key_press(t_game *game, t_bool_key *b)
{
	view_key_press_wasdlr(game, b);
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
