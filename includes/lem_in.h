/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <ofedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:34:29 by ofedorov          #+#    #+#             */
/*   Updated: 2017/05/29 14:56:34 by ofedorov         ###   ########.fr       */
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

t_map				*parse_file(void);
bool				solve(t_map *map);
void				print_result(t_map *map);
void				free_and_exit(t_map *map, int code);
int					get_index(t_map *map, char *name);

#endif
