/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_inter_sphere_other.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 00:16:23 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/02 00:16:49 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "type.h"
#include "rt.h"
#include <math.h>

int				is_inter_sphere_other(t_obj *sphere, t_vect3d *pos)
{
	t_vect3d	vec;
	double		v;

	vec = vect_sub2(sphere->origin, pos);
	v = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	v = fabs(v);
	return (v <= sphere->rey) ? 1 : 0;
}
