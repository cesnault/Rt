/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_damier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 23:51:41 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/19 00:00:13 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgb.h"
#include "vector.h"
#include "parser.h"

t_rgb		rgb_damier2d(t_vect3d *vec)
{
	int		x;
	int		y;
	int		z;
	t_rgb	a[2];
	int		ret;

	a[1].r = 50;
	a[0].r = 100;
	a[1].g = 100;
	a[0].g = 50;
	a[1].b = 100;
	a[0].b = 100;
	x = (int)(vec->x) * 255;
	y = (int)(vec->y) * 255;
	z = (int)(vec->z) * 255;
	ret = (2 + x / 2) + (2 + y / 2);
	ret = ret % 2;
	if (ret)
		return (a[0]);
	return (a[1]);
}

t_rgb		rgb_damier3d(t_vect3d *vec)
{
	t_rgb	a[2];
	int		ret;
	int		nb_neg;
	int		incr;

	incr = 0;
	nb_neg = 0;
	a[1].r = 50;
	a[0].r = 100;
	a[1].g = 100;
	a[0].g = 50;
	a[1].b = 100;
	a[0].b = 100;
	ret = (int)(incr + vec->x / 2.0) +\
	(int)(incr + vec->y / 2.0) + (int)(incr + vec->z / 2.0);
	ret = ret % 2;
	if (vec->x < 0.0)
		ret++;
	if (vec->y < 0.0)
		ret++;
	ret = ret % 2;
	if (ret)
		return (a[0]);
	return (a[1]);
}
