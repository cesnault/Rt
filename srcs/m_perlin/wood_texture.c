/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wood_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 23:56:06 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/15 21:52:03 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "perlin.h"
#include <math.h>

static void	update_color(double *td, t_rgb *color)
{
	td[6] = 128.0 * (sin(2.0 * td[0] * td[5] * 3.14159));
	if (td[6] < 0.0)
		td[6] *= -1.0;
	color->r = 80 + td[6];
	color->g = 30 + td[6];
	color->b = 30;
	if (color->r > 255)
		color->r = 255;
	if (color->g > 255)
		color->g = 255;
}

static void	init_ti_td(double *td, double zoom, int *ti, t_texture *text)
{
	td[0] = 5.0;
	td[1] = 0.1;
	td[2] = zoom;
	ti[0] = text->dim.x;
	ti[1] = text->dim.y;
}

void		wood_texture(t_texture *text, double **noise, double zoom)
{
	t_rgb	color;
	int		pos[2];
	double	td[8];
	int		ti[2];

	init_ti_td(td, zoom, ti, text);
	pos[1] = 0;
	color.a = 0;
	while (pos[1] < text->dim.y)
	{
		pos[0] = 0;
		while (pos[0] < text->dim.x)
		{
			td[6] = pos[0];
			td[7] = pos[1];
			td[3] = (pos[0] - text->dim.x / 2) / ((double)text->dim.x);
			td[4] = (pos[1] - text->dim.y / 2) / ((double)text->dim.y);
			td[5] = sqrt(td[3] * td[3] + td[4] * td[4]) +\
td[1] * turbulence(&(td[6]), noise, td[2], ti) / 256.0;
			update_color(td, &color);
			texture_add_pixel(text, color, pos[0], pos[1]);
			pos[0] += 1;
		}
		pos[1] += 1;
	}
}
