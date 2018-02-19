/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cam2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:34:42 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/02 19:34:45 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>

double	cam_get_dir_x(t_cam *cam)
{
	if (cam && cam->dir)
		return (cam->dir->x);
	return (0.0);
}

double	cam_get_dir_y(t_cam *cam)
{
	if (cam && cam->dir)
		return (cam->dir->y);
	return (0.0);
}

double	cam_get_dir_z(t_cam *cam)
{
	if (cam && cam->dir)
		return (cam->dir->z);
	return (0.0);
}

void	cam_destroy(t_cam *cam)
{
	if (cam)
	{
		vect3d_destroy(cam->origin);
		vect3d_destroy(cam->dir);
	}
}
