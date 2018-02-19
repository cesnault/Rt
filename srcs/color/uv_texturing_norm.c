/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_texturing_norm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 21:43:07 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/05 21:43:08 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "math.h"

int			ft_clamp(int value, int min, int max)
{
	value > max ? value = max : 0;
	value < min ? value = min : 0;
	return (value);
}

void		uv_sphere(t_obj *o, float *u, float *v)
{
	t_vect3d	n;

	n = vect_sub2(o->origin, o->intersect);
	vect_normalize(&n);
	*u = atan2(n.x, n.z) / (2 * 3.14) + 0.5;
	*v = n.y * 0.5 + 0.5;
	*u -= 0.1;
	if (*u < 0.0)
		*u = 1.0 + *u;
	if (*v < 0.0)
		*v = 1.0 + *v;
}

void		uv_cylinder(t_obj *o, float *u, float *v)
{
	t_vect3d		n;
	float			new_size;

	n = vect_sub2(o->origin, o->intersect);
	new_size = sqrt(n.x * n.x + n.y * n.y + n.z * n.z);
	vect_normalize(&n);
	*u = atan2(n.x, n.z) / (2 * 3.14) + 0.5;
	*v = n.y * 0.5 + 0.5;
	*u -= 0.1;
	if (*u < 0.0)
		*u = 1.0 + *u;
	if (*v < 0.0)
		*v = 1.0 + *v;
}
