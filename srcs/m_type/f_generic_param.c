/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_generic_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 05:51:32 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/11 05:51:55 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>
#include "ft_ori.h"

t_generic_param		*init_generic_param(void)
{
	t_generic_param *g;

	if (!(g = malloc(sizeof(t_generic_param))))
		malloc_fail("init_generic_param");
	if (!(g->name = ft_strdup("RT")))
		malloc_fail("init_generic_param");
	g->dim.x = 1000;
	g->dim.y = 1000;
	g->ambiant = 0.2f;
	g->sepia = 0;
	g->stereo = 0;
	g->antialia = 1;
	g->green = 0;
	g->yellow = 0;
	g->red = 0;
	g->neg = 0;
	return (g);
}

void				gen_param_set_dim(t_generic_param *g, int x, int y)
{
	g->dim.x = x;
	g->dim.y = y;
}

void				gen_param_set_ambiant(t_generic_param *g, float ambiant)
{
	g->ambiant = ambiant;
}

void				gen_param_set_name(t_generic_param *g, char *name)
{
	if (!(g->name = ft_strdup(name)))
		malloc_fail("gen_param_set_name");
}

void				gp_min_max_value(t_generic_param *g)
{
	if (!g)
		return ;
	if (g->dim.x > 1000)
		g->dim.x = 1000;
	if (g->dim.y > 1000)
		g->dim.y = 1000;
	if (g->dim.x < 1000)
		g->dim.x = 1000;
	if (g->dim.y < 1000)
		g->dim.y = 1000;
}
