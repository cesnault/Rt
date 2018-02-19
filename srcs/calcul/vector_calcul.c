/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calcul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 19:43:39 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/02 19:07:15 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "parser.h"
#include <stdlib.h>

t_vect3d			*vect_sub(t_vect3d *a, t_vect3d *b)
{
	t_vect3d		*res;

	if (!(res = malloc(sizeof(t_vect3d))))
		malloc_fail("vect_sub");
	res->x = a->x - b->x;
	res->y = a->y - b->y;
	res->z = a->z - b->z;
	return (res);
}

void				vect_sub3(t_vect3d *ori, t_vect3d *a, t_vect3d *b)
{
	ori->x = a->x - b->x;
	ori->y = a->y - b->y;
	ori->z = a->z - b->z;
}

void				vect_add3(t_vect3d *ori, t_vect3d *a, t_vect3d *b)
{
	ori->x = a->x + b->x;
	ori->y = a->y + b->y;
	ori->z = a->z + b->z;
}

t_vect3d			*vect_add(t_vect3d *a, t_vect3d *b)
{
	t_vect3d		*res;

	if (!(res = malloc(sizeof(t_vect3d))))
		malloc_fail("vect_add");
	res->x = a->x + b->x;
	res->y = a->y + b->y;
	res->z = a->z + b->z;
	return (res);
}

void				vect_normalize(t_vect3d *a)
{
	double			norme;

	norme = 1 / sqrt(a->x * a->x + a->y * a->y + a->z * a->z);
	a->x *= norme;
	a->y *= norme;
	a->z *= norme;
}
