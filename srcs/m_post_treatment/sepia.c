/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sepia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 23:40:23 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/12 23:40:40 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "post_treatment.h"

t_rgb		sepia(t_rgb v)
{
	t_rgb	n;

	n.r = (v.r * 0.393) + (v.g * 0.769) + (v.b * 0.189);
	n.g = (v.r * 0.349) + (v.g * 0.686) + (v.b * 0.168);
	n.b = (v.r * 0.272) + (v.g * 0.534) + (v.b * 0.131);
	if (n.r > 255)
		n.r = 255;
	if (n.g > 255)
		n.g = 255;
	if (n.b > 255)
		n.b = 255;
	return (n);
}

void		applied_sepia(t_texture *text)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < text->dim.y)
	{
		while (x < text->dim.x)
		{
			text->rgb[y][x] = sepia(text->rgb[y][x]);
			x++;
		}
		y++;
		x = 0;
	}
}
