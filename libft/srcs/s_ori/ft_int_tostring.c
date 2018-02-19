/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_tostring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:57:31 by jegloff           #+#    #+#             */
/*   Updated: 2017/02/26 19:01:01 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

void	ft_int_tostring(int *tab_int, int len)
{
	int c;

	c = 0;
	ft_putstr("[");
	while (c < len)
	{
		ft_putnbr(tab_int[c]);
		c++;
		if (c < len)
			ft_putstr(", ");
	}
	ft_putstr("]\n");
}
