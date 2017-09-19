/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <ofedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 12:03:06 by ofedorov          #+#    #+#             */
/*   Updated: 2017/09/19 13:34:39 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*fresh;
	unsigned char	*cb;

	fresh = malloc(size);
	if (fresh == NULL)
		return (NULL);
	cb = (unsigned char *)fresh;
	while (size-- > 0)
		*(cb + size) = (unsigned char)0;
	return (fresh);
}
