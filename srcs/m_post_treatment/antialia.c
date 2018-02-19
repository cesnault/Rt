/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 23:39:44 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/12 23:40:11 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "post_treatment.h"

t_rgb			anti_aliasing(t_texture *text, int x, int y, int atal)
{
	int			xx;
	int			yy;
	t_rgb		rgb;

	yy = y * atal;
	rgb.a = 0;
	rgb.r = 0;
	rgb.b = 0;
	rgb.g = 0;
	while (yy < (y * atal) + atal)
	{
		xx = x * atal;
		while (xx < (x * atal) + atal)
		{
			rgb.r += text->rgb[yy][xx].r;
			rgb.g += text->rgb[yy][xx].g;
			rgb.b += text->rgb[yy][xx].b;
			xx++;
		}
		yy += 1;
	}
	rgb.r /= (atal * atal);
	rgb.g /= (atal * atal);
	rgb.b /= (atal * atal);
	return (rgb);
}

void			applied_antialia(t_texture *ori, t_texture *tmp, int anti_alia)
{
	int			x;
	int			y;

	y = 0;
	while (y < ori->dim.y)
	{
		x = 0;
		while (x < ori->dim.x)
		{
			ori->rgb[y][x] = anti_aliasing(tmp, x, y,
			anti_alia);
			x++;
		}
		y++;
	}
}
