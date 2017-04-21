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

# define DEFAULT_ROOM 0
# define START_ROOM 1
# define END_ROOM 2

typedef struct	s_link
{
	char			*name;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	char			*name;
	t_link			*connected;
	struct s_room	*next;
}					t_room;

typedef struct		s_map
{
	int				ants_count;
	t_room			*rooms;
	t_room			*start_room;
	t_room			*current_room;
	t_room			*end_room;
}					t_map;



#endif
