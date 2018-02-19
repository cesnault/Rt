/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 20:34:51 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/02 22:11:50 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"
#include "../../minilibx_macos/mlx.h"
#include <math.h>
#include "gtkgui.h"

int				red_cross(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int				key(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(0);
	return (0);
}

void			init_ray(int x, int y, t_cam *cam, t_generic_param *setting)
{
	t_vect3d	view_plane;
	t_vect3d	origin;

	origin.x = 0;
	origin.y = 0;
	origin.z = -1;
	cam->dir->x = 0;
	cam->dir->y = 0;
	cam->dir->z = 0;
	view_plane.x = x - setting->dim.x / 2;
	view_plane.y = setting->dim.y / 2 - y;
	view_plane.z = setting->dim.x / (2 * tan(15 * M_PI / 180));
	vect_normalize(&view_plane);
	vect_sub3(cam->dir, &view_plane, &origin);
	vect_normalize(cam->dir);
}

void			init_ray_texture(int x, int y, t_cam *cam, t_texture *t)
{
	t_vect3d	view_plane;
	t_vect3d	origin;

	origin.x = 0;
	origin.y = 0;
	origin.z = -1;
	view_plane.x = x - t->dim.x / 2;
	view_plane.y = t->dim.y / 2 - y;
	view_plane.z = t->dim.x / (2 * tan(15 * M_PI / 180));
	vect_normalize(&view_plane);
	vect_sub3(cam->dir, &view_plane, &origin);
	vect_normalize(cam->dir);
	rotation(cam->dir, cam->rot, 1);
	vect_normalize(cam->dir);
}

void			rt_texture(t_rt *glb, t_texture *text)
{
	int	x;
	int	y;

	x = 0;
	while (x < text->dim.x)
	{
		y = 0;
		while (y < text->dim.y)
		{
			init_ray_texture(x, y, glb->cam, text);
			hit_object_texture(glb, x, y, text);
			y++;
		}
		x++;
	}
}
