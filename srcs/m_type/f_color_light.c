/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_color_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 16:15:27 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/09 16:58:04 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>

t_color_light		*color_light_init(float x, float y, float z)
{
	t_color_light	*v;

	if (!(v = malloc(sizeof(t_color_light))))
		malloc_fail("color_light_init");
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}

float				color_light_get_x(t_color_light *vec)
{
	if (vec)
		return (vec->x);
	return (0.0);
}

float				color_light_get_y(t_color_light *vec)
{
	if (vec)
		return (vec->y);
	return (0.0);
}

float				color_light_get_z(t_color_light *vec)
{
	if (vec)
		return (vec->z);
	return (0.0);
}
