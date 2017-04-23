/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:16:26 by ofedorov          #+#    #+#             */
/*   Updated: 2017/04/10 15:16:27 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_ants(t_map *map)
{
	int	turn;
	int	current_ant;
	int	last_ant;

	turn = 2 - map->path_length;
	while (turn <= map->ants_count)
	{
		current_ant = turn;
		last_ant = turn + map->path_length - 1;
		while (current_ant <= last_ant)
		{
			if (current_ant > 0 && current_ant <= map->ants_count)
			{
				ft_printf("L%d-%s", current_ant,
					map->rooms[map->path[last_ant - current_ant]]);
				if (current_ant != last_ant && current_ant != map->ants_count)
					ft_putchar("\n");
			}
			ant_in_turn++;
		}
		ft_putchar("\n");
		start_ant++;
	}
}

void		print_result(t_map *map)
{
	t_list	*current_input;

	current_input = map->input;
	while (current_input)
	{
		ft_putendl((char*)current_input->content);
		current_input = current_input->next;
	}
	print_ants(map);
}
