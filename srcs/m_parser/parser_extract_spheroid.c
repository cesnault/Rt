/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_spheroid.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 22:12:44 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/02 22:13:12 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_ori.h"
#include "type.h"
#include <unistd.h>

static void		core_parser_spheroid(t_obj *t, char *str,\
int type, int fd)
{
	if (type == NAME && !(t->name))
		t->name = parser_extract_string("name", str);
	else if (type == P1)
		t->p1 = parser_extract_vector("p1", str);
	else if (type == LIGHT_COLOR)
		t->color_light = parser_extract_vector_float("light color", str);
	else if (type == ROT && !(t->rot))
		t->rot = parser_extract_vector("rot", str);
	else if (type == TEXTURE)
		t->texture = parser_extract_texture(fd, str);
	else if (type == POS)
		t->origin = parser_extract_vector("pos", str);
}

t_obj			*parser_extract_spheroid(int fd)
{
	char		*str;
	int			ret;
	int			type;
	t_obj		*obj;

	type = 1;
	str = 0;
	if (!(parser_extract_verif(fd)))
		return (0);
	if (!(obj = obj_init()))
		return (0);
	while (type != END && (ret = get_next_line(fd, &str)) > 0)
	{
		type = field_type(str);
		core_parser_spheroid(obj, str, type, fd);
		if (str)
			ft_strdel(&str);
	}
	return (obj);
}
