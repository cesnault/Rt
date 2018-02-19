/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 19:07:07 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/09 20:05:52 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"
#include <math.h>
#include <stdlib.h>

static double	solv_ball(t_cam *cam, t_obj *ball)
{
	t_discr		solv;
	t_vect3d	ray_pos;

	ray_pos = vect_sub2(cam->origin, ball->origin);
	rev_rotation(&ray_pos, ball->rot, 1);
	rev_rotation(cam->dir, ball->rot, 1);
	solv.a = pow(cam->dir->x, 2) + pow(cam->dir->y, 2) + pow(cam->dir->z, 2);
	solv.b = 2 * ray_pos.x * cam->dir->x + 2 * ray_pos.y *\
	cam->dir->y + 2 * ray_pos.z * cam->dir->z;
	solv.c = pow(ray_pos.x, 2) + pow(ray_pos.y, 2) +\
	pow(ray_pos.z, 2) - (ball->rey * ball->rey);
	solv.delta = (solv.b * solv.b) - (4 * solv.a * solv.c);
	if (solv.delta < 0)
		return (20000);
	if (solv.delta == 0)
		return ((-1 * solv.b) / (2 * solv.a));
	else
	{
		solv.t = (-1 * solv.b - sqrt(solv.delta)) / (2 * solv.a);
		solv.c = (-1 * solv.b + sqrt(solv.delta)) / (2 * solv.a);
	}
	if ((solv.t < solv.c && solv.t > 0.001) || (solv.t > 0.001 && solv.c < 0))
		return (solv.t);
	return (solv.c);
}

void			hit_ball(t_rt *glb, t_obj *ball)
{
	double		t2;

	t2 = solv_ball(glb->cam, ball);
	if (t2 < 20000 && t2 > 0.001)
	{
		tidr_set_double(glb->tmp_obj, ball->id, t2);
		ball->t = t2;
	}
	else
		ball->t = 20000;
	rotation(glb->cam->dir, ball->rot, 1);
}
