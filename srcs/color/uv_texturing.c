/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_texturing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 23:28:51 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/12 23:32:21 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "math.h"

void		uv_cylinder3(t_obj *obj, float *u, float *v)
{
	t_vect3d	d;

	vect_sub3(&d, obj->intersect, obj->origin);
	d = vector_norm2(d);
	*u = 0.5 + atan2(d.z, d.x) / 3.14 * 0.5;
	*v = d.y / (0.2);
	*v = *v - floor(*v);
}

void		uv_cylinder2(t_obj *obj, t_cam *cam, float *u, float *v)
{
	t_vect3d tmp;

	tmp = vect_sub2(obj->origin, cam->dir);
	vect_normalize(&tmp);
	*u = 0.5 + atan2(tmp.z, tmp.x) / 3.14 * 0.5;
	*v = tmp.y / 3.14;
	*u = *u * (float)(((t_texture *)(obj->texture->obj))->dim.x);
	*v = *v * (float)(((t_texture *)(obj->texture->obj))->dim.y);
	*v = *v - floor(*v);
}

void		uv_plane(t_obj *obj, float *u, float *v)
{
	t_vect3d	d;

	d = vect_sub2(obj->intersect, obj->origin);
	vect_normalize(&d);
	*u = 0.5 + atan2(d.z, d.x) / M_PI * 0.5;
	*v = 0.5 - asin(d.y) / M_PI;
}

void		main_uv_texture(t_obj *obj, float *u, float *v)
{
	*u = 0.0f;
	*v = 0.0f;
	if (obj->type == SPHERE)
		uv_sphere(obj, u, v);
	else if (obj->type == CYLINDER || obj->type == CONE)
		uv_cylinder(obj, u, v);
	else if (obj->type == PLAN || obj->type == TRIANGLE)
		uv_plane(obj, u, v);
	else
		uv_sphere(obj, u, v);
}
