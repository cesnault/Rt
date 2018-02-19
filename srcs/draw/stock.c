/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:52:54 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/02 19:53:02 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "../../minilibx_macos/mlx.h"
#include "parser.h"
#include "texture.h"

void	stock(t_rt *glb, int x, int y)
{
	t_rgb rgb;

	if (glb->col.r > 1)
		glb->col.r = 1;
	if (glb->col.g > 1)
		glb->col.g = 1;
	if (glb->col.b > 1)
		glb->col.b = 1;
	rgb.r = 255 * glb->col.r;
	rgb.g = 255 * glb->col.g;
	rgb.b = 255 * glb->col.b;
	rgb.a = 0;
	texture_add_pixel(glb->text, rgb, x, y);
}

void	stock_texture(t_rt *glb, int x, int y, t_texture *text)
{
	t_rgb rgb;

	if (glb->col.r > 1)
		glb->col.r = 1;
	if (glb->col.g > 1)
		glb->col.g = 1;
	if (glb->col.b > 1)
		glb->col.b = 1;
	rgb.r = 255 * glb->col.r;
	rgb.g = 255 * glb->col.g;
	rgb.b = 255 * glb->col.b;
	rgb.a = 0;
	texture_add_pixel(text, rgb, x, y);
}
