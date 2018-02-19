/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_ptexture_dup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 14:21:20 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/15 14:21:50 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "texture.h"
#include <stdlib.h>

static int		*dup_procedural_id(int *a)
{
	int			*p;

	if (!(p = malloc(sizeof(int))))
		malloc_fail("dup_procedural_id");
	if (!a)
		malloc_fail("dup_procedural_id");
	*p = *a;
	return (p);
}

t_ptextu		*dup_ptexture(t_ptextu *pp)
{
	t_ptextu	*p;
	t_texture	*t;

	if (!(p = malloc(sizeof(t_ptextu))))
		malloc_fail("dup_ptexture");
	if (!pp)
		malloc_fail("dup_ptexture");
	p->type = pp->type;
	if (p->type == COLOR)
	{
		p->obj = (t_color_light *)color_light_dup(pp->obj);
	}
	else if (p->type == PERLIN || p->type == PICTURE)
	{
		p->obj = (t_texture *)texture_dup((t_texture *)(pp->obj));
		t = p->obj;
	}
	else if (p->type == PROCEDURAL)
	{
		p->obj = dup_procedural_id(pp->obj);
	}
	p->refl_specu = pp->refl_specu;
	p->refl_diffuse = pp->refl_diffuse;
	p->refract = pp->refract;
	return (p);
}
