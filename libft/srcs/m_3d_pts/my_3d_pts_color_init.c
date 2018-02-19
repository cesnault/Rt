/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_3d_pts_color_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 23:57:55 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/16 23:58:07 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3d_pts.h"
#include "ft_ori.h"
#include <stdlib.h>

t_3d_pts_color		*my_3d_pts_color_init(int x, int y, int z, int color)
{
	t_3d_pts_color	*pts;

	if (!(pts = malloc(sizeof(t_3d_pts_color))))
	{
		ft_putstr_fd("t_3d_pts_color_init: error malloc\n", 2);
		return (0);
	}
	if (!(pts->pts = my_3d_pts_init(x, y, z)))
	{
		ft_putstr_fd("t_3d_pts_color_init: error alloc pts\n", 2);
		return (0);
	}
	pts->color = color;
	return (pts);
}
