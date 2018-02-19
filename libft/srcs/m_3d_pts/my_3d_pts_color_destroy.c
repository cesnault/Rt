/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_3d_pts_color_destroy.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:00:13 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/13 18:00:19 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3d_pts.h"
#include "ft_ori.h"
#include <stdlib.h>

void	my_3d_pts_color_destroy(t_3d_pts_color **pts)
{
	my_3d_pts_destroy(&(pts[0]->pts));
	free(pts[0]);
	pts[0] = 0;
}
