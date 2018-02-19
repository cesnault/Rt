/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 23:10:19 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/12 23:11:08 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color_light		color_obj(t_rt *glb, int id)
{
	t_color_light	res;

	res.x = ((t_color_light *)glb->tab_obj->all_obj[id]->texture->obj)->x;
	res.y = ((t_color_light *)glb->tab_obj->all_obj[id]->texture->obj)->y;
	res.z = ((t_color_light *)glb->tab_obj->all_obj[id]->texture->obj)->z;
	return (res);
}

t_color_light		rgb_in_color_light(t_rgb rgb)
{
	t_color_light	res;

	res.x = ((float)rgb.r) / 255.0;
	res.y = ((float)rgb.g) / 255.0;
	res.z = ((float)rgb.b) / 255.0;
	return (res);
}

void				min_maxf(float *v, float min, float max)
{
	if (*v > max)
		*v = max;
	if (*v < min)
	{
		*v = *v + max;
		min_maxf(v, min, max);
	}
}
