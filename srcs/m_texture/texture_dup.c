/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 22:47:07 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/15 22:47:17 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "type.h"
#include "texture.h"

t_texture		*texture_dup(t_texture *text)
{
	t_texture	*t;
	int			x;
	int			y;

	if (!text || !(text->rgb))
	{
		return (0);
	}
	y = 0;
	if (!(t = texture_init("no name", text->dim.x, text->dim.y)))
		return (0);
	while (y < t->dim.y)
	{
		x = 0;
		while (x < t->dim.x)
		{
			t->rgb[y][x].r = text->rgb[y][x].r;
			t->rgb[y][x].g = text->rgb[y][x].g;
			t->rgb[y][x].b = text->rgb[y][x].b;
			x++;
		}
		y++;
	}
	return (t);
}
