/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_rgb_construct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:59:23 by jegloff           #+#    #+#             */
/*   Updated: 2017/04/12 17:59:24 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgb.h"

void		p_rgb_construct(t_rgb *rgb, int r, int g, int b)
{
	rgb->a = r;
	rgb->r = g;
	rgb->g = b;
	rgb->b = 0;
}
