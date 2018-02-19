/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dint_found_pos_value.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 20:14:51 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/10 22:29:43 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include "ft_point.h"

t_point	*ft_2dint_found_pos_value(int **tab, int y, int x, int to_found)
{
	int c_x;
	int c_y;

	c_x = 0;
	c_y = 0;
	while (c_y < y)
	{
		while (c_x < x)
		{
			if (tab[c_y][c_x] == to_found)
				return (ft_pts_init(c_x, c_y));
			c_x++;
		}
		c_x = 0;
		c_y++;
	}
	return (0);
}
