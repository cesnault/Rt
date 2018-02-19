/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 19:41:49 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/22 02:50:32 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"

void			calcul_intersect(t_rt *glb, int id)
{
	if (glb->tab_obj->all_obj[id]->type == SPHEROID)
		return ;
	glb->tab_obj->all_obj[id]->intersect->x = glb->cam->origin->x +\
glb->cam->dir->x * glb->tab_obj->all_obj[id]->t;
	glb->tab_obj->all_obj[id]->intersect->y = glb->cam->origin->y +\
glb->cam->dir->y * glb->tab_obj->all_obj[id]->t;
	glb->tab_obj->all_obj[id]->intersect->z = glb->cam->origin->z +\
glb->cam->dir->z * glb->tab_obj->all_obj[id]->t;
}

t_vect3d		vect_sub2(t_vect3d *a, t_vect3d *b)
{
	t_vect3d		res;

	res.x = a->x - b->x;
	res.y = a->y - b->y;
	res.z = a->z - b->z;
	return (res);
}
