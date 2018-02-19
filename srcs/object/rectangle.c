/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 20:00:48 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/02 20:03:10 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"
#include <math.h>

static double	solve_rectangle(t_obj *rect, t_cam *cam)
{
	double		a;
	double		b;
	double		c;
	double		d;
	double		t;

	a = rect->p1->y * (rect->p2->z - rect->p3->z) + rect->p2->y *\
	(rect->p3->z - rect->p1->z) + rect->p3->y * (rect->p1->z - rect->p2->z);
	b = rect->p1->z * (rect->p2->x - rect->p3->x) + rect->p2->z *\
	(rect->p3->x - rect->p1->x) + rect->p3->z * (rect->p1->x - rect->p2->x);
	c = rect->p1->x * (rect->p2->y - rect->p3->y) + rect->p2->x *\
	(rect->p3->y - rect->p1->y) + rect->p3->x * (rect->p1->y - rect->p2->y);
	d = (-(rect->p1->x * (rect->p2->y * rect->p3->z - rect->p3->y *\
	rect->p2->z))) - rect->p2->x * (rect->p3->y * rect->p1->z - rect->p1->y *\
	rect->p3->z) - rect->p3->x *\
	(rect->p1->y * rect->p2->z - rect->p2->y * rect->p1->z);
	t = -(a * cam->origin->x + b * cam->origin->y + c *\
	cam->origin->z + d) / (a * cam->dir->x + b *\
	cam->dir->y + c * cam->dir->z);
	return (t);
}

void			hit_rectangle(t_rt *glb, t_obj *rect)
{
	double		dist;
	t_vect3d	tmp;

	tmp = *glb->cam->origin;
	glb->cam->origin = vect_sub(glb->cam->origin, rect->origin);
	rev_rotation(glb->cam->origin, rect->rot, 1);
	rev_rotation(glb->cam->dir, rect->rot, 1);
	dist = solve_rectangle(rect, glb->cam);
	if (dist > 0.001 && dist < 20000)
	{
		tidr_set_double(glb->tmp_obj, rect->id, dist);
		rect->t = dist;
	}
	else
		rect->t = 20000;
	*glb->cam->origin = tmp;
	rotation(glb->cam->dir, rect->rot, 1);
}
