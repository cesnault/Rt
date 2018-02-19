/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 19:23:59 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/22 02:06:23 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"

void		check_hit(t_rt *glb)
{
	int		i;
	int		f;

	i = 0;
	while (i < glb->pos_obj->size_use)
	{
		f = glb->pos_obj->tab[i];
		if (glb->tab_obj->all_obj[f]->type == SPHERE)
			hit_ball(glb, glb->tab_obj->all_obj[f]);
		else if (glb->tab_obj->all_obj[f]->type == CYLINDER)
			hit_cylindre(glb, glb->tab_obj->all_obj[f]);
		else if (glb->tab_obj->all_obj[f]->type == CONE)
			hit_cone(glb, glb->tab_obj->all_obj[f]);
		else if (glb->tab_obj->all_obj[f]->type == PLAN)
			hit_plan(glb, glb->tab_obj->all_obj[f]);
		else if (glb->tab_obj->all_obj[f]->type == SPHEROID)
			hit_spheroid(glb, glb->tab_obj->all_obj[f]);
		else if (glb->tab_obj->all_obj[f]->type == TRIANGLE)
			hit_triangle(glb, glb->tab_obj->all_obj[f]);
		else if (glb->tab_obj->all_obj[f]->type == DISK)
			hit_disk(glb, glb->tab_obj->all_obj[f]);
		i++;
	}
}

void		apply_rotation(t_rt *glb, t_vect3d *tmp, int id)
{
	*tmp = *glb->cam->origin;
	vect_sub3(glb->cam->origin, glb->cam->origin,
		glb->tab_obj->all_obj[id]->origin);
	rev_rotation(glb->cam->origin, glb->tab_obj->all_obj[id]->rot, 1);
	rev_rotation(glb->cam->dir, glb->tab_obj->all_obj[id]->rot, 1);
	calcul_intersect(glb, id);
	calcul_normal(glb, id);
	rotation(glb->cam->dir, glb->tab_obj->all_obj[id]->rot, 1);
	rotation(glb->tab_obj->all_obj[id]->intersect,
		glb->tab_obj->all_obj[id]->rot, 1);
	vect_add3(glb->tab_obj->all_obj[id]->intersect, glb->tab_obj->all_obj[id]->\
		intersect, glb->tab_obj->all_obj[id]->origin);
	rotation(glb->tab_obj->all_obj[id]->normal,
		glb->tab_obj->all_obj[id]->rot, 1);
	*glb->cam->origin = *tmp;
}

void		calcul(t_rt *glb, int id)
{
	calcul_intersect(glb, id);
	calcul_normal(glb, id);
}

void		hit_object_texture(t_rt *glb, int x, int y, t_texture *text)
{
	int			id;
	double		t;
	t_vect3d	tmp;

	t = 20000;
	id = -1;
	glb->tmp_obj->size_use = 0;
	check_hit(glb);
	found_id(glb, &id);
	if (id != -1 && glb->tab_obj->all_obj[id]->t < 20000)
	{
		if (glb->tab_obj->all_obj[id]->type == TRIANGLE)
			calcul(glb, id);
		else
			apply_rotation(glb, &tmp, id);
		glb->max = 0;
		shadow(glb, id);
		ambiante(glb, id);
		diffuse(glb, id);
		specular(glb, id);
		refraction_v2(glb, id);
		stock_texture(glb, x, y, text);
	}
}
