/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_in_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 20:24:14 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/14 03:19:43 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"
#include "rt.h"

void		copy_in_obj_norm(t_e *e, t_obj *obj)
{
	if (!(obj->name = ft_strdup(e->o->name)))
		malloc_fail("copy_in_obj_norm");
	(obj->origin) = e->o->origin;
	obj->id = e->o->id;
	if (e->idobj != 2)
		obj->rey = e->o->rey;
	obj->dir = e->o->dir;
	obj->texture = e->o->texture;
	obj->color_light = NULL;
	(obj->rot) = e->o->rot;
	(obj->p1) = NULL;
	(obj->p2) = NULL;
	(obj->p3) = NULL;
}

void		copy_in_obj(t_e *e, t_obj *obj)
{
	choose_obj_type(e, obj);
	copy_in_obj_norm(e, obj);
	if (!(obj->intersect = (t_vect3d *)malloc(sizeof(t_vect3d))))
		malloc_fail("copy_in_obj");
	if (!(obj->normal = (t_vect3d *)malloc(sizeof(t_vect3d))))
		malloc_fail("copy_in_obj");
	if (gtk_toggle_button_get_active(\
		GTK_TOGGLE_BUTTON(e->button_addsphere[5])) == FALSE)
		obj->neg = 0;
	if (gtk_toggle_button_get_active(\
		GTK_TOGGLE_BUTTON(e->button_addsphere[5])) == TRUE)
		obj->neg = 1;
	obj->t = e->o->t;
	obj->id = e->glb->pos_obj->size_use + e->glb->neg_obj->size_use;
}
