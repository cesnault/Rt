/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_picture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 23:08:55 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/12 23:09:13 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color_light		color_picture(t_rt *glb, int id)
{
	t_color_light	res;
	t_rgb			rgb;
	float			u;
	float			v;
	t_texture		*text;

	text = (t_texture *)(glb->tab_obj->all_obj[id]->texture->obj);
	main_uv_texture(glb->tab_obj->all_obj[id], &u, &v);
	u *= (float)(text->dim.x);
	v *= (float)(text->dim.y);
	min_maxf(&v, 0, (float)(text->dim.y) - 1);
	min_maxf(&u, 0, (float)(text->dim.x) - 1);
	rgb = text->rgb[((int)v)][((int)u)];
	res.x = ((float)rgb.r) / 255.0;
	res.y = ((float)rgb.g) / 255.0;
	res.z = ((float)rgb.b) / 255.0;
	return (res);
}
