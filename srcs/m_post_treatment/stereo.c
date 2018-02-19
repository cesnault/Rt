/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stereo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 16:01:49 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/15 16:01:58 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "post_treatment.h"

void		stereo(t_texture *text)
{
	int		x;
	int		y;
	t_rgb	tmp;

	x = 0;
	y = 0;
	while (y < text->dim.y)
	{
		while (x < text->dim.x)
		{
			tmp = text->rgb[y][x];
			tmp.r = 0;
			if (x < text->dim.x - 10)
				tmp.r = text->rgb[y][x + 10].r;
			text->rgb[y][x] = tmp;
			x++;
		}
		y++;
		x = 0;
	}
}
