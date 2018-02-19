/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_rectangle2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 23:44:28 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/02 23:46:46 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>
#include <unistd.h>
#include "ft_ori.h"
#include "parser.h"
#include "math.h"
#include "rt.h"
#include "generic_parser.h"

static t_obj		*obj_first_triangle(t_spe_object *spe)
{
	t_obj			*obj;

	obj = obj_init();
	if (spe->name)
		if (!(obj->name = ft_strdup(spe->name)))
			malloc_fail("obj_first_triangle");
	obj->origin = vect_dup(spe->origin);
	obj->rot = vect_dup(spe->rot);
	obj->color_light = color_light_dup(spe->color_light);
	obj->p1 = vect_dup(spe->origin);
	obj->p1->x -= (spe->dim->x / 2.0);
	obj->p1->y -= (spe->dim->y / 2.0);
	obj->p2 = vect_dup(spe->origin);
	obj->p2->x -= (spe->dim->x / 2.0);
	obj->p2->y += (spe->dim->y / 2.0);
	obj->p3 = vect_dup(spe->origin);
	obj->p3->x += (spe->dim->x / 2.0);
	obj->p3->y -= (spe->dim->y / 2.0);
	calcul_rot(obj->p1, spe->origin, spe->rot);
	calcul_rot(obj->p2, spe->origin, spe->rot);
	calcul_rot(obj->p3, spe->origin, spe->rot);
	obj->texture = spe->texture;
	obj->type = TRIANGLE;
	vect_set_all(obj->rot, 0.0, 0.0, 0.0);
	return (obj);
}

static t_obj		*obj_second_triangle(t_spe_object *spe)
{
	t_obj			*obj;

	obj = obj_init();
	if (spe->name)
		if (!(obj->name = ft_strdup(spe->name)))
			malloc_fail("obj_second_triangle");
	obj->origin = vect_dup(spe->origin);
	obj->rot = vect_dup(spe->rot);
	obj->color_light = color_light_dup(spe->color_light);
	obj->p1 = vect_dup(spe->origin);
	obj->p1->x += (spe->dim->x / 2.0);
	obj->p1->y += (spe->dim->y / 2.0);
	obj->p2 = vect_dup(spe->origin);
	obj->p2->x -= (spe->dim->x / 2.0);
	obj->p2->y += (spe->dim->y / 2.0);
	obj->p3 = vect_dup(spe->origin);
	obj->p3->x += (spe->dim->x / 2.0);
	obj->p3->y -= (spe->dim->y / 2.0);
	calcul_rot(obj->p1, spe->origin, spe->rot);
	calcul_rot(obj->p2, spe->origin, spe->rot);
	calcul_rot(obj->p3, spe->origin, spe->rot);
	obj->texture = spe->texture;
	obj->type = TRIANGLE;
	vect_set_all(obj->rot, 0.0, 0.0, 0.0);
	return (obj);
}

void				parser_extract_rectangle(int fd, int type,\
t_all_pobject *mimi)
{
	t_spe_object	*spe;
	t_obj			*obj;
	t_pobject		*p;

	(void)mimi;
	spe = extract_spe_object(fd, type);
	spe->rot->x = (spe->rot->x) * (2.0 * 3.14) / 360.0;
	spe->rot->y = (spe->rot->y) * (2.0 * 3.14) / 360.0;
	spe->rot->z = (spe->rot->z) * (2.0 * 3.14) / 360.0;
	vect_normalize(spe->rot);
	obj = obj_first_triangle(spe);
	p = pobject_create(obj, TRIANGLE);
	add_pobject_in_all(mimi, p);
	obj = obj_second_triangle(spe);
	p = pobject_create(obj, TRIANGLE);
	add_pobject_in_all(mimi, p);
	return ;
}

void				parser_rectangle(t_all_pobject *mimi, t_spe_object *spe)
{
	t_obj			*obj;
	t_pobject		*p;

	(void)mimi;
	spe->rot->x = (spe->rot->x) * (2.0 * 3.14) / 360.0;
	spe->rot->y = (spe->rot->y) * (2.0 * 3.14) / 360.0;
	spe->rot->z = (spe->rot->z) * (2.0 * 3.14) / 360.0;
	vect_normalize(spe->rot);
	obj = obj_first_triangle(spe);
	p = pobject_create(obj, TRIANGLE);
	add_pobject_in_all(mimi, p);
	obj = obj_second_triangle(spe);
	p = pobject_create(obj, TRIANGLE);
	add_pobject_in_all(mimi, p);
	return ;
}
