/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_get_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 00:01:11 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/06 00:01:13 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

t_rgb	*texture_get_pixel(t_texture *text, int x, int y)
{
	if (!text || x >= text->dim.x || y >= text->dim.y)
		return (0);
	return (&(text->rgb[y][x]));
}
