/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_triangle_bitch.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:19:05 by cesnault          #+#    #+#             */
/*   Updated: 2017/07/13 20:32:56 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "rt.h"
#include <stdlib.h>
#include "ft_ori.h"

t_ptextu		*dup_texture_color(t_ptextu *p, float r, float g, float b)
{
	t_ptextu	*pp;

	if (!(pp = malloc(sizeof(t_ptextu))))
		malloc_fail("dup_texture_color");
	pp->type = p->type;
	pp->refl_specu = p->refl_specu;
	pp->refl_diffuse = p->refl_diffuse;
	if (!(pp->obj = (t_color_light *)(malloc(sizeof(t_color_light)))))
		malloc_fail("dup_texture_color");
	((t_color_light *)(pp->obj))->x = r;
	((t_color_light *)(pp->obj))->y = g;
	((t_color_light *)(pp->obj))->z = b;
	return (pp);
}

void			make_triangle_bitch(t_generic_triangle t,\
t_vect3d p1, t_vect3d p2, t_vect3d p3)
{
	t_obj		*obj;

	obj = obj_init();
	if (!(obj->name = ft_strdup(t.spe->name)))
		malloc_fail("make_triangle_****");
	obj->type = TRIANGLE;
	obj->p1 = vect_dup(&(p1));
	obj->p2 = vect_dup(&(p2));
	obj->p3 = vect_dup(&(p3));
	obj->origin = vect_dup(&(p1));
	obj->origin->x += obj->p2->x + obj->p3->x;
	obj->origin->y += obj->p2->y + obj->p3->y;
	obj->origin->z += obj->p2->z + obj->p3->z;
	obj->origin->x /= 3.0;
	obj->origin->y /= 3.0;
	obj->origin->z /= 3.0;
	obj->rot = vect3d_init(0.0, 0.0, 0.0);
	obj->intersect = NULL;
	obj->normal = NULL;
	obj->texture = dup_ptexture(t.spe->texture);
	add_pobject_in_all(t.mimi, pobject_create(obj, TRIANGLE));
}

void			make_triangle_bitch2(t_generic_triangle t,\
t_vect3d p1, t_vect3d p2, t_vect3d p3)
{
	t_obj		*obj;

	obj = obj_init();
	if (!(obj->name = ft_strdup(t.spe->name)))
		malloc_fail("make_triangle_****");
	obj->type = TRIANGLE;
	obj->p1 = vect_dup(&(p1));
	obj->p2 = vect_dup(&(p2));
	obj->p3 = vect_dup(&(p3));
	obj->rot = vect3d_init(0.0, 0.0, 0.0);
	obj->texture = dup_ptexture(t.spe->texture);
	add_pobject_in_all(t.mimi, pobject_create(obj, TRIANGLE));
}
