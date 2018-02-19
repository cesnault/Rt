/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:24:12 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/22 01:52:56 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

double	dist(t_vect3d *b, t_vect3d *a)
{
	return (sqrt(pow(b->x - a->x, 2) + pow(b->y - a->y, 2) +
		pow(b->z - a->z, 2)));
}

void	shadow_or_not(t_rt *glb, int i, int id, int id2)
{
	t_vect3d intersect;

	if (id == -1 || id2 == id)
		glb->tab_light->all_light[i]->shadow = 1;
	else
	{
		calcul_intersect(glb, id);
		calcul_normal(glb, id);
		intersect = *glb->tab_obj->all_obj[id]->intersect;
		if (dist(glb->tab_light->all_light[i]->origin, glb->\
			cam->origin) < dist(&intersect, glb->cam->origin))
			glb->tab_light->all_light[i]->shadow = 1;
		else
			glb->tab_light->all_light[i]->shadow = 1 - glb->tab_obj->\
		all_obj[id]->texture->refl_diffuse;
	}
}

void	shadow(t_rt *glb, int id)
{
	t_vect3d	light_dir;
	int			i;
	t_vect3d	tmp[2];
	int			id2;

	tmp[0] = *glb->cam->dir;
	tmp[1] = *glb->cam->origin;
	i = 0;
	id2 = id;
	while (i < (int)glb->tab_light->size_use)
	{
		id = -1;
		vect_sub3(&light_dir, glb->tab_light->all_light[i]->origin,
			glb->tab_obj->all_obj[id2]->intersect);
		vect_normalize(&light_dir);
		*glb->cam->dir = light_dir;
		*glb->cam->origin = *glb->tab_obj->all_obj[id2]->intersect;
		glb->tmp_obj->size_use = 0;
		check_hit(glb);
		found_id(glb, &id);
		shadow_or_not(glb, i, id, id2);
		i++;
	}
	*glb->cam->dir = tmp[0];
	*glb->cam->origin = tmp[1];
}
