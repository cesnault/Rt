/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 19:13:05 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/02 19:56:16 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"
#include <math.h>
#include <stdlib.h>

static double	solv_cylindre(t_cam *cam, t_obj *cyl)
{
	t_discr		solv;
	t_vect3d	ray_pos;

	ray_pos = vect_sub2(cam->origin, cyl->origin);
	rev_rotation(&ray_pos, cyl->rot, 1);
	rev_rotation(cam->dir, cyl->rot, 1);
	solv.a = pow(cam->dir->x, 2) + pow(cam->dir->z, 2);
	solv.b = 2 * ray_pos.x * cam->dir->x + 2 * ray_pos.z * cam->dir->z;
	solv.c = pow(ray_pos.x, 2) + pow(ray_pos.z, 2) - (cyl->rey * cyl->rey);
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

int				is_hit_cylinder(t_rt *glb, t_obj *cyl)
{
	double		ret;

	ret = solv_cylindre(glb->cam, cyl);
	if (ret < 20000.0 && ret > 0.001)
		return (1);
	else
		return (0);
	rotation(glb->cam->dir, cyl->rot, 1);
}

void			hit_cylindre(t_rt *glb, t_obj *cyl)
{
	double		t1;

	t1 = solv_cylindre(glb->cam, cyl);
	if (t1 < 20000 && t1 > 0.001)
	{
		tidr_set_double(glb->tmp_obj, cyl->id, t1);
		cyl->t = t1;
	}
	else
		cyl->t = 20000;
	rotation(glb->cam->dir, cyl->rot, 1);
}
