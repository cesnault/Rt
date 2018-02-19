/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 23:55:56 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/15 21:32:11 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "perlin.h"

static void		basic_init_rgb(t_rgb *color, double v)
{
	color->r = (int)(v);
	color->g = (int)(v);
	color->b = (int)(v);
}

void			smooth_texture(t_texture *text, double **noise,\
double zoom)
{
	t_rgb		color;
	double		pos[2];
	int			dim[2];
	int			coord[2];
	double		value_sn;

	color.a = 0;
	coord[1] = 0;
	dim[0] = text->dim.x;
	dim[1] = text->dim.y;
	while (coord[1] < text->dim.y)
	{
		coord[0] = 0;
		while (coord[0] < text->dim.x)
		{
			pos[0] = (double)coord[0];
			pos[1] = (double)coord[1];
			value_sn = turbulence(pos, noise, zoom, dim);
			basic_init_rgb(&color, value_sn);
			texture_add_pixel(text, color, coord[0], coord[1]);
			coord[0] += 1;
		}
		coord[0] = 0;
		coord[1] += 1;
	}
}
