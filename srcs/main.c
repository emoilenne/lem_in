/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <ofedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:11:29 by ofedorov          #+#    #+#             */
/*   Updated: 2017/05/29 14:55:18 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_map	*map;

	map = parse_file();
	if (solve(map))
		print_result(map);
	else
		ft_error_exit("ERROR\n");
	free_and_exit(map, SUCCESS);
}
