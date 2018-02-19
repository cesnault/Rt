/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:35:56 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/18 23:36:27 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"
#include "ft_ori.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

t_texture				*generate_texture_bmp(int fd, int width, int height)
{
	t_texture			*text;
	int					x;
	int					y;
	unsigned char		t[3];
	t_rgb				rgb;

	x = 0;
	y = 0;
	rgb.a = 0;
	text = texture_init("MA", width, height);
	while (y < height)
	{
		while (x < width)
		{
			read(fd, t, 3);
			rgb.b = t[0];
			rgb.g = t[1];
			rgb.r = t[2];
			texture_add_pixel(text, rgb, x, height - y - 1);
			x++;
		}
		x = 0;
		y++;
	}
	return (text);
}

t_texture				*import_bmp(char *name)
{
	t_texture			*text;
	int					fd;
	t_point				dim;
	t_header_bmp		head;
	t_bmp_info_head		header_img;

	if ((fd = open(name, O_RDONLY)) < 0)
	{
		ft_putstr_fd("import_bmp: file inexistant.\n", 2);
		return (0);
	}
	head = bmp_extract_header(fd);
	header_img = bmp_extract_bmp_info_header(fd);
	bmp_read_header(head);
	bmp_read_info_header(header_img);
	dim.x = octet_to_int((unsigned char *)header_img.bi_width, 4);
	dim.y = octet_to_int((unsigned char *)header_img.bi_height, 4);
	text = generate_texture_bmp(fd, dim.x, dim.y);
	close(fd);
	return (text);
}
