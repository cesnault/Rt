/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 19:50:50 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/21 19:08:41 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"
#include "../../minilibx_macos/mlx.h"
#include <math.h>

static void			color_diffuse(t_rt *glb, int id)
{
	int				i;
	t_vect3d		light_dir;
	double			res;
	t_color_light	color;

	color = color_object(glb, id);
	i = 0;
	while (i < (int)glb->tab_light->size_use)
	{
		vect_sub3(&light_dir, glb->tab_light->all_light[i]->origin,\
glb->tab_obj->all_obj[id]->intersect);
		vect_normalize(&light_dir);
		res = vect_dot(&light_dir, glb->tab_obj->all_obj[id]->normal);
		if (res > 0)
		{
			glb->col.r += res * LCOL->x * glb->tab_obj->all_obj[id]->texture->\
			refl_diffuse * color.x * glb->tab_light->all_light[i]->shadow;
			glb->col.g += res * LCOL->y * glb->tab_obj->all_obj[id]->texture->\
			refl_diffuse * color.y * glb->tab_light->all_light[i]->shadow;
			glb->col.b += res * LCOL->z * glb->tab_obj->all_obj[id]->texture->\
			refl_diffuse * color.z * glb->tab_light->all_light[i]->shadow;
		}
		i++;
	}
}

void				diffuse(t_rt *glb, int id)
{
	color_diffuse(glb, id);
}
