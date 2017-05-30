/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <ofedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:53:06 by ofedorov          #+#    #+#             */
/*   Updated: 2017/05/29 17:52:19 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*cdst;
	const unsigned char	*csrc;

	cdst = (unsigned char *)dst;
	csrc = (const unsigned char *)src;
	while (n > 0)
	{
		n--;
		cdst[n] = csrc[n];
	}
	return (dst);
}
