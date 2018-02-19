/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:34:07 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/18 23:34:45 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include "bmp.h"
#include <stdlib.h>

static unsigned char	*generate_img(t_texture *text, t_header_bmp bm,\
t_bmp_info_head inf)
{
	unsigned char		*data;
	int					c;

	c = 0;
	if (!(data = malloc(sizeof(unsigned char) * (get_size_bmp(text) + 1))))
		malloc_fail("generate_img");
	add_header_bmp(bm, data, &c);
	add_info_bmp(inf, data, &c);
	add_picture(text, data, &c);
	return (data);
}

int						export_bmp(t_texture *text, char *name)
{
	unsigned int		value;
	t_header_bmp		bmp;
	t_bmp_info_head		head;
	unsigned char		*data;

	value = get_size_bmp(text);
	bmp = header_bmp_create(text);
	head = bmp_info_head_create(text);
	file_create(name);
	data = generate_img(text, bmp, head);
	file_concat_size_end(name, data, value);
	if (!data)
		free(data);
	return (0);
}
