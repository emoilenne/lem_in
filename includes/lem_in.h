/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:34:29 by ofedorov          #+#    #+#             */
/*   Updated: 2017/04/10 13:34:30 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

typedef struct		s_map
{
	int				ants_count;
	int				start;
	int				end;
	int				rooms_count;
	t_list			*rooms_list;
	char			**rooms;
	bool			**links;
	int				*path;
	int				path_length;
	t_list			*input;
}					t_map;

typedef struct		s_solve_info
{
	int				*path;
	int				*min_path;
	int				min_length;
	int				current_length;
}					t_solve_info;

t_map	*parse_file(void);
bool	solve(t_map *map);
void	print_result(t_map *map);
void	free_map(t_map *map);
int		get_index(t_map *map, char *name);

#endif
