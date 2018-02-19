/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_pts_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:13:20 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/13 17:13:24 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ori.h"
#include "ft_3d_pts.h"

t_3d_pts	*my_3d_pts_init(int x, int y, int z)
{
	t_3d_pts *pts;

	if (!(pts = malloc(sizeof(t_3d_pts))))
	{
		ft_putstr_fd("3d_pts_init: error malloc\n", 2);
		return (0);
	}
	pts->x = x;
	pts->y = y;
	pts->z = z;
	return (pts);
}
