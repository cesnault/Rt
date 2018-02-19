/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_refl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 23:11:35 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/12 23:15:32 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"
#include "../../libft/includes/ft_ori.h"
#include <stdlib.h>

void			glb_reflec(t_rt *glb, int id, t_vect3d *reflechi)
{
	*glb->cam->origin = *glb->tab_obj->all_obj[id]->intersect;
	*glb->cam->dir = *reflechi;
}

void			vect_reflechi(t_rt *glb, int id)
{
	t_vect3d		temp;
	double			dot;
	t_vect3d		reflechi;
	double			cos;

	cos = vect_dot(glb->tab_obj->all_obj[id]->normal, glb->cam->dir);
	if (cos > 0)
	{
		glb->tab_obj->all_obj[id]->normal->x *= -1;
		glb->tab_obj->all_obj[id]->normal->y *= -1;
		glb->tab_obj->all_obj[id]->normal->z *= -1;
	}
	dot = vect_dot(glb->tab_obj->all_obj[id]->normal, glb->cam->dir);
	temp = *glb->tab_obj->all_obj[id]->normal;
	vect_scalaire(&temp, dot);
	vect_scalaire(&temp, 2);
	vect_sub3(&reflechi, glb->cam->dir, &temp);
	glb_reflec(glb, id, &reflechi);
}

t_color_light	color_reflect(t_rt *glb, int id)
{
	t_color_light	res;

	res = color_object(glb, id);
	return (res);
}

void			res_col_add(t_color_light *res,
	t_rt *glb, t_color_light glb_col2, int id)
{
	*res = color_reflect(glb, id);
	res->x *= glb->tab_obj->all_obj[id]->texture->refl_specu * glb->col.r;
	res->y *= glb->tab_obj->all_obj[id]->texture->refl_specu * glb->col.g;
	res->z *= glb->tab_obj->all_obj[id]->texture->refl_specu * glb->col.b;
	glb->col.r = glb_col2.x;
	glb->col.g = glb_col2.y;
	glb->col.b = glb_col2.z;
}

t_color_light	recur_refl(t_rt *glb, int id)
{
	t_color_light	res;
	static int		max;
	t_color_light	glb_col2;
	int				id2;

	id2 = -1;
	max = 0;
	res.x = 0;
	res.y = 0;
	res.z = 0;
	if (id == -1)
	{
		glb->max = 0;
		return (res);
	}
	if (glb->tab_obj->all_obj[id]->texture->refl_specu == 0 || glb->max > 3)
	{
		glb->max = 0;
		return (res);
	}
	vect_reflechi(glb, id);
	glb->max += 1;
	outs(glb, id, &id2, &glb_col2);
	res_col_add(&res, glb, glb_col2, id);
	return (res);
}
