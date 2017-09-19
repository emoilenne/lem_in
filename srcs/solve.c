/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <ofedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:15:23 by ofedorov          #+#    #+#             */
/*   Updated: 2017/09/19 13:38:02 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static bool		set_min_path(t_map *map, int *path, int length)
{
	map->path_length = length;
	ft_memcpy(map->path, path, sizeof(int) * length);
	return (true);
}

static bool		not_visited(int *path, int length, int room)
{
	int	index;

	index = 0;
	while (index < length)
	{
		if (path[index] == room)
			return (false);
		index++;
	}
	return (true);
}

static bool		solve_rec(t_map *map, int *path, int length, int current_room)
{
	bool	found_path;
	bool	solved;
	int		next_room;

	if (map->path_length != 0 && length >= map->path_length)
		return (false);
	if (current_room == map->end)
		return (set_min_path(map, path, length));
	found_path = false;
	solved = false;
	next_room = 0;
	while (next_room < map->rooms_count)
	{
		if (map->links[current_room][next_room] &&
			not_visited(path, length, next_room))
		{
			path[length] = next_room;
			found_path = solve_rec(map, path, length + 1, next_room);
			solved = found_path || solved;
		}
		next_room++;
	}
	return (solved);
}

bool			solve(t_map *map)
{
	int		*path;
	bool	solved;

	if (map->rooms_count == 1)
		return (true);
	path = (int*)malloc(sizeof(int) * (map->rooms_count - 1));
	map->path = (int*)malloc(sizeof(int) * (map->rooms_count - 1));
	map->path_length = 0;
	solved = solve_rec(map, path, 0, map->start);
	free(path);
	return (solved);
}
