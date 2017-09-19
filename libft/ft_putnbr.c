/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <ofedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 19:53:50 by ofedorov          #+#    #+#             */
/*   Updated: 2017/09/19 13:39:01 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n < -9)
			ft_putnbr(-(n / 10));
		ft_putchar('0' - (n - (n / 10) * 10));
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar('0' + n % 10);
	}
	else
		ft_putchar('0' + n);
}
