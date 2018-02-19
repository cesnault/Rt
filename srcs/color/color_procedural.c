/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_procedural.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 23:09:45 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/12 23:10:00 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "procedural.h"

t_color_light		color_procedural(t_rt *glb, int id)
{
	t_color_light	res;
	t_rgb			rgb;

	rgb = procedural_main(glb->tab_obj->all_obj[id]->intersect,\
((int *)(glb->tab_obj->all_obj[id]->texture->obj)));
	res.x = ((float)rgb.r) / 255.0;
	res.y = ((float)rgb.g) / 255.0;
	res.z = ((float)rgb.b) / 255.0;
	return (res);
}
