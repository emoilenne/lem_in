/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <ofedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:47:02 by ofedorov          #+#    #+#             */
/*   Updated: 2017/05/27 18:00:15 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static bool		parse_room(t_map *map, char *line, int room_number)
{
	char	**input;
	int		index;

	input = ft_strsplit(line, ' ');
	if (!input[1])
	{
		map->rooms = ft_strlst_toarr(map->rooms_list);
		map->rooms_count = rooms_count;
		map->links = (bool**)ft_memalloc(sizeof(bool*) * rooms_count);
		index = 0;
		while (index < map->rooms_count)
		{
			map->links[index] = (bool*)ft_memalloc(sizeof(bool) * rooms_count);
			index++;
		}
	}
	else if (input[1] && input[2])
		ft_lstaddend(&(map->rooms_list), ft_lstnew(ft_strdup(input[0]),
					sizeof(char*)));
	else
		ft_error_exit("ERROR\n");
	ft_strsplit_free(input);
	return (input[1]) ? true : false;
}

static void		parse_link(t_map *map, char *line)
{
	char	**input;
	int		index1;
	int		index2;

	input = ft_strsplit(line, '-');
	if (!map->rooms || !map->links || !input[1])
		ft_error_exit("ERROR\n");
	index1 = get_index(map, input[0]);
	index2 = get_index(map, input[1]);
	map->links[index1][index2] = true;
	map->links[index2][index1] = true;
}

static void		parse_input(t_map *map, char *line)
{
	static int		room_number = 0;
	static bool		parse_links = false;

	if (ft_strequ(line, "##start"))
		map->start = room_number;
	else if (ft_strequ(line, "##end"))
		map->end = room_number;
	else if (line[0] != '#')
	{
		if (!parse_links)
			parse_links = !parse_room(map, line, room_number);
		if (parse_links)
			parse_link(map, line);
		else
			room_number++;
	}
}

static t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map*)ft_memalloc(sizeof(t_map));
	map->ants_count = -1;
	map->start = -1;
	map->end = -1;
	map->rooms_count = -1;
	map->rooms_list = NULL;
	map->rooms = NULL;
	map->links = NULL;
	map->path = NULL;
	map->path_length = -1;
	map->input = NULL;
	return (map);
}

t_map			*parse_file(void)
{
	char	*line;
	int		return_value;
	t_map	*map;

	map = init_map();
	if ((return_value = get_next_line(0, &line)) == 1)
	{
		map->ants_count = ft_atoi(line);
		ft_lstaddend(&(map->input), ft_lstnew(line, ft_strlen(line) + 1));
		free(line);
		while ((return_value = get_next_line(0, &line)) == 1)
		{
			if (!line || !(*line))
				ft_error_exit("ERROR\n");
			ft_lstaddend(&(map->input), ft_lstnew(line, ft_strlen(line) + 1));
			parse_input(map, line);
			free(line);
		}
	}
	if (return_value == -1 || (return_value == 0 && !(map->input)) ||
		map->rooms_count == -1 || map->start == -1 || map->end == -1 ||
		map->start >= map->rooms_count || map->end >= map->rooms_count ||
		map->ants_count < 1 || map->start == map->end)
		ft_error_exit("ERROR\n");
	return (map);
}
