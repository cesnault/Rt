/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marble_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 23:55:41 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/15 21:42:07 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "perlin.h"
#include <math.h>

static t_rgb	init_rgb_marble(double v)
{
	t_rgb		r;

	r.r = v;
	r.g = v;
	r.b = v;
	r.a = 0;
	return (r);
}

static void		init_td(double *td, double zoom, int *p, t_texture *text)
{
	td[0] = 5.0;
	td[1] = 10.0;
	td[2] = 5.0;
	td[3] = zoom;
	p[1] = 0;
	p[2] = text->dim.x;
	p[3] = text->dim.y;
}

void			marble_texture(t_texture *text, double **noise, double zoom)
{
	t_rgb		color;
	int			p[4];
	double		td[8];

	init_td(td, zoom, p, text);
	while (p[1] < text->dim.y)
	{
		p[0] = 0;
		while (p[0] < text->dim.x)
		{
			td[6] = p[0];
			td[7] = p[1];
			td[4] = p[0] * td[0] / p[2] + p[1] * td[1] / p[3] +\
td[2] * turbulence(&(td[6]), noise, td[3], &(p[2])) / 256.0;
			td[5] = 256 * sin(td[4] * 3.14159);
			if (td[5] < 0.0)
				td[5] *= -1.0;
			color = init_rgb_marble(td[5]);
			texture_add_pixel(text, color, p[0], p[1]);
			p[0] += 1;
		}
		p[1] += 1;
	}
}
