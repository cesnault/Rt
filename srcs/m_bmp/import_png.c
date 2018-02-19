/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_png.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 14:22:52 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/15 14:29:50 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "ft_ori.h"
#include "rt.h"
#include "../../lib/lodepng/lodepng.h"
#include "texture.h"

int					png_file_verif(char *str)
{
	unsigned char	*picture;
	unsigned		d_x;
	unsigned		d_y;

	if (lodepng_decode32_file(&picture, &d_x, &d_y, str))
		return (1);
	free(picture);
	return (0);
}

t_texture			*import_png(char *name)
{
	t_texture		*text;
	unsigned		d_x;
	unsigned		d_y;
	t_point			p;
	unsigned char	*picture;

	lodepng_decode32_file(&picture, &d_x, &d_y, name);
	if (d_x == 0 || d_y == 0)
		return (NULL);
	text = texture_init(name, d_x, d_y);
	p.y = 0;
	while (p.y < (int)d_y)
	{
		p.x = 0;
		while (p.x++ < (int)d_x)
		{
			text->rgb[p.y][p.x].r = picture[4 * p.y * d_x + 4 * p.x + 0];
			text->rgb[p.y][p.x].g = picture[4 * p.y * d_x + 4 * p.x + 1];
			text->rgb[p.y][p.x].b = picture[4 * p.y * d_x + 4 * p.x + 2];
			text->rgb[p.y][p.x].a = 0;
		}
		p.y += 1;
	}
	free(picture);
	return (text);
}
