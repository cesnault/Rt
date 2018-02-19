/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yellow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 20:34:51 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/15 16:05:22 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "post_treatment.h"
#include "type.h"
#include "rgb.h"

static t_rgb	yellow(t_rgb v)
{
	t_rgb		n;
	float		opacite;

	opacite = 0.6;
	n.r = v.r * (1 - opacite) + 255 * opacite;
	n.g = v.g * (1 - opacite) + 255 * opacite;
	n.b = v.b * (1 - opacite) + 0 * opacite;
	return (n);
}

void			applied_yellow(t_texture *text)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (y < text->dim.y)
	{
		while (x < text->dim.x)
		{
			text->rgb[y][x] = yellow(text->rgb[y][x]);
			x++;
		}
		y++;
		x = 0;
	}
}
