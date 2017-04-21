/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 20:02:46 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/17 14:01:05 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_putstr_fd(char const *s, int fd)
{
	int	i;

	i = 0;
	while (s && *s)
	{
		ft_putchar_fd(*s++, fd);
		i++;
	}
	return (i);
}