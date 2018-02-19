/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_color_light2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:36:40 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/02 19:36:45 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>

void				color_light_set_x(t_color_light *vec, float x)
{
	if (vec)
		vec->x = x;
}

void				color_light_set_y(t_color_light *vec, float y)
{
	if (vec)
		vec->y = y;
}

void				color_light_set_z(t_color_light *vec, float z)
{
	if (vec)
		vec->z = z;
}

void				color_light_destroy(t_color_light *v)
{
	if (v)
		free(v);
}
