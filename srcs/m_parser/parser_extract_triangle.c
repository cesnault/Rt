/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_triangle.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 17:02:12 by cesnault          #+#    #+#             */
/*   Updated: 2017/05/28 22:37:27 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_ori.h"
#include "type.h"
#include <unistd.h>

static void		core_parser_extract_triangle(t_obj *t, char *str,\
int type, int fd)
{
	if (type == NAME && !(t->name))
		t->name = parser_extract_string("name", str);
	else if (type == P1)
		t->p1 = parser_extract_vector("p1", str);
	else if (type == P2)
		t->p2 = parser_extract_vector("p2", str);
	else if (type == P3)
		t->p3 = parser_extract_vector("p3", str);
	else if (type == LIGHT_COLOR)
		t->color_light = parser_extract_vector_float("light color", str);
	else if (type == ROT && !(t->rot))
		t->rot = parser_extract_vector("rot", str);
	else if (type == TEXTURE)
		t->texture = parser_extract_texture(fd, str);
}

t_obj			*parser_extract_triangle(int fd)
{
	t_obj		*t;
	char		*str;
	int			type;
	int			ret;

	type = 1;
	if (!(parser_extract_verif(fd)))
		return (0);
	if (!(t = obj_init()))
		return (0);
	while (type != END && (ret = get_next_line(fd, &str)) > 0)
	{
		type = field_type(str);
		core_parser_extract_triangle(t, str, type, fd);
		if (str)
			ft_strdel(&str);
	}
	return (t);
}
