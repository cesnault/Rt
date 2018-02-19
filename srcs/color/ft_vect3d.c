/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 21:45:50 by cesnault          #+#    #+#             */
/*   Updated: 2017/07/05 21:45:51 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "math.h"

t_vect3d	rgb_to_vect3d(t_rgb r)
{
	t_vect3d v;

	v.x = r.r;
	v.y = r.g;
	v.z = r.b;
	return (v);
}

t_vect3d	vect3d_mult(t_vect3d a, float b)
{
	t_vect3d t;

	t.x = a.x * b;
	t.y = a.y * b;
	t.z = a.z * b;
	return (t);
}

t_vect3d	vect3d_mult2(t_vect3d a, t_vect3d b)
{
	t_vect3d t;

	t.x = a.x * b.x;
	t.y = a.y * b.y;
	t.z = a.z * b.z;
	return (t);
}

t_vect3d	vect3d_add(t_vect3d a, t_vect3d b)
{
	t_vect3d t;

	t.x = a.x + b.x;
	t.y = a.y + b.y;
	t.z = a.z + b.z;
	return (t);
}
