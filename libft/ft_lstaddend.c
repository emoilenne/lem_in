/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <ofedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:16:03 by ofedorov          #+#    #+#             */
/*   Updated: 2017/09/19 13:34:25 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*lst;

	if (!alst)
		return ;
	lst = *alst;
	while (lst && lst->next)
		lst = lst->next;
	if (!(*alst))
		*alst = new;
	else
		lst->next = new;
}
