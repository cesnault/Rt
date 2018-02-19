/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_mysort_r.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:09:05 by jegloff           #+#    #+#             */
/*   Updated: 2017/02/27 16:11:27 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

static int	ft_cursor_max(int *tab, int len)
{
	int		c;
	int		c_max;

	c = 0;
	c_max = 0;
	while (c < len)
	{
		if (ft_max(tab[c], tab[c_max]) == tab[c])
			c_max = c;
		c++;
	}
	return (c_max);
}

void		ft_int_mysort_r(int *tab_int, int len)
{
	int		c;
	int		c_max;

	c = 0;
	c_max = 0;
	while (c < len)
	{
		c_max = ft_cursor_max(&tab_int[c], len - c) + c;
		if (c_max != c)
			ft_int_swap_pos(tab_int, c, c_max);
		c++;
	}
}
