/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_mysort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:09:47 by jegloff           #+#    #+#             */
/*   Updated: 2017/02/27 16:10:27 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

static int	ft_cursor_min(int *tab, int len)
{
	int		c;
	int		c_min;

	c = 0;
	c_min = 0;
	while (c < len)
	{
		if (ft_min(tab[c], tab[c_min]) == tab[c])
			c_min = c;
		c++;
	}
	return (c_min);
}

void		ft_int_mysort(int *tab_int, int len)
{
	int		c;
	int		c_min;

	c = 0;
	c_min = 0;
	while (c < len)
	{
		c_min = ft_cursor_min(&tab_int[c], len - c) + c;
		if (c_min != c)
			ft_int_swap_pos(tab_int, c, c_min);
		c++;
	}
}
