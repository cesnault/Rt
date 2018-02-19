/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:35:05 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/18 23:35:39 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"

unsigned int		get_size_bmp(t_texture *text)
{
	unsigned int	size;

	size = text->dim.x * text->dim.y * 3 + 54;
	return (size);
}

int					octet_to_int(unsigned char *str, int size)
{
	int				c;
	int				v;
	int				nb_decal;

	c = 0;
	v = 0;
	nb_decal = 0;
	while (c < size)
	{
		v += ((int)(str[c])) << nb_decal;
		nb_decal += 8;
		c++;
	}
	return (v);
}

void				head_bmp_add_size(t_texture *text, t_header_bmp *head)
{
	unsigned int	value;

	value = get_size_bmp(text);
	head->size_o[0] = value & 255;
	head->size_o[1] = (value >> 8) & 255;
	head->size_o[2] = (value >> 16) & 255;
	head->size_o[3] = (value >> 24) & 255;
}

void				info_bmp_add_size(t_texture *text, t_bmp_info_head *inf)
{
	unsigned int	value;

	value = get_size_bmp(text) - 54;
	inf->bi_size_img[0] = value & 255;
	inf->bi_size_img[1] = (value >> 8) & 255;
	inf->bi_size_img[2] = (value >> 16) & 255;
	inf->bi_size_img[3] = (value >> 24) & 255;
}
