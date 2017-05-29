/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <ofedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:35:24 by ofedorov          #+#    #+#             */
/*   Updated: 2017/05/29 15:05:59 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	free_pointers(t_map *map)
{
	int		index;

	if (map->rooms_list)
		ft_lstdel(&(map->rooms_list), ft_lstdelcontent);
	if (map->input)
		ft_lstdel(&(map->input), ft_lstdelcontent);
	index = 0;
	while (map->rooms && index < map->rooms_count)
	{
		free(map->rooms[index]);
		index++;
	}
	FREE_IFN_NULL(map->rooms);
	index = 0;
	while (map->links && index < map->rooms_count)
	{
		free(map->links[index]);
		index++;
	}
	FREE_IFN_NULL(map->links);
	FREE_IFN_NULL(map->path);
}

void		free_and_exit(t_map *map, int code)
{
	free_pointers(map);
	free(map);
	if (code == FAILURE)
		ft_error_exit("ERROR\n");
}
