/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calcul3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 18:59:00 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/02 18:59:20 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "parser.h"
#include <stdlib.h>

double			vect_dot(t_vect3d *a, t_vect3d *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

t_vect3d		vect_cross(t_vect3d *a, t_vect3d *b)
{
	t_vect3d	v;

	v.x = a->y * b->z - a->z * b->y;
	v.y = a->z * b->x - a->x * b->z;
	v.z = a->x * b->y - a->y * b->x;
	return (v);
}

void			vect_scalaire(t_vect3d *a, double b)
{
	a->x *= b;
	a->y *= b;
	a->z *= b;
}

void			vect_set_all(t_vect3d *a, double x, double y, double z)
{
	a->x = x;
	a->y = y;
	a->z = z;
}
