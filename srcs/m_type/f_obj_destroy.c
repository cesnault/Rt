/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_obj_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 00:05:52 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/13 00:06:58 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>
#include "ft_ori.h"
#include "texture.h"

void			obj_free_texture(t_ptextu **text)
{
	t_ptextu	*t;
	t_texture	*tt;

	if (!text && !(*text))
		return ;
	t = *text;
	if (t->type && (t->type == PERLIN || t->type == PICTURE))
	{
		tt = (t_texture *)(t->obj);
		texture_destroy(&tt);
	}
	else if (t->type && t->type == PROCEDURAL)
		free((int *)(t->obj));
	else if (t->type && t->type == COLOR)
		free((t_color_light *)t->obj);
	free(*text);
	*text = 0;
}

void			obj_destroy(t_obj *o)
{
	if (!(o))
		return ;
	if (o->texture)
		obj_free_texture(&(o->texture));
	if (o->name)
		free(o->name);
	if (o->origin)
		free(o->origin);
	if (o->dir)
		free(o->dir);
	if (o->color_light)
		free(o->color_light);
	if (o->rot)
		free(o->rot);
	if (o->intersect)
		free(o->intersect);
	if (o->normal)
		free(o->normal);
	if (o->p1)
		free(o->p1);
	if (o->p2)
		free(o->p2);
	if (o->p3)
		free(o->p3);
}

void			free_all_obj(t_obj **obj, int size)
{
	int			c;
	t_obj		*o;

	if (!obj || !(*obj))
		return ;
	c = 0;
	o = *obj;
	while (c < size)
	{
		obj_destroy(&(o[c]));
		c++;
	}
	free(*obj);
}
