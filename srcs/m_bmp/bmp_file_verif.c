/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_file_verif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:41:17 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/18 23:42:17 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"
#include "ft_ori.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static int				bmp_magik_number(unsigned char data[2])
{
	if (data[0] == 'B' && data[1] == 'M')
		return (1);
	else if (data[0] == 'B' && data[1] == 'A')
		return (1);
	else if (data[0] == 'C' && data[1] == 'I')
		return (1);
	else if (data[0] == 'C' && data[1] == 'P')
		return (1);
	else if (data[0] == 'I' && data[1] == 'C')
		return (1);
	else if (data[0] == 'P' && data[1] == 'T')
		return (1);
	return (0);
}

static int				bmp_other_test(t_header_bmp head, t_bmp_info_head inf)
{
	if (octet_to_int(inf.bi_size, 4) != 40)
	{
		ft_putstr_fd("bmp_check_format: error biSize\n", 2);
		return (0);
	}
	if (octet_to_int(head.offset_start, 4) != 54)
	{
		ft_putstr_fd("bmp_check_format: error bfOffBits\n", 2);
		return (0);
	}
	if (octet_to_int(inf.bi_width, 4) * octet_to_int(inf.bi_height, 4) * 3 !=\
	octet_to_int(inf.bi_size_img, 4))
	{
		ft_putstr_fd("bmp_check_format: error bi_size_img\n", 2);
		return (0);
	}
	if (octet_to_int(inf.bi_color_use, 4) ||\
octet_to_int(inf.bi_color_import, 4) || octet_to_int(inf.bi_compress, 4) ||\
octet_to_int(inf.bi_planes, 2) != 1 || octet_to_int(inf.bi_bit_count, 2) != 24)
	{
		ft_putstr_fd("bmp_check_format : error\n", 2);
		return (0);
	}
	return (1);
}

static int				bmp_check_format(char *name)
{
	int					size;
	t_header_bmp		head;
	t_bmp_info_head		header_img;
	int					fd;

	if ((size = ft_file_size(name)) < 55)
		return (0);
	if ((fd = open(name, O_RDONLY)) < 0)
		return (0);
	head = bmp_extract_header(fd);
	header_img = bmp_extract_bmp_info_header(fd);
	close(fd);
	if (octet_to_int(head.size_o, 4) != size)
	{
		ft_putstr_fd("bmp_check_format: error size\n", 2);
		return (0);
	}
	if (!bmp_magik_number(head.m_number))
	{
		ft_putstr_fd("bmp_check_format: error magik number\n", 2);
		return (0);
	}
	if (!bmp_other_test(head, header_img))
		return (0);
	return (1);
}

int						bmp_file_verif(char *name)
{
	if (!name)
	{
		ft_putstr_fd("Error name don't exist.\n", 2);
		return (0);
	}
	if (!(ft_file_exist(name)))
	{
		ft_putstr_fd("File don't exist.\n", 2);
		return (0);
	}
	if (!check_extand(name, ".bmp"))
	{
		ft_putstr_fd("Error extend BMP.\n", 2);
		return (0);
	}
	if (!bmp_check_format(name))
	{
		ft_putstr_fd("Error format BMP.\n", 2);
		return (0);
	}
	return (1);
}
