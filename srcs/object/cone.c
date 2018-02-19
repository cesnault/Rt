/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 19:27:20 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/22 01:49:38 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"
#include <math.h>

static double	solv_cone(t_cam *cam, t_obj *cone)
{
	t_discr		solv;
	t_vect3d	ray_pos;

	ray_pos = vect_sub2(cam->origin, cone->origin);
	rev_rotation(&ray_pos, cone->rot, 1);
	rev_rotation(cam->dir, cone->rot, 1);
	solv.a = pow(cam->dir->x, 2) + pow(cam->dir->z, 2) - pow(cam->dir->y, 2);
	solv.b = 2 * ray_pos.x * cam->dir->x + 2 * ray_pos.z * cam->dir->z - 2 *\
ray_pos.y * cam->dir->y;
	solv.c = pow(ray_pos.x, 2) + pow(ray_pos.z, 2) - pow(ray_pos.y, 2);
	solv.delta = solv.b * solv.b - (4 * solv.a * solv.c);
	if (solv.delta == 0)
		return (20000);
	if (solv.delta == 0)
		solv.t = (-1 * solv.b) / (2 * solv.a);
	else
	{
		solv.t = (-1 * solv.b - sqrt(solv.delta)) / (2 * solv.a);
		solv.c = (-1 * solv.b + sqrt(solv.delta)) / (2 * solv.a);
	}
	if ((solv.t < solv.c && solv.t > 0.001) || (solv.t > 0.001 && solv.c < 0))
		return (solv.t);
	return (solv.c);
}

void			hit_cone(t_rt *glb, t_obj *cone)
{
	double		t1;

	t1 = solv_cone(glb->cam, cone);
	if (t1 < 20000 && t1 > 0.001)
	{
		tidr_set_double(glb->tmp_obj, cone->id, t1);
		cone->t = t1;
	}
	else
		cone->t = 20000;
	rotation(glb->cam->dir, cone->rot, 1);
}
