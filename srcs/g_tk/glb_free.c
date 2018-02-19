/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glb_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 20:33:18 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/22 20:33:21 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>
#include "gtkgui.h"

void	rgb_free(t_texture *obj)
{
	int i;

	i = 0;
	while (i < obj->dim.y)
	{
		if (obj->rgb[i] != NULL)
			free(obj->rgb[i]);
		i++;
	}
	if (obj->rgb != NULL)
		free(obj->rgb);
	if (obj->name != NULL)
		free(obj->name);
	free(obj);
}

void	tab_obj_free_norm(t_obj_redim *tab_obj, int i)
{
	free(tab_obj->all_obj[i]->texture);
	free(tab_obj->all_obj[i]->color_light);
	free(tab_obj->all_obj[i]->rot);
	free(tab_obj->all_obj[i]->intersect);
	free(tab_obj->all_obj[i]->normal);
}

void	tab_obj_free(t_obj_redim *tab_obj)
{
	unsigned int i;

	i = 0;
	while (i < tab_obj->size_use)
	{
		free(tab_obj->all_obj[i]->name);
		free(tab_obj->all_obj[i]->origin);
		free(tab_obj->all_obj[i]->dir);
		if (tab_obj->all_obj[i]->texture->type == 1)
			color_free(((t_color_light *)tab_obj->all_obj[i]->texture->obj));
		else if (tab_obj->all_obj[i]->texture->type != PROCEDURAL)
			rgb_free(((t_texture *)tab_obj->all_obj[i]->texture->obj));
		tab_obj_free_norm(tab_obj, i);
		if (tab_obj->all_obj[i]->p1 != NULL)
			free(tab_obj->all_obj[i]->p1);
		if (tab_obj->all_obj[i]->p2 != NULL)
			free(tab_obj->all_obj[i]->p2);
		if (tab_obj->all_obj[i]->p3 != NULL)
			free(tab_obj->all_obj[i]->p3);
		free(tab_obj->all_obj[i]);
		i++;
	}
	free(tab_obj->all_obj);
	free(tab_obj);
	tab_obj = NULL;
}

void	tab_light_free(t_light_redim *tab_light)
{
	unsigned int i;

	i = 0;
	while (i < tab_light->size_use)
	{
		free(tab_light->all_light[i]->name);
		free(tab_light->all_light[i]->origin);
		free(tab_light->all_light[i]->color_light);
		free(tab_light->all_light[i]);
		i++;
	}
	tab_light->size_use = 0;
	free(tab_light->all_light);
	free(tab_light);
	tab_light = NULL;
}

void	glb_free(t_rt *glb)
{
	tab_obj_free(glb->tab_obj);
	tab_light_free(glb->tab_light);
	cam_free(glb->cam);
	pos_obj_free(glb->pos_obj);
	neg_obj_free(glb->neg_obj);
	tmp_obj_free(glb->tmp_obj);
	setting_free(glb->setting);
	rgb_free(glb->text);
	free(glb->line);
	free(glb);
	glb = NULL;
}
