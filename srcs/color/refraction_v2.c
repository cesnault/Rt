/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction_v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 21:17:56 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/05 21:17:59 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"
#include "../../libft/includes/ft_ori.h"
#include <stdlib.h>
#include <math.h>

void			res_refrac(t_rt *glb, int id, t_color_light glb_col2,
	t_color_light *res)
{
	res->x *= glb->col.r * (1 - glb->tab_obj->\
		all_obj[id]->texture->refl_diffuse);
	res->y *= glb->col.g * (1 - glb->tab_obj->\
		all_obj[id]->texture->refl_diffuse);
	res->z *= glb->col.b * (1 - glb->tab_obj->\
		all_obj[id]->texture->refl_diffuse);
	glb->col.r = glb_col2.x;
	glb->col.g = glb_col2.y;
	glb->col.b = glb_col2.z;
}

t_color_light	recursivity(t_rt *glb, int id)
{
	t_color_light		glb_col2;
	t_color_light		res;
	int					id2;

	res.x = 1;
	res.y = 1;
	res.z = 1;
	id2 = -1;
	if (id == -1)
	{
		glb->max = 0;
		return (res);
	}
	if ((glb->tab_obj->all_obj[id]->texture->refl_diffuse >= 1 || glb->max > 2))
	{
		glb->max = 0;
		return (res);
	}
	enter(glb, id);
	glb->max += 1;
	outs(glb, id, &id2, &glb_col2);
	res_refrac(glb, id, glb_col2, &res);
	return (res);
}

void			var_in(t_vect3d var[4], t_rt *glb, int id)
{
	var[0] = *glb->cam->origin;
	var[1] = *glb->cam->dir;
	var[2] = *glb->tab_obj->all_obj[id]->intersect;
	var[3] = *glb->tab_obj->all_obj[id]->normal;
}

void			var_out(t_vect3d var[4], t_rt *glb, int id)
{
	*glb->cam->origin = var[0];
	*glb->cam->dir = var[1];
	*glb->tab_obj->all_obj[id]->intersect = var[2];
	*glb->tab_obj->all_obj[id]->normal = var[3];
}

void			refraction_v2(t_rt *glb, int id)
{
	t_vect3d				var[4];
	t_color_light			glb_col;

	var_in(var, glb, id);
	if (glb->tab_obj->all_obj[id]->texture->refl_diffuse < 1)
	{
		glb_col = recursivity(glb, id);
		glb->col.r += glb_col.x;
		glb->col.g += glb_col.y;
		glb->col.b += glb_col.z;
	}
	else
	{
		glb_col = recur_refl(glb, id);
		glb->col.r += glb_col.x;
		glb->col.g += glb_col.y;
		glb->col.b += glb_col.z;
	}
	var_out(var, glb, id);
}
