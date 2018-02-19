/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 19:31:32 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/02 20:10:33 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"
#include <math.h>
#include <stdlib.h>

static void		update_intersect(t_obj *t, t_vect3d v)
{
	t->intersect->x = v.x;
	t->intersect->y = v.y;
	t->intersect->z = v.z;
}

static double	solv_core_triangle(t_obj *triangle, t_cam *cam,\
t_vect3d *vec, double *td)
{
	td[0] = vect_dot(triangle->normal, cam->dir);
	if (fabs(td[0]) < 0.00001)
		return (20000.0);
	td[2] = vect_dot(triangle->normal, triangle->p1);
	td[1] = (vect_dot(triangle->normal, cam->origin) + td[2]) / td[0];
	if (td[1] < 0.0)
		return (20000.0);
	vec[0].x = cam->origin->x + cam->dir->x * td[1];
	vec[0].y = cam->origin->y + cam->dir->y * td[1];
	vec[0].z = cam->origin->z + cam->dir->z * td[1];
	return (0.0);
}

static double	solv_triangle(t_obj *triangle, t_cam *cam)
{
	t_vect3d	vec[4];
	double		td[4];

	if (solv_core_triangle(triangle, cam, vec, td) == 20000.0)
		return (20000.0);
	update_intersect(triangle, vec[0]);
	vec[2] = vect_sub2(triangle->p2, triangle->p1);
	vec[3] = vect_sub2(&(vec[0]), triangle->p1);
	vec[1] = vect_cross(&(vec[2]), &(vec[3]));
	if ((td[3] = vect_dot(triangle->normal, &(vec[1]))) < 0.0)
		return (20000.0);
	vec[2] = vect_sub2(triangle->p3, triangle->p2);
	vec[3] = vect_sub2(&(vec[0]), triangle->p2);
	vec[1] = vect_cross(&(vec[2]), &(vec[3]));
	if ((td[3] = vect_dot(triangle->normal, &(vec[1]))) < 0.0)
		return (20000.0);
	vec[2] = vect_sub2(triangle->p1, triangle->p3);
	vec[3] = vect_sub2(&(vec[0]), triangle->p3);
	vec[1] = vect_cross(&(vec[2]), &(vec[3]));
	if ((td[3] = vect_dot(triangle->normal, &(vec[1]))) < 0.0)
		return (20000.0);
	return (td[1]);
}

void			hit_triangle(t_rt *glb, t_obj *triangle)
{
	double		dist;

	calcul_normal(glb, triangle->id);
	dist = solv_triangle(triangle, glb->cam);
	if (dist > 0.000000 && dist < 20000.0)
	{
		tidr_set_double(glb->tmp_obj, triangle->id, dist);
		triangle->t = dist;
	}
	else
		triangle->t = 20000;
}
