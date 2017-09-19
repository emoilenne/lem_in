/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <ofedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 09:55:48 by ofedorov          #+#    #+#             */
/*   Updated: 2017/09/19 13:49:36 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	get_index(t_map *map, char *name)
{
	int	i;

	i = 0;
	while (i < map->rooms_count && ft_strcmp(map->rooms[i], name))
		i++;
	if (i == map->rooms_count)
		free_and_exit(map, FAILURE);
	return (i);
}
