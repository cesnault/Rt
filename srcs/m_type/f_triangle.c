/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_triangle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 14:41:24 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/17 14:45:03 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>

t_triangle		*triangle_init(void)
{
	t_triangle	*t;

	if (!(t = malloc(sizeof(t_triangle))))
		malloc_fail("triangle_init");
	t->name = 0;
	t->p1 = 0;
	t->p2 = 0;
	t->p3 = 0;
	t->texture = 0;
	t->color_light = 0;
	t->rot = 0;
	t->intersect = 0;
	t->normal = 0;
	t->id = 0;
	t->type = TRIANGLE;
	return (t);
}

/*
** pensez par free la structure
*/

void			triangle_free(t_triangle **triangle)
{
	t_triangle	*t;

	if (!triangle || !(*triangle))
		return ;
	t = *triangle;
	if (t->name)
		free(t->name);
	if (t->color_light)
		free(t->color_light);
	if (t->rot)
		free(t->rot);
	if (t->intersect)
		free(t->intersect);
	if (t->normal)
		free(t->normal);
	if (t->p1)
		free(t->p1);
	if (t->p2)
		free(t->p2);
	if (t->p3)
		free(t->p3);
	free(t);
	*triangle = 0;
}
