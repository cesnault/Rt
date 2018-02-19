/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_vect3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 16:06:25 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/06 16:07:04 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>

t_vect3d		*vect3d_init(double x, double y, double z)
{
	t_vect3d	*v;

	if (!(v = malloc(sizeof(t_vect3d))))
		malloc_fail("vect3d_init");
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}

t_vect3d		vect3d_init2(double x, double y, double z)
{
	t_vect3d	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

double			vect3d_get_x(t_vect3d *vec)
{
	if (vec)
		return (vec->x);
	return (0.0);
}

double			vect3d_get_y(t_vect3d *vec)
{
	if (vec)
		return (vec->y);
	return (0.0);
}

double			vect3d_get_z(t_vect3d *vec)
{
	if (vec)
		return (vec->z);
	return (0.0);
}
