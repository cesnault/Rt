/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:57:18 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/02 19:57:22 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"
#include <math.h>
#include <stdlib.h>

static double	solv_disk(t_cam *cam, t_obj *p)
{
	double		t;
	t_vect3d	ray_pos;
	t_vect3d	intersect;
	double		distance;

	ray_pos = vect_sub2(cam->origin, p->origin);
	rev_rotation(&ray_pos, p->rot, 1);
	rev_rotation(cam->dir, p->rot, 1);
	t = ((-1 * p->dir->x * ray_pos.x) + (-1 * p->dir->y *\
ray_pos.y) + (-1 * p->dir->z *\
ray_pos.z)) / (p->dir->x * cam->dir->x + p->dir->y *\
cam->dir->y + p->dir->z * cam->dir->z);
	if (t < 0)
		return (20000);
	intersect.x = cam->origin->x + cam->dir->x * t;
	intersect.y = cam->origin->y + cam->dir->y * t;
	intersect.z = cam->origin->z + cam->dir->z * t;
	distance = sqrt(pow(intersect.x - p->origin->x, 2) +\
pow(intersect.y - p->origin->y, 2) + pow(intersect.z - p->origin->z, 2));
	if (distance > p->rey)
		return (20000);
	return (t);
}

void			hit_disk(t_rt *glb, t_obj *p)
{
	double		t1;

	t1 = solv_disk(glb->cam, p);
	if (t1 < 20000 && t1 > 0.001)
	{
		tidr_set_double(glb->tmp_obj, p->id, t1);
		p->t = t1;
	}
	else
		p->t = 20000;
	rotation(glb->cam->dir, p->rot, 1);
}
