/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_pts_map_max_pts.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 23:57:05 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/16 23:57:17 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d_pts_map.h"
#include "ft_ori.h"

t_point		*ft_2d_pts_map_max_pts(t_2d_pts_map *tab)
{
	t_point	*pts;
	int		x;
	int		y;

	x = 1;
	y = 0;
	pts = ft_pts_init(tab->map[0][0].x, tab->map[0][0].y);
	while (y < tab->y)
	{
		while (x < tab->x)
		{
			pts->y = ft_max(pts->y, tab->map[y][x].y);
			pts->x = ft_max(pts->x, tab->map[y][x].x);
			x++;
		}
		x = 0;
		y++;
	}
	return (pts);
}
