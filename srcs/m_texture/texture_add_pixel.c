/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_add_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 00:01:27 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/06 00:01:48 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

void	texture_add_pixel(t_texture *text, t_rgb rgb, int x, int y)
{
	if (!text || x >= text->dim.x || y >= text->dim.y)
		return ;
	text->rgb[y][x].r = rgb.r;
	text->rgb[y][x].g = rgb.g;
	text->rgb[y][x].b = rgb.b;
	text->rgb[y][x].a = rgb.a;
}
