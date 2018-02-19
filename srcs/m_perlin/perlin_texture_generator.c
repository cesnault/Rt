/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_texture_generator.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 23:55:45 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/09 17:06:08 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "perlin.h"
#include <stdlib.h>

t_texture		*perlin_texture_generator(t_point dim, int type,\
char *name, int zoom)
{
	double		**tab_alea;
	t_texture	*text;

	tab_alea = generate_double_alea(dim.y, dim.x);
	text = texture_init(name, dim.x, dim.y);
	if (type == SMOOTH)
		smooth_texture(text, tab_alea, zoom);
	else if (type == MARBLE)
		marble_texture(text, tab_alea, zoom);
	else
		wood_texture(text, tab_alea, zoom);
	free_tab2d(&tab_alea, dim.y);
	return (text);
}
