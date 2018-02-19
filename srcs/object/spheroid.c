/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheroide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:21:24 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/02 20:07:08 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"
#include <math.h>
#include <stdlib.h>

static void		calc_intersection(t_obj *ball, t_cam *cam, double t)
{
	ball->intersect->x = cam->origin->x + cam->dir->x * t;
	ball->intersect->y = cam->origin->y + cam->dir->y * t;
	ball->intersect->z = cam->origin->z + cam->dir->z * t;
}

static double	solv_core_spheroid(t_discr solv)
{
	if (solv.delta < 0)
		return (20000);
	if (solv.delta == 0)
		return ((-1 * solv.b) / (2 * solv.a));
	else
	{
		solv.t = (-1 * solv.b - sqrt(solv.delta)) / (2 * solv.a);
		solv.c = (-1 * solv.b + sqrt(solv.delta)) / (2 * solv.a);
	}
	if ((solv.t < solv.c && solv.c > 0.001) || (solv.t > 0.001 && solv.c < 0))
		return (solv.t);
	return (solv.c);
}

static double	solv_spheroid(t_cam *cam, t_obj *ball)
{
	t_discr		solv;
	t_vect3d	ray_pos;
	float		a;
	float		b;
	float		c;

	a = ball->p1->x;
	b = ball->p1->y;
	c = ball->p1->z;
	ray_pos = vect_sub2(cam->origin, ball->origin);
	rev_rotation(&ray_pos, ball->rot, 1);
	rev_rotation(cam->dir, ball->rot, 1);
	solv.a = (cam->dir->x * cam->dir->x) / (a * a) +\
	(cam->dir->y * cam->dir->y) / (b * b) +\
	(cam->dir->z * cam->dir->z) / (c * c);
	solv.b = ((2.0 * ray_pos.x * cam->dir->x) / (a * a)) +\
	((2.0 * ray_pos.y * cam->dir->y) / (b * b)) +\
	((2.0 * ray_pos.z * cam->dir->z) / (c * c));
	solv.c = ((ray_pos.x * ray_pos.x) / (a * a)) +\
	((ray_pos.y * ray_pos.y) / (b * b)) +\
	((ray_pos.z * ray_pos.z) / (c * c)) - 1.0;
	solv.delta = (solv.b * solv.b) - (4 * solv.a * solv.c);
	return (solv_core_spheroid(solv));
}

void			hit_spheroid(t_rt *glb, t_obj *ball)
{
	double		t2;

	t2 = solv_spheroid(glb->cam, ball);
	if (t2 < 20000 && t2 > 0.001)
	{
		calc_intersection(ball, glb->cam, t2);
		tidr_set_double(glb->tmp_obj, ball->id, t2);
		ball->t = t2;
	}
	else
		ball->t = 20000;
	rotation(glb->cam->dir, ball->rot, 1);
}
