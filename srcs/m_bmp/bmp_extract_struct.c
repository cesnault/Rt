/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_extract_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:37:02 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/18 23:37:28 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"
#include "ft_ori.h"
#include <fcntl.h>
#include <unistd.h>

t_bmp_info_head		bmp_extract_bmp_info_header(int fd)
{
	t_bmp_info_head	inf;

	read(fd, inf.bi_size, 4);
	read(fd, inf.bi_width, 4);
	read(fd, inf.bi_height, 4);
	read(fd, inf.bi_planes, 2);
	read(fd, inf.bi_bit_count, 2);
	read(fd, inf.bi_compress, 4);
	read(fd, inf.bi_size_img, 4);
	read(fd, inf.bi_xpixel_meter, 4);
	read(fd, inf.bi_ypixel_meter, 4);
	read(fd, inf.bi_color_use, 4);
	read(fd, inf.bi_color_import, 4);
	return (inf);
}

t_header_bmp		bmp_extract_header(int fd)
{
	t_header_bmp	head;

	read(fd, head.m_number, 2);
	read(fd, head.size_o, 4);
	read(fd, head.id_app, 2);
	read(fd, head.id_app2, 2);
	read(fd, head.offset_start, 4);
	return (head);
}
