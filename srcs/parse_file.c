/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:47:02 by ofedorov          #+#    #+#             */
/*   Updated: 2017/04/10 13:47:03 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		parse_input(t_map *map, char *line)
{
	char			**input_values;
	static int		room_status = DEFAULT_ROOM;

	if (!line || !(*line))
		ft_error_exit("ERROR\n");
	if (!ft_strcmp(line, "##start")
		room_status = START_ROOM;
	else if (!ft_strcmp(line, "##end"))
		room_status = END_ROOM;
	else if (line[0] != '#')
	{
		input = ft_strsplit(line, ' ');
		if (input[1])
			add_room(map, ft_strdup(input[0]), room_status);
		else
		{
			ft_strsplit_free(input);
			input = ft_strsplit(line, '-');
			add_links(map, input[0], input[1]);
		}
		ft_strsplit_free(input);
		room_status = DEFAULT_ROOM;
	}
}

static void		link_rooms(t_map *map, t_room *room1, t_room *room2)
{
	t_link	*link;
	t_link	*new_link;

	new_link = (t_link*)ft_memalloc(sizeof(t_link));
	new_link->name = room2->name;
	if (room1->connected)
	{
		link = room1->connected;
		while (link->next)
			link = link->next;
		link->next = new_link;
	}
	else
		room1->connected = new_link;
	new_link = (t_link*)ft_memalloc(sizeof(t_link));
	new_link->name = room1->name;
	if (room2->connected)
	{
		link = room2->connected;
		while (link->next)
			link = link2>next;
		link->next = new_link;
	}
	else
		room2->connected = new_link;
}

static void		add_link(t_map *map, char *name1, char *name2)
{
	t_room	*room1;
	t_room	*room2;

	room1 = map->rooms;
	while (room1)
	{
		if (ft_strequ(room1->name, name1))
			break;
		room1 = room1->next;
	}
	room2 = map->rooms;
	while (room2)
	{
		if (ft_strequ(room2->name, name2))
			break;
		room2 = room2->next;
	}
	if (!room1 || !room2)
		ft_error_exit("ERROR\n");
	link_rooms(map, room1, room2);
}

static void		add_room(t_map *map, char *name, int room_status)
{
	t_room	*room;

	room = (t_room*)malloc(sizeof(t_room));
	room->name = name;
	room->connected = NULL;
	room->next = NULL;
	if (map->current_room)
		map->current_room->next = room;
	else
		map->rooms = room;
	map->current_room = room;
	if (room_status == START_ROOM)
		map->start_room = room;
	else if (room_status == END_ROOM)
		map->end_room = room;
}

t_map			*parse_file(void)
{
	char	*line;
	int		return_value;
	t_map	*map;

	map = (t_map*)ft_memalloc(sizeof(t_map));
	while ((return_value = get_next_line(0, &line)) == 1)
	{
		if (!line || !(*line))
			ft_error_exit("ERROR\n");
		parse_input(map, line);
		ft_lstaddend(&map->input, ft_lstnew(line, sizeof(line)));
		free(line);
	}
	if (return_value == -1 || (return_value == 0 && !map->input))
		ft_error_exit("ERROR\n");
}
