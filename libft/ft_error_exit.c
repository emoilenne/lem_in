/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <ofedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:11:15 by ofedorov          #+#    #+#             */
/*   Updated: 2017/09/19 13:34:19 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error_exit(char const *error)
{
	if (!error)
		write(STDERR_FILENO, "Error\n", 6);
	else
		write(STDERR_FILENO, error, ft_strlen(error));
	exit(1);
}
