/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:22:07 by jegloff           #+#    #+#             */
/*   Updated: 2017/04/27 22:19:01 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgb.h"

t_rgb		rgb_mult(t_rgb rgb, float factor)
{
	t_rgb	r;

	r.a = (int)((float)rgb.a * factor);
	r.r = (int)((float)rgb.r * factor);
	r.g = (int)((float)rgb.g * factor);
	r.b = (int)((float)rgb.b * factor);
	return (r);
}

void		p_rgb_mult(t_rgb *rgb, float factor)
{
	rgb->a *= factor;
	rgb->r *= factor;
	rgb->g *= factor;
	rgb->b *= factor;
}
