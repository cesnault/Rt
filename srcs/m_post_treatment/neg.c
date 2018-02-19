/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 20:34:51 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/15 16:07:53 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "post_treatment.h"

static t_rgb	negative(t_rgb v)
{
	t_rgb		n;
	float		opacite;

	opacite = 0.6;
	n.r = 255 - v.r;
	n.g = 255 - v.g;
	n.b = 255 - v.b;
	return (n);
}

void			applied_negative(t_texture *text)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (y < text->dim.y)
	{
		while (x < text->dim.x)
		{
			text->rgb[y][x] = negative(text->rgb[y][x]);
			x++;
		}
		y++;
		x = 0;
	}
}
