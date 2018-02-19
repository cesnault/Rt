/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:33:08 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/18 23:33:28 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <unistd.h>
#include "bmp.h"

static void	display_hexa(unsigned char *str, int size, int base)
{
	int		c;

	c = 0;
	while (c < size)
	{
		ft_putstr(ft_itoa_base(str[c], base));
		ft_putchar('\t');
		c++;
	}
}

void		bmp_read_header(t_header_bmp bmp)
{
	ft_putstr("\n\t\t ---===== HEADER BMP IMG ====---\n");
	ft_putstr("0x0000: magik number : ");
	write(1, bmp.m_number, 2);
	ft_putstr("\n0x0002: size file in octet : ");
	display_hexa((unsigned char *)(bmp.size_o), 4, 10);
	ft_putstr("\n0x0006: id api : ");
	display_hexa((unsigned char *)(bmp.id_app), 2, 10);
	ft_putstr("\n0x0008: id api : ");
	display_hexa((unsigned char *)(bmp.id_app2), 2, 10);
	ft_putstr("\n0x000A: offset begin : ");
	display_hexa((unsigned char *)(bmp.offset_start), 4, 10);
}

void		bmp_read_info_header(t_bmp_info_head bmp)
{
	ft_putstr("\n\n\t\t ---===== HEADER BMP IMG ====---");
	ft_putstr("\n0x000E: size header : ");
	display_hexa((unsigned char *)(bmp.bi_size), 4, 10);
	ft_putstr("\n0x0012: width picture : ");
	display_hexa((unsigned char *)(bmp.bi_width), 4, 10);
	ft_putstr("\n0x0016: height picture : ");
	display_hexa((unsigned char *)(bmp.bi_height), 4, 10);
	ft_putstr("\n0x001A: number plan : ");
	display_hexa((unsigned char *)(bmp.bi_planes), 2, 10);
	ft_putstr("\n0x001C: bit per pixel : ");
	display_hexa((unsigned char *)(bmp.bi_bit_count), 2, 10);
	ft_putstr("\n0x001E: type of compress : ");
	display_hexa((unsigned char *)(bmp.bi_compress), 4, 10);
	ft_putstr("\n0x0022: size picture octet : ");
	display_hexa((unsigned char *)(bmp.bi_size_img), 4, 10);
	ft_putstr("\n0x0026: res hori pixel per meter : ");
	display_hexa((unsigned char *)(bmp.bi_xpixel_meter), 4, 10);
	ft_putstr("\n0x002A: res verti pixel per meter : ");
	display_hexa((unsigned char *)(bmp.bi_ypixel_meter), 4, 10);
	ft_putstr("\n0x002E: number of color : ");
	display_hexa((unsigned char *)(bmp.bi_color_use), 4, 10);
	ft_putstr("\n0x0032: number important color : ");
	display_hexa((unsigned char *)(bmp.bi_color_import), 4, 10);
}
