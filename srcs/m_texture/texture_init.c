/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 00:01:19 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/06 00:01:20 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include <stdlib.h>
#include "ft_ori.h"

static void	init_tab_rgb(t_texture *text)
{
	int y;

	y = 0;
	if (!(text->rgb = malloc(sizeof(t_rgb *) * text->dim.y)))
		malloc_fail("init_tab_rgb");
	while (y < text->dim.y)
	{
		if (!(text->rgb[y] = malloc(sizeof(t_rgb) * text->dim.x)))
			malloc_fail("init_tab_rgb");
		y++;
	}
}

static void	init_value_rgb(t_texture *text)
{
	int x;
	int y;

	y = 0;
	while (y < text->dim.y)
	{
		x = 0;
		while (x < text->dim.x)
		{
			text->rgb[y][x].r = 0;
			text->rgb[y][x].g = 0;
			text->rgb[y][x].b = 0;
			x++;
		}
		y++;
	}
}

t_texture	*texture_init(char *name, int width, int height)
{
	t_texture *text;

	if (!(text = malloc(sizeof(t_texture))))
		malloc_fail("texture_init");
	text->dim.x = width;
	text->dim.y = height;
	if (!(text->name = ft_strdup(name)))
		malloc_fail("texture_init");
	init_tab_rgb(text);
	init_value_rgb(text);
	return (text);
}
