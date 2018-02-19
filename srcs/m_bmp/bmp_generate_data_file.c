/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_generate_data_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:45:28 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/18 23:46:45 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"

void			add_header_bmp(t_header_bmp bm, unsigned char *data, int *count)
{
	data[(*count)++] = bm.m_number[0];
	data[(*count)++] = bm.m_number[1];
	data[(*count)++] = bm.size_o[0];
	data[(*count)++] = bm.size_o[1];
	data[(*count)++] = bm.size_o[2];
	data[(*count)++] = bm.size_o[3];
	data[(*count)++] = bm.id_app[0];
	data[(*count)++] = bm.id_app[1];
	data[(*count)++] = bm.id_app2[0];
	data[(*count)++] = bm.id_app2[1];
	data[(*count)++] = bm.offset_start[0];
	data[(*count)++] = bm.offset_start[1];
	data[(*count)++] = bm.offset_start[2];
	data[(*count)++] = bm.offset_start[3];
}

static void		add_inf_bmp_moore(t_bmp_info_head inf,\
		unsigned char *data, int *count)
{
	data[(*count)++] = inf.bi_compress[0];
	data[(*count)++] = inf.bi_compress[1];
	data[(*count)++] = inf.bi_compress[2];
	data[(*count)++] = inf.bi_compress[3];
	data[(*count)++] = inf.bi_size_img[0];
	data[(*count)++] = inf.bi_xpixel_meter[0];
	data[(*count)++] = inf.bi_xpixel_meter[1];
	data[(*count)++] = inf.bi_xpixel_meter[2];
	data[(*count)++] = inf.bi_xpixel_meter[3];
	data[(*count)++] = inf.bi_ypixel_meter[0];
	data[(*count)++] = inf.bi_ypixel_meter[1];
	data[(*count)++] = inf.bi_ypixel_meter[2];
	data[(*count)++] = inf.bi_ypixel_meter[3];
	data[(*count)++] = inf.bi_color_use[0];
	data[(*count)++] = inf.bi_color_use[1];
	data[(*count)++] = inf.bi_color_use[2];
	data[(*count)++] = inf.bi_color_use[3];
	data[(*count)++] = inf.bi_color_import[0];
	data[(*count)++] = inf.bi_color_import[1];
	data[(*count)++] = inf.bi_color_import[2];
	data[(*count)++] = inf.bi_color_import[3];
}

void			add_info_bmp(t_bmp_info_head inf,\
		unsigned char *data, int *count)
{
	data[(*count)++] = inf.bi_size[0];
	data[(*count)++] = inf.bi_size[1];
	data[(*count)++] = inf.bi_size[2];
	data[(*count)++] = inf.bi_size[3];
	data[(*count)++] = inf.bi_width[0];
	data[(*count)++] = inf.bi_width[1];
	data[(*count)++] = inf.bi_width[2];
	data[(*count)++] = inf.bi_width[3];
	data[(*count)++] = inf.bi_height[0];
	data[(*count)++] = inf.bi_height[1];
	data[(*count)++] = inf.bi_height[2];
	data[(*count)++] = inf.bi_height[3];
	data[(*count)++] = inf.bi_planes[0];
	data[(*count)++] = inf.bi_planes[1];
	data[(*count)++] = inf.bi_bit_count[0];
	data[(*count)++] = inf.bi_bit_count[1];
	add_inf_bmp_moore(inf, data, count);
}

void			add_picture(t_texture *text, unsigned char *data, int *count)
{
	int			x;
	int			y;

	x = 0;
	y = text->dim.y - 1;
	while (y >= 0)
	{
		while (x < text->dim.x)
		{
			data[(*count)++] = (unsigned int)text->rgb[y][x].b;
			data[(*count)++] = (unsigned int)text->rgb[y][x].g;
			data[(*count)++] = (unsigned int)text->rgb[y][x].r;
			x++;
		}
		y--;
		x = 0;
	}
	data[(*count)] = 0;
}
