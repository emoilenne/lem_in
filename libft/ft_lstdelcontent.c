/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelcontent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <ofedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:40:46 by ofedorov          #+#    #+#             */
/*   Updated: 2017/09/19 13:34:33 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelcontent(void *content, size_t content_size)
{
	unsigned char	*cb;

	cb = (unsigned char *)content;
	while (content_size-- > 0)
		*(cb + content_size) = (unsigned char)0;
	free(content);
}
