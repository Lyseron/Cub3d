/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:23:50 by mvignes           #+#    #+#             */
/*   Updated: 2026/06/09 19:56:13 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

// void	free_all()
// {}

int	print_error(char *str, Map *map, int r)
{
	ft_putstr_fd(str, 2);
	free_data_fd(map);
	return (r);
}

void	free_data_fd(Map *map)
{
	if (map->map_fd)
		close(map->map_fd);
	if (map->texture.NO)
		free(map->texture.NO);
	if (map->texture.SO)
		free(map->texture.SO);
	if (map->texture.WE)
		free(map->texture.WE);
	if (map->texture.EA)
		free(map->texture.EA);
	if (map->Floor)
		free(map->Floor);
	if (map->Ceiling)
		free(map->Ceiling);
	if (map->extract)
		ft_lstclear(&(map->extract), free);
	if (map->grid)
		ft_free_dba(map->grid);
}
