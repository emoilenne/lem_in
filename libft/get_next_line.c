/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <ofedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:16:04 by ofedorov          #+#    #+#             */
/*   Updated: 2017/09/19 13:35:21 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_getc(int fd)
{
	char		b;
	int			ret;

	ret = read(fd, &b, 1);
	if (ret == 0)
		return (0);
	if (ret < 0)
		return (-1);
	else
		return (b);
}

int			get_next_line(int fd, char **line)
{
	char		*dest;
	char		*buffer;
	char		*end;
	int			c;

	dest = malloc(sizeof(char) * 1024);
	buffer = dest;
	end = buffer + 1023;
	while ((c = ft_getc(fd)) != 0 && c != '\n' && buffer < end)
		*buffer++ = c;
	*buffer = '\0';
	*line = ft_strdup(dest);
	free(dest);
	return ((c == 0 && ft_strlen(*line) == 0) ? 0 : 1);
}
