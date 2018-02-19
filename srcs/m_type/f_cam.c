/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cam.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 16:47:37 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/06 16:47:40 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>

t_cam	*cam_init(void)
{
	t_cam *cam;

	if (!(cam = malloc(sizeof(t_cam))))
		malloc_fail("cam_init");
	cam->origin = 0;
	cam->dir = 0;
	cam->rot = 0;
	return (cam);
}

double	cam_get_ori_x(t_cam *cam)
{
	if (cam && cam->origin)
		return (cam->origin->x);
	return (0.0);
}

double	cam_get_ori_y(t_cam *cam)
{
	if (cam && cam->origin)
		return (cam->origin->y);
	return (0.0);
}

double	cam_get_ori_z(t_cam *cam)
{
	if (cam && cam->origin)
		return (cam->origin->z);
	return (0.0);
}
