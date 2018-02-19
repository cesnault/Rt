/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction_v2_norm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 21:37:38 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/05 21:37:43 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"
#include "../../libft/includes/ft_ori.h"
#include <stdlib.h>
#include <math.h>

void			refract(t_rt *glb, int id, double n1, double n2)
{
	double			cos;
	double			sin;
	double			tmp;

	cos = vect_dot(glb->cam->dir, glb->tab_obj->all_obj[id]->normal);
	if (cos < 0)
	{
		cos *= -1;
	}
	tmp = 1 - pow((n1 / n2), 2) * (1 - pow(cos, 2));
	sin = sqrt(tmp);
	glb->cam->dir->x = (n1 / n2) * glb->cam->dir->x + ((n1 / n2) *\
cos - sin) * glb->tab_obj->all_obj[id]->normal->x;
	glb->cam->dir->y = (n1 / n2) * glb->cam->dir->y + ((n1 / n2) *\
cos - sin) * glb->tab_obj->all_obj[id]->normal->y;
	glb->cam->dir->z = (n1 / n2) * glb->cam->dir->z + ((n1 / n2) *\
cos - sin) * glb->tab_obj->all_obj[id]->normal->z;
	*glb->cam->origin = *glb->tab_obj->all_obj[id]->intersect;
}

void			hit(t_rt *glb, int id)
{
	double			t;
	int				i;
	t_vect3d		tmp;

	i = 0;
	t = 20000;
	if (glb->tab_obj->all_obj[id]->type == SPHERE)
		hit_ball(glb, glb->tab_obj->all_obj[id]);
	else if (glb->tab_obj->all_obj[id]->type == CYLINDER)
		hit_cylindre(glb, glb->tab_obj->all_obj[id]);
	else if (glb->tab_obj->all_obj[id]->type == CONE)
		hit_cone(glb, glb->tab_obj->all_obj[id]);
	else if (glb->tab_obj->all_obj[id]->type == PLAN)
		hit_plan(glb, glb->tab_obj->all_obj[id]);
	else if (glb->tab_obj->all_obj[id]->type == SPHEROID)
		hit_spheroid(glb, glb->tab_obj->all_obj[id]);
	else if (glb->tab_obj->all_obj[id]->type == TRIANGLE)
	{
		calcul_normal(glb, id);
		hit_triangle(glb, glb->tab_obj->all_obj[id]);
	}
	else if (glb->tab_obj->all_obj[id]->type == DISK)
		hit_disk(glb, glb->tab_obj->all_obj[id]);
	i++;
	apply_rotation(glb, &tmp, id);
}

void			outs(t_rt *glb, int id, int *id2, t_color_light *glb_col2)
{
	int				i;
	double			t;
	t_vect3d		tmp;

	t = 20000;
	i = 0;
	glb_col2->x = glb->col.r;
	glb_col2->y = glb->col.g;
	glb_col2->z = glb->col.b;
	glb->tmp_obj->size_use = 0;
	check_hit(glb);
	found_id(glb, id2);
	if (*id2 != -1 && *id2 != id)
	{
		if (glb->tab_obj->all_obj[*id2]->type == TRIANGLE)
			calcul(glb, *id2);
		else
			apply_rotation(glb, &tmp, *id2);
		shadow(glb, *id2);
		ambiante(glb, *id2);
		diffuse(glb, *id2);
		specular(glb, *id2);
		refraction_v2(glb, *id2);
	}
}

void			enter(t_rt *glb, int id)
{
	if (glb->tab_obj->all_obj[id]->texture->refract > 10)
		glb->tab_obj->all_obj[id]->texture->refract = 10;
	if (glb->tab_obj->all_obj[id]->texture->refract < 1)
		glb->tab_obj->all_obj[id]->texture->refract = 1;
	refract(glb, id, 1.0, glb->tab_obj->all_obj[id]->texture->refract);
	vect_normalize(glb->cam->dir);
	if (glb->tab_obj->all_obj[id]->type != PLAN &&\
		glb->tab_obj->all_obj[id]->type != TRIANGLE)
		hit(glb, id);
	refract(glb, id, glb->tab_obj->all_obj[id]->texture->refract, 1.0);
	vect_normalize(glb->cam->dir);
}
