/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_construct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 22:15:53 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/19 22:16:01 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgb.h"
#include <stdlib.h>
#include "ft_ori.h"

t_rgb		rgb_construct(int a, int r, int g, int b)
{
	t_rgb	rgb;

	rgb.a = a;
	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}

t_rgb		*rgb_const(int r, int g, int b, int a)
{
	t_rgb	*rgb;

	if (!(rgb = malloc(sizeof(rgb))))
	{
		ft_putstr_fd("rgb_const: error of malloc\n", 2);
		return (0);
	}
	rgb->a = r;
	rgb->r = g;
	rgb->g = b;
	rgb->b = a;
	return (rgb);
}
