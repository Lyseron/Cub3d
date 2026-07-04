/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_anim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 22:39:38 by lyaberge          #+#    #+#             */
/*   Updated: 2026/07/03 22:39:38 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	moove_anim(t_anim *anim)
{
	anim->nb_of_loop++;
	if (anim->nb_of_loop >= anim->time_frame)
	{
		anim->nb_of_loop = 0;
		anim->frame_id++;
		if (anim->frame_id >= anim->nb_of_img)
			anim->frame_id = 0;
		return (true);
	}
	return (false);
}
