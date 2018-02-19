/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 19:40:23 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/02 19:11:25 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"
#include "ft_ori.h"
#include <math.h>
#include <stdlib.h>

static void		f_cam_to_normal(t_rt *glb, int id, double cam_to_normal)
{
	if (cam_to_normal < 0)
	{
		glb->tab_obj->all_obj[id]->normal->x = -1 *\
glb->tab_obj->all_obj[id]->dir->x;
		glb->tab_obj->all_obj[id]->normal->y = -1 *\
glb->tab_obj->all_obj[id]->dir->y;
		glb->tab_obj->all_obj[id]->normal->z = -1 *\
glb->tab_obj->all_obj[id]->dir->z;
	}
}

static void		f_triangle_normal(t_rt *glb, int id)
{
	t_vect3d	*e1;
	t_vect3d	*e2;
	t_vect3d	n;

	e1 = vect_sub(glb->tab_obj->all_obj[id]->p2, glb->tab_obj->all_obj[id]->p1);
	e2 = vect_sub(glb->tab_obj->all_obj[id]->p3, glb->tab_obj->all_obj[id]->p1);
	n = vect_cross(e1, e2);
	glb->tab_obj->all_obj[id]->normal->x = n.x;
	glb->tab_obj->all_obj[id]->normal->y = n.y;
	glb->tab_obj->all_obj[id]->normal->z = n.z;
	vect_normalize(glb->tab_obj->all_obj[id]->normal);
	free(e1);
	free(e2);
}

static void		update_value(t_vect3d *cam_dir, t_rt *glb, int id)
{
	cam_dir->x = glb->cam->dir->x * -1;
	cam_dir->y = glb->cam->dir->y * -1;
	cam_dir->z = glb->cam->dir->z * -1;
	glb->tab_obj->all_obj[id]->normal->x = glb->tab_obj->all_obj[id]->dir->x;
	glb->tab_obj->all_obj[id]->normal->y = glb->tab_obj->all_obj[id]->dir->y;
	glb->tab_obj->all_obj[id]->normal->z = glb->tab_obj->all_obj[id]->dir->z;
}

int				is_triangle(t_rt *glb, int id)
{
	if (glb->tab_obj->all_obj[id]->type == TRIANGLE)
	{
		f_triangle_normal(glb, id);
		return (1);
	}
	return (0);
}

void			calcul_normal(t_rt *glb, int id)
{
	t_vect3d	center;
	double		cam_to_normal;
	t_vect3d	cam_dir;

	if ((is_triangle(glb, id) == 1))
		return ;
	center.x = 0;
	center.z = 0;
	if (glb->tab_obj->all_obj[id]->type == CONE ||\
glb->tab_obj->all_obj[id]->type == CYLINDER)
		center.y = glb->tab_obj->all_obj[id]->intersect->y;
	else
		center.y = 0;
	if (glb->tab_obj->all_obj[id]->type != PLAN &&\
glb->tab_obj->all_obj[id]->type != DISK)
		vect_sub3(glb->tab_obj->all_obj[id]->normal,\
glb->tab_obj->all_obj[id]->intersect, &center);
	else
	{
		update_value(&cam_dir, glb, id);
		cam_to_normal = vect_dot(glb->tab_obj->all_obj[id]->normal, &cam_dir);
		f_cam_to_normal(glb, id, cam_to_normal);
	}
	vect_normalize(glb->tab_obj->all_obj[id]->normal);
}
