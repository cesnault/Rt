/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 21:05:46 by cesnault          #+#    #+#             */
/*   Updated: 2017/05/19 21:06:23 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>
#include "../../minilibx_macos/mlx.h"

static	void		default_cam(t_cam *cam)
{
	cam->origin->x = 0;
	cam->origin->y = 0;
	cam->origin->z = 0;
	cam->rot->x = 0;
	cam->rot->y = 0;
	cam->rot->z = 0;
	cam->dir->x = 0;
	cam->dir->y = 0;
	cam->dir->z = 0;
}

void				free_other_camera(t_all_pobject *pop, unsigned int i)
{
	while (i < pop->size_use)
	{
		if (pop->all_obj[i]->type == 7)
		{
			free(((t_cam *)pop->all_obj[i]->obj)->origin);
			free(((t_cam *)pop->all_obj[i]->obj)->rot);
			free(((t_cam *)pop->all_obj[i]->obj));
		}
		i++;
	}
}

void				malloc_cam(t_cam *cam)
{
	if (!(cam->origin = (t_vect3d *)malloc(sizeof(t_vect3d))))
		malloc_fail("init_cam");
	if (!(cam->rot = (t_vect3d *)malloc(sizeof(t_vect3d))))
		malloc_fail("init_cam");
	if (!(cam->dir = (t_vect3d *)malloc(sizeof(t_vect3d))))
		malloc_fail("init_cam");
}

void				init_cam(t_rt *rt, t_all_pobject *pop)
{
	unsigned int	i;
	t_cam			*cam;

	i = 0;
	if (!(cam = cam_init()))
		return ;
	while (i < pop->size_use)
	{
		if (pop->all_obj[i]->type == 7)
		{
			cam->origin = ((t_cam *)pop->all_obj[i]->obj)->origin;
			cam->rot = ((t_cam *)pop->all_obj[i]->obj)->rot;
			if (!(cam->dir = (t_vect3d *)malloc(sizeof(t_vect3d))))
				malloc_fail("init_cam");
			rt->cam = cam;
			free(((t_cam *)pop->all_obj[i]->obj));
			i++;
			free_other_camera(pop, i);
			return ;
		}
		i++;
	}
	malloc_cam(cam);
	default_cam(cam);
	rt->cam = cam;
}
