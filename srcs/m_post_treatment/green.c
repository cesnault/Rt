/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   green.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 20:34:51 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/15 16:08:52 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "post_treatment.h"

static t_rgb	green(t_rgb v)
{
	t_rgb		n;
	float		opacite;

	opacite = 1.0 - 0.6;
	n.r = v.r * (opacite);
	n.g = v.g * (opacite) + 255 * (1.0 - opacite);
	n.b = v.b * (opacite);
	return (n);
}

void			applied_green(t_texture *text)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (y < text->dim.y)
	{
		while (x < text->dim.x)
		{
			text->rgb[y][x] = green(text->rgb[y][x]);
			x++;
		}
		y++;
		x = 0;
	}
}
