/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 19:30:10 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/02 20:00:34 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"
#include <math.h>
#include <stdlib.h>

static double	solv_plan(t_cam *cam, t_obj *p)
{
	double		t;
	t_vect3d	ray_pos;

	ray_pos = vect_sub2(cam->origin, p->origin);
	rev_rotation(&ray_pos, p->rot, 1);
	rev_rotation(cam->dir, p->rot, 1);
	t = ((-1 * p->dir->x * ray_pos.x) + (-1 * p->dir->y *\
ray_pos.y) + (-1 * p->dir->z *\
ray_pos.z)) / (p->dir->x * cam->dir->x + p->dir->y *\
cam->dir->y + p->dir->z * cam->dir->z);
	if (t < 0)
		return (20000);
	return (t);
}

void			hit_plan2(t_rt *glb, t_obj *p, int *id, double *t)
{
	double		t1;

	t1 = solv_plan(glb->cam, p);
	if (20000 > t1 && t1 > 0.001)
	{
		*t = t1;
		p->t = t1;
		*id = p->id;
	}
	else
		p->t = 20000;
	rotation(glb->cam->dir, p->rot, 1);
}

void			hit_plan(t_rt *glb, t_obj *p)
{
	double		t1;

	t1 = solv_plan(glb->cam, p);
	if (t1 < 20000 && t1 > 0.001)
	{
		tidr_set_double(glb->tmp_obj, p->id, t1);
		p->t = t1;
	}
	else
		p->t = 20000;
	rotation(glb->cam->dir, p->rot, 1);
}
