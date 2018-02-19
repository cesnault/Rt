/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calcul2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 18:51:32 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/02 18:52:26 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include "parser.h"
#include <stdlib.h>
#include <math.h>

t_vect3d			*vect_dup(t_vect3d *vec)
{
	t_vect3d		*v;

	if (!vec)
		return (0);
	if (!(v = malloc(sizeof(t_vect3d))))
		malloc_fail("vect_dup ");
	v->x = vec->x;
	v->y = vec->y;
	v->z = vec->z;
	return (v);
}

t_color_light		*color_light_dup(t_color_light *vec)
{
	t_color_light	*cl;

	if (!(cl = malloc(sizeof(t_color_light))))
		malloc_fail("color_light_dup ");
	cl->x = vec->x;
	cl->y = vec->y;
	cl->z = vec->z;
	return (cl);
}

double				vector_len2(t_vect3d a)
{
	double			l;

	l = a.x * a.x + a.y * a.y + a.z * a.z;
	l = sqrt(l);
	return (l);
}

t_vect3d			vector_mult2(double a, t_vect3d b)
{
	t_vect3d		vec;

	vec.x = a * b.x;
	vec.y = a * b.y;
	vec.z = a * b.z;
	return (vec);
}

t_vect3d			vector_norm2(t_vect3d a)
{
	t_vect3d		vec;
	double			l;

	vec = a;
	l = vector_len2(a);
	if (l)
	{
		l = 1 / l;
		vec = vector_mult2(l, vec);
	}
	return (vec);
}
