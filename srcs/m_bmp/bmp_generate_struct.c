/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_generate_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:49:56 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/18 23:50:44 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"
#include "texture.h"

t_header_bmp		header_bmp_create(t_texture *text)
{
	t_header_bmp	bmp;

	bmp.m_number[0] = 'B';
	bmp.m_number[1] = 'M';
	head_bmp_add_size(text, &bmp);
	bmp.id_app[0] = 0;
	bmp.id_app[1] = 0;
	bmp.id_app2[0] = 0;
	bmp.id_app2[1] = 0;
	bmp.offset_start[0] = 54;
	bmp.offset_start[1] = 0;
	bmp.offset_start[2] = 0;
	bmp.offset_start[3] = 0;
	return (bmp);
}

static void			bmp_inf2(t_texture *text, t_bmp_info_head *bmp)
{
	bmp->bi_planes[0] = 1;
	bmp->bi_planes[1] = 0;
	bmp->bi_bit_count[0] = 24;
	bmp->bi_bit_count[1] = 0;
	bmp->bi_compress[0] = 0;
	bmp->bi_compress[1] = 0;
	bmp->bi_compress[2] = 0;
	bmp->bi_compress[3] = 0;
	info_bmp_add_size(text, bmp);
	bmp->bi_xpixel_meter[0] = 18;
	bmp->bi_xpixel_meter[1] = 11;
	bmp->bi_xpixel_meter[2] = 0;
	bmp->bi_xpixel_meter[3] = 0;
	bmp->bi_ypixel_meter[0] = 18;
	bmp->bi_ypixel_meter[1] = 11;
	bmp->bi_ypixel_meter[2] = 0;
	bmp->bi_ypixel_meter[3] = 0;
	bmp->bi_color_use[0] = 0;
	bmp->bi_color_use[1] = 0;
	bmp->bi_color_use[2] = 0;
	bmp->bi_color_use[3] = 0;
	bmp->bi_color_import[0] = 0;
	bmp->bi_color_import[1] = 0;
	bmp->bi_color_import[2] = 0;
	bmp->bi_color_import[3] = 0;
}

void				bmp_info_head_create_basic(t_texture *text,\
t_bmp_info_head *bmp)
{
	bmp->bi_size[0] = 40;
	bmp->bi_size[1] = 0;
	bmp->bi_size[2] = 0;
	bmp->bi_size[3] = 0;
	bmp->bi_width[0] = text->dim.x & 255;
	bmp->bi_width[1] = (text->dim.x >> 8) & 255;
	bmp->bi_width[2] = (text->dim.x >> 16) & 255;
	bmp->bi_width[3] = (text->dim.x >> 24) & 255;
	bmp->bi_height[0] = text->dim.y & 255;
	bmp->bi_height[1] = (text->dim.y >> 8) & 255;
	bmp->bi_height[2] = (text->dim.y >> 16) & 255;
	bmp->bi_height[3] = (text->dim.y >> 24) & 255;
	bmp_inf2(text, bmp);
}

t_bmp_info_head		bmp_info_head_create(t_texture *text)
{
	t_bmp_info_head	bmp;

	bmp_info_head_create_basic(text, &bmp);
	return (bmp);
}
