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
	int	last_ant;
	int	current_ant;

	last_ant = 1;
	while (last_ant <= map->ants_count)
	{
		current_ant = last_ant - map->solution_rooms_count;
		if (current_ant <= 0)
			current_ant = 1;
		while (current_ant <= last_ant)
		{
			ft_printf("L%i-%s", current_ant, map->path[current_ant - last_ant]);
			if (current_ant != last_ant) //TODO change printf ^
				ft_putchar(' ');
		}
		ft_putchar('\n');
		last_ant++;
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
