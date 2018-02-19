/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 19:47:47 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/21 20:54:31 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"
#include <math.h>
#include <stdlib.h>

static double		direction_of_light(t_rt *glb, int id, int i)
{
	t_vect3d		light_dir;
	t_vect3d		h;
	double			var;

	vect_sub3(&light_dir, glb->tab_light->all_light[i]->origin,\
glb->tab_obj->all_obj[id]->intersect);
	vect_normalize(&light_dir);
	vect_sub3(&h, &light_dir, glb->cam->dir);
	var = sqrt(vect_dot(&h, &h));
	if (var != 0)
	{
		h.x = (1.0 / var) * h.x;
		h.y = (1.0 / var) * h.y;
		h.z = (1.0 / var) * h.z;
	}
	vect_normalize(&h);
	var = pow(vect_dot(glb->tab_obj->all_obj[id]->normal, &h), 117);
	return (var);
}

void				specular(t_rt *glb, int id)
{
	int				i;
	double			spe;
	t_color_light	col;

	i = 0;
	col = color_object(glb, id);
	while (i < (int)glb->tab_light->size_use)
	{
		spe = direction_of_light(glb, id, i);
		if (spe > 0)
		{
			glb->col.r += glb->tab_obj->all_obj[id]->texture->refl_specu *\
spe * glb->tab_light->all_light[i]->color_light->x *
glb->tab_light->all_light[i]->shadow;
			glb->col.g += glb->tab_obj->all_obj[id]->texture->refl_specu *\
spe * glb->tab_light->all_light[i]->color_light->y *
glb->tab_light->all_light[i]->shadow;
			glb->col.b += glb->tab_obj->all_obj[id]->texture->refl_specu *\
spe * glb->tab_light->all_light[i]->color_light->z *
glb->tab_light->all_light[i]->shadow;
		}
		i++;
	}
}
